# Portowanie lock-in do Red Pitaya SIGNALlab 250-12

## Krótka odpowiedź

Tak — **da się przygotować** wersję lock-in pod SIGNALlab 250-12, ale to jest pełny port sprzętowo-programowy (nie tylko zmiana kilku stałych).

Największe ryzyka:
- inna częstotliwość próbkowania ADC/DAC (250 MS/s vs 125 MS/s),
- inna rozdzielczość torów (12-bit vs 14-bit),
- możliwe różnice w mapie rejestrów i top-level HDL dla platformy 250-12,
- inna kalibracja FE/BE i limity dynamiczne.

## Co trzeba zmienić (zakres prac)

### 1) FPGA / HDL (rdzeń lock-in)

1. **Nowy top-level dla 250-12**
   - podmiana/port `red_pitaya_top.v` dla platformy SIGNALlab 250-12,
   - poprawne podłączenie instancji `lock` do torów ADC/DAC i triggerów.

2. **Szerokości bitowe i saturacje**
   - audyt modułów lock-in (`mult_dsp_14`, `sat14`, `lock_pid_block`, `muxer*`, filtry),
   - zamiana miejsc 14-bit zależnych na warianty 12-bit albo parametryzacja (`ADC_BITS`, `DAC_BITS`, `IQ_BITS`),
   - przeliczenie przesunięć bitowych po filtracji (np. fragmenty typu `[27-1:11]`).

3. **Czas i demodulacja**
   - przeliczenie generatora odniesienia (`gen_mod2`) i rampy dla 250 MHz,
   - weryfikacja triggerów (harmonic/square/ramp) po zmianie zegara.

4. **Mapa rejestrów**
   - utrzymanie kompatybilnej mapy lock-in lub świadome przeadresowanie,
   - jeśli adres bazowy lock-in inny niż `0x40600000`, aktualizacja warstwy C.

### 2) Backend C (sterownik aplikacji)

1. **Parametry platformy**
   - aktualizacja stałych próbkowania i przeliczeń czasu/napięcia (moduły `fpga.*`, `worker.*`, `generate.*`),
   - dostosowanie konwersji ADC/DAC count <-> volt dla 12-bit.

2. **Dostęp do rejestrów lock-in**
   - weryfikacja `LOCK_BASE_ADDR`/`LOCK_BASE_SIZE` i struktury `lock_reg_t` w `fpga_lock.h`,
   - ewentualna migracja pól, jeśli HDL dla 250-12 ma inny układ rejestrów.

3. **Kalibracje**
   - wykorzystanie kalibracji kompatybilnej z 250-12 (FS, offset, gain),
   - walidacja ograniczeń min/max dla parametrów GUI lock-in.

### 3) Frontend/UI

1. Sprawdzenie zakresów i opisów jednostek dla 12-bit.
2. Korekta domyślnych presetów (PID/rampa/LPF), żeby start był stabilny na 250-12.

### 4) Testy i walidacja

1. Testy funkcjonalne lock-in:
   - poprawność X/Y/F1/F2/F3,
   - stabilność fazy i amplitudy,
   - zachowanie po zmianie częstotliwości i harmonicznych.
2. Testy pętli:
   - lock acquire time,
   - relock po zakłóceniu,
   - praca PID A/B i ograniczeń saturacji.
3. Testy integracyjne:
   - scope + lock + DAC,
   - trigger routing,
   - zgodność odczytów rejestrów z GUI.

## Minimalny plan realizacji (praktyczny)

### Etap A — „bring-up” (1)
- skompilować bitstream dla 250-12 z instancją `lock`,
- potwierdzić odczyt/zapis podstawowych rejestrów lock-in z poziomu C.

### Etap B — „DSP correctness” (2)
- uruchomić demodulację (X/Y) i zweryfikować amplitudę/fazę sygnałem testowym,
- skorygować skalowanie i filtry po przejściu na 12-bit/250 MHz.

### Etap C — „control loops” (3)
- dostroić PID/ramp/relock,
- przygotować bezpieczne presety startowe.

### Etap D — „app polish” (4)
- aktualizacja GUI, opisów i presetów,
- testy końcowe oraz paczka aplikacji dla SIGNALlab 250-12.

## Co mogę zrobić od razu w kolejnym kroku

Mogę przygotować **pierwszy techniczny PR portujący warstwę C pod profil 250-12** (bez ruszania algorytmu lock-in):
- wprowadzić profil sprzętowy (125-14 / 250-12),
- przenieść stałe próbkowania i bit-depth do wspólnej konfiguracji,
- dodać miejsca „adapterowe” dla mapy rejestrów lock-in,
- zostawić domyślnie kompatybilność z obecnym 125-14.

To będzie najbezpieczniejszy punkt startu przed modyfikacją HDL.
