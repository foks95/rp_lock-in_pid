# Instalacja Lock-in+PID na SIGNALlab 250-12 (krok po kroku)

Poniżej jest praktyczna instrukcja "od zera" dla Linux/macOS terminal.

## 1) Pobierz repozytorium

```bash
git clone https://github.com/marceluda/rp_lock-in_pid.git
cd rp_lock-in_pid
```

## 2) Przygotuj host do kompilacji

Zainstaluj podstawowe narzędzia:

```bash
sudo apt-get update
sudo apt-get install -y make curl xz-utils u-boot-tools
```

Załaduj zmienne builda projektu:

```bash
source settings.sh
```

> Jeśli `source settings.sh` zwraca błąd związany z toolchainem, doinstaluj toolchain zgodnie z `README.md`.

## 3) Zbuduj aplikację

W katalogu głównym repo:

```bash
make
```

Po poprawnym buildzie powinny istnieć co najmniej:
- `lock_in+pid/controllerhf.so`
- `lock_in+pid/red_pitaya.bit`
- `lock_in+pid/fpga.conf`

Szybka weryfikacja:

```bash
test -f lock_in+pid/controllerhf.so && echo "OK: controllerhf.so"
test -f lock_in+pid/red_pitaya.bit && echo "OK: red_pitaya.bit"
```

## 4) Sprawdź połączenie z Red Pitayą

Przykład dla hosta mDNS:

```bash
ping -c 2 rp-XXXXXX.local
```

lub po IP:

```bash
ping -c 2 192.168.1.100
```

## 5) Wgraj aplikację na Red Pitayę

Skrypt instalacyjny kopiuje komplet plików do:
`/opt/redpitaya/www/apps/lock_in+pid`

Uruchom:

```bash
cd lock_in+pid
./upload_app.sh rp-XXXXXX.local
```

albo (po IP):

```bash
./upload_app.sh 192.168.1.100
```

Jeśli SSH działa na innym porcie, użyj `-p`:

```bash
./upload_app.sh -p 2222 192.168.1.100
```

## 6) Uruchom aplikację w przeglądarce

Otwórz:

```text
http://rp-XXXXXX.local/lock_in+pid
```

lub:

```text
http://192.168.1.100/lock_in+pid
```

## 7) Szybki test działania po instalacji

1. Wejdź do aplikacji w przeglądarce.
2. Sprawdź, czy wykresy się odświeżają.
3. Zmień częstotliwość generatora i potwierdź zmianę na torze pomiarowym.
4. Zapisz preset i odczytaj go ponownie.

## Najczęstsze problemy

- **`ssh-copy-id` pyta o hasło root**: to normalne przy pierwszym uploadzie.
- **Brak `controllerhf.so` po `make`**: wróć do kroku 2 i sprawdź środowisko (`source settings.sh`).
- **Aplikacja nie otwiera się w przeglądarce**: upewnij się, że pliki są na RP w `/opt/redpitaya/www/apps/lock_in+pid`.
- **Konflikt starej wersji aplikacji**: uruchom upload ponownie — skrypt usuwa i odtwarza katalog aplikacji.
