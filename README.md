# PWR RACING TEAM
Zadania rekrutacyjne do działu **software**.

## Zadanie 2.1
Program znajduje ***najmniejszy podzbiór takich punktów***, które
***otaczają wszystkie inne punkty***.

```
      ○   --  ○
    /       .    \  
   /    ·  . .    ○
  ○     .  .  .   / 
    \            /
      ○   ---  ○
```

### Opis działania:
**Algorytm Graham Scan***

- Wyznaczenie punktu o **najmniejszej wartości współrzędnej Y. Jeśli kilka ma tę samą wartość — wybieramy ten o najmniejszym X. **Oznaczamy go jako p0***.

- Sortowanie pozostałych punktów według **kąta względem p0**.

- Wstawienie **trzech pierwszych punktów** na stos.

- Iteracja przez kolejne punkty:
     - sprawdzamy, czy przejście tworzy **skręt przeciwny do ruchu wskazówek zegara**
     - jeśli **tak** → dodajemy punkt do otoczki
     - jeśli **nie** → usuwamy poprzedni punkt ze stosu i ponownie sprawdzamy.

### Napotkane problemy i ich rozwiązanie: 

- **Problem:** Trudność w zrozumieniu iloczynu wektorowego i określenia kierunku skrętu

- **Rozwiązanie:** Analiza wzoru matematycznego, rysowanie sytuacji, zrozumienie geometrii

### Zastosowane technologie i narzędzia:
- Algorytm **Graham Scan** — obliczanie otoczki
- `std::sort` — sortowanie punktów według kąta względem **p0**
- Funkcje pomocnicze:
     - obliczanie **iloczynu wektorowego**
     - obliczanie **dystansu między punktami**

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

- Spośród maksymalnych odległości dla wszystkich krawędzi wybieramy **minimalną** — jest to najmniejsza możliwa odległość między dwiema równoległymi prostymi spełniającymi warunki zadania.

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

- "Utworzenie" **paska (obszaru)** wokół środka o **szerokości** ```2 x min_dystans```.

- Sprawdzenie punktów znajdujących się w pasku — **może tam znajdować się para bliższa niż w podzbiorach**.

### Napotkane problemy i ich rozwiązanie: 

- **Problem:** Optymalne przeszukiwanie punktów w "utworzonym" pasku.

- **Rozwiązanie:** Rozrysowanie sytuacji i analiza geometryczna, aby zrozumieć, które pary należy sprawdzać.

### Zastosowane technologie i narzędzia:
- **Rekurencja** — dzielenie problemu na mniejsze fragmenty
- `std::sort` — sortowanie punktów według współrzędnej X
- **Algorytmy geometryczne** — ograniczenie liczby porównań punktów w pasku