# PWR RACING TEAM ![](https://racing-pwr.pl/_next/image?url=%2F_next%2Fstatic%2Fmedia%2Flogo.a822dc58.png&w=1200&q=75)
Zadania rekrutacyjne do działu software.

## Zadanie 2.1

Użyłem do tego problemu algorytmu Graham Scan


## Zadanie 2.2
Program znajduje **najbliższe dwie równoległe proste**, takie że wszystkie punkty ze zbioru znajdują się na nich lub pomiędzy nimi.

```
   ───────────────────────  ← prosta 1
        ·     ·
   ·         ·     ·
        ·          ·
    ·         ·
             ·
   ───────────────────────  ← prosta 2

Minimalna odległość między prostymi
```

### Opis działania:
- Za pomocą algorytmu **Graham Scan** wyznaczana jest otoczka wypukła punktów.

- Każdą krawędź otoczki traktujemy jako potencjalną bazę prostych.

- Dla każdej krawędzi obliczamy odległość **wszystkich punktów otoczki** od prostej wyznaczonej przez tę krawędź.

- Z otrzymanych wartości wybieramy **maksymalną odległość** dla niej krawędzi.

- Spośród maksymalnych odległości dla wszystkich krawędzi wynieramy **minimalną** — jest to najmniejsza możliwa odległość między dwiema równoległymi prostymi spełniającymi warunki zadania.

### Zastosowane technologie i narzędzia:
- Algorytm **Graham Scan** (otoczka wypukła)

- `std::max_element`, `std::min_element` (wyznaczanie ekstremów)

- Funkcja pomocnicza do obliczania odległości punkt–prosta

## Zadanie 2.3
Program służy do odnalezienia **dwóch punktów znajdujących się najbliżej siebie** w podanym zbiorze punktów.

```
      ·     ·
   ·      ○      ·     ·
       ·   \              ·
  ·         ○    ·
              ·
```
### Opis działania:
W rozwiązaniu zastosowano algorytm **Divide & Conquer (Dziel i Zwyciężaj)**, który ma niską złożoność obliczeniową.

#### Etapy algorytmu:

- Sortowanie punktów względem współrzędnej X.

- Podział zbioru na dwie części (lewa i prawa strona).

- **Rekurencyjne wyznaczenie** najbliższej pary punktów w lewej i prawej części.

- Wybranie **mniejszej z dwóch znalezionych odległości**.

- "utworzenie" **paska (obszaru)** wokół środka o **szerokości** ```2 x min_dystans```.

- Sprawdzenie punktów znajdujących się w pasku — **może tam znajdować się para bliższa niż w podzbiorach**.

### Napotkane problemy i ich rozwiązanie: 

- **Problem:** Optymalne przeszukiwanie punktów w "utworzonym" pasku.

- **Rozwiązanie:** Rozrysowanie sytuacji i analiza geometryczna, aby zrozumieć, które pary należy sprawdzać.

### Zastosowane technologie i narzędzia:
- **Rekurencja** — dzielenie problemu na mniejsze fragmenty
- `std::sort` — sortowanie punktów według współrzędnej X
- **Algorytmy geometryczne** — ograniczenie liczby porównań punktów w pasku