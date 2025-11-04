#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "GrahamScan.h"
#include "DivideAndConquer.h"
#include "TwoParallelLines.h"

using namespace std;

// Program rekrutacyjny PWR Racing Team — dział Software
// Zadania: otoczka wypukła, minimalna odległość między prostymi, najbliższa para punktów
// Autor: Artur Skrzypczak

int main() {
    string filename;
    cout << "Podaj nazwe pliku: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file) {
        cout << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }

    int n;
    file >> n; // Wczytanie ilosci punktow

    if (n <= 0) {
        cout << "Nieprawidlowa liczba punktow!\n";
        return 1;
    }

    vector<Point> points;
    points.reserve(n); // Rezerwuje w pamieci ilosc punktow ktore przyjmie

    for (int i = 0; i < n; i++) {
        Point point;
        file >> point.x >> point.y; // Szczytuje punkt x i przypisuje go do x i y tak samo, file >> pomija spacje, od razu przechodzi do kolejnej wartosci
        points.push_back(point);
    }

    // --------------------------------------------- ZADANIE 1. ---------------------------------------------
    GrahamScan grahamScan;
    vector<Point> shell = grahamScan.findShell(points);

    cout << "Otoczka: ";
    for (int i = 0; i < shell.size(); i++) {
        cout << "(" << shell[i].x << ", " << shell[i].y << ")";
        if (i != shell.size() - 1) cout << ", ";
    }
    cout << "\n";

    // --------------------------------------------- ZADANIE 2. ---------------------------------------------
    TwoParallelLines twoParallelLines;
    double distance = twoParallelLines.findMinDistance(shell);
    cout << "Proste: d = " << distance;
    cout << "\n";

    // --------------------------------------------- ZADANIE 3. ---------------------------------------------
    DivideAndConquer divideAlgorithm;
    Result closestPair = divideAlgorithm.closestPair(points);
    double pointsDistance = sqrt(closestPair.distance);
    cout << "Najblizsze punkty: " << "[(" << closestPair.point1.x << ", " << closestPair.point1.y << "), (" << closestPair.point2.x << ", " << closestPair.point2.y << ")], d = " << pointsDistance;
    cout << "\n";

    return 0;
}
