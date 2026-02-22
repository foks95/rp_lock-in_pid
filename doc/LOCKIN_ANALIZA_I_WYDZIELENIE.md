# Lock-in w projekcie `rp_lock-in_pid` — analiza i propozycja wydzielenia

## 1) Gdzie kończy się „scope/AWG/PID”, a zaczyna „lock-in”

W tym repo granica jest już formalnie zdefiniowana przez indeksy parametrów:

- `PARAMS_LOCK_PARAMS = 81` — od tego indeksu parametry są traktowane jako lock-in i trafiają do `lock_update()`.  
- Lock-in parametry mają zakres makr `LOCK_*` od `LOCK_OSCA_SW` do `LOCK_MOD_HARMONIC_ON`.

To jest najważniejszy punkt „wydzielenia logicznego”: wszystkie parametry od 81 w górę to osobny subsystem lock-in.

## 2) Przepływ danych lock-in (end-to-end)

1. Frontend (`index.html`) trzyma lock-in parametry w tym samym obiekcie `params.local` i wysyła je przez `POST /data`.
2. Backend (`rp_set_params` w `main.c`) rozpoznaje, które parametry się zmieniły.
3. Jeśli zmiana dotyczy zakresu lock-in (`p_idx >= PARAMS_LOCK_PARAMS`), ustawiana jest flaga `lock_params_change`.
4. Na końcu `rp_set_params` wywoływane jest `lock_update(&rp_main_params[0])`.
5. `lock_update()` mapuje parametry 1:1 do rejestrów FPGA (`g_lock_reg->...`).
6. Przy odczycie sygnałów `rp_get_signals()` dodatkowo wywołuje `lock_update_main(...)`, żeby odświeżyć z FPGA parametry read-only lock-in.

W praktyce lock-in jest więc „modułem rejestrów FPGA” sterowanym przez wspólną tablicę parametrów.

## 3) Pliki należące do lock-in (wydzielony rdzeń)

Minimalny „rdzeń lock-in” to:

- `lock_in+pid/src/lock.c` — logika zapisu/odczytu parametrów lock-in,
- `lock_in+pid/src/lock.h` — interfejs modułu,
- `lock_in+pid/src/fpga_lock.c` — mapowanie FPGA lock-in przez `/dev/mem`,
- `lock_in+pid/src/fpga_lock.h` — opis rejestrów i API mapowania.

Plik `main.c` jest tylko orchestracją i routingiem parametrów, ale nie zawiera właściwej matematyki lock-in (ta jest po stronie FPGA).

## 4) Co już jest „wydzielone”, a co jeszcze nie

### Już wydzielone

- osobne API modułu: `lock_init`, `lock_exit`, `lock_update`, `lock_update_main`,
- osobna warstwa dostępu do rejestrów FPGA (`fpga_lock.*`),
- osobna gałąź aktualizacji w `rp_set_params`.

### Niewydzielone

- definicje lock-in parametrów (`rp_main_params[]`) siedzą nadal w ogromnej tablicy `main.c`,
- indeksy/makra `LOCK_*` siedzą w `main.h` razem z resztą aplikacji,
- frontend lock-in jest zmieszany z całym UI w jednym `index.html`.

## 5) Proponowane wydzielenie praktyczne (bez zmiany działania)

Najmniejszy, bezpieczny plan na wydzielenie lock-in do osobnej „warstwy domenowej”:

1. **Krok A — kontrakt lock-in**  
   Dodać `src/lock_params.h` i przenieść tam:
   - makra `LOCK_*`,
   - `PARAMS_LOCK_PARAMS`,
   - ewentualnie grupy enum dla sekcji lock-in.

2. **Krok B — tabela parametrów lock-in**  
   Przenieść lock-in fragment `rp_main_params[]` z `main.c` do osobnego pliku, np.:
   - `src/lock_params_table.c`
   - funkcja: `int lock_params_apply_defaults(rp_app_params_t *dst)`.

3. **Krok C — adapter w `main.c`**  
   Zostawić w `main.c` tylko:
   - wykrycie `lock_params_change`,
   - wywołanie `lock_update()` / `lock_update_main()`.

4. **Krok D — frontend**  
   Opcjonalnie wydzielić lock-in JS do `js/lock_in_controls.js` i podłączyć w `index.html`.

Efekt: lock-in dalej działa identycznie, ale staje się samodzielnym modułem możliwym do utrzymania/portowania.

## 6) Szybka „granica modułu” do pracy developerskiej

Jeśli chcesz pracować **tylko nad lock-in**, praktycznie wystarczy ograniczyć się do:

- C/FPGA API: `lock.c`, `lock.h`, `fpga_lock.c`, `fpga_lock.h`,
- indeksy i routing: `main.h` (`LOCK_*`, `PARAMS_LOCK_PARAMS`) oraz fragment lock gałęzi w `main.c`,
- UI lock-in: kontrolki i powiązane eventy w `index.html` (lub przyszły `lock_in_controls.js`).

To jest obecna, realna granica subsystemu lock-in w tym projekcie.
