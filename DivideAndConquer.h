#ifndef DIVIDEANDCONQUER_H
#define DIVIDEANDCONQUER_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>

struct Result {
    double distance;
    Point point1, point2;
};

class DivideAndConquer {
private:
     double distSq(Point a, Point b) {
        return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    }

    // Funkcja przeszukuje kazdy punkt z kazdym i szuka najblizszej odlegosci (dobry dla malej ilosci punktow)
    Result bruteForce(std::vector<Point>& points, int left, int right) {
        Result bestResult = { DBL_MAX, {0,0}, {0,0} };

        for (int i = left; i < right; i++) {
            for (int j = i+1; j < right; j++) {
                double tempDistance = distSq(points[i], points[j]);
                if (tempDistance < bestResult.distance) {
                    bestResult.distance = tempDistance;
                    bestResult.point1 = points[i];
                    bestResult.point2 = points[j];
                }
            }
        }

        return bestResult;
    }

public:
    // Rekurencyjna metoda Divide And Conquer (dzieli rekurencyjnie na dwie polowy i znajduje najblizsza odleglosc)
    Result closestPairRecursive(std::vector<Point>& points, int left, int right) {
        
        // 1. Jesli jest malo punktow to uzywamy brute force
        if (right - left <= 3) return bruteForce(points, left, right);    
        
        // 2. Wyznaczamy srodek
        int mid = (left + right) / 2;
        double midX = points[mid].x;

        // 3. Liczymy odlegosci dla lewej i prawej polowy
        Result leftResult = closestPairRecursive(points, left, mid);
        Result rightResult = closestPairRecursive(points, mid, right);
        
        Result bestResult;
        if (leftResult.distance < rightResult.distance) {
            bestResult = leftResult;
        } else {
            bestResult = rightResult;
        }
        
        double distance = bestResult.distance;

        // 4. Gdy znalezlismy najmnniejsza odlegosc -> "tworzymy" pasek wokol srodka o szerokosci = 2*distance, poniewaz musimy sprawdzic czy na laczeniu srodka nie ma blizszych punktow
        std::vector<Point> strip;
        for (int i = left; i < right; i++) {
            if (fabs(points[i].x - midX) < distance) strip.push_back(points[i]);
        }

        // 5. Sprawdzamy w pasku czy tam nie ma namniejszej odleglosci
        std::sort(strip.begin(), strip.end(), [](Point a, Point b){
            return a.y < b.y;
        });

        for (int i = 0; i < strip.size(); i++) {
            for (int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < bestResult.distance; j++) {
                double tempDistance = distSq(strip[i], strip[j]);
                if (tempDistance < bestResult.distance) {
                    bestResult.distance = tempDistance;
                    bestResult.point1 = strip[i];
                    bestResult.point2 = strip[j];
                }
            }
        }

        return bestResult;
    }

    // Glowna funnkcja algorytmu
    Result closestPair(std::vector<Point>& points) {
        std::sort(points.begin(), points.end(), [](Point a, Point b) {
            return a.x < b.x; // Sortujemy punkty wzgledem osi X, by lepiej podzielic na polowe lewa i prawa
        });

        return closestPairRecursive(points, 0, points.size());
    }
};

#endif
