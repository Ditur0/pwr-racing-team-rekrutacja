#ifndef TWOPARALLELLINES_H
#define TWOPARALLELLINES_H

#include <vector>
#include <cmath>
#include <algorithm>

class TwoParallelLines {
private:
    double distPointToLine(Point p1, Point p2, Point p3) {
       double a = p2.y - p1.y;
       double b = p1.x - p2.x;
       double c = (p2.x * p1.y) - (p1.x * p2.y);

       double distance = fabs((a * p3.x) + (b * p3.y) + c) / sqrt(a * a + b * b);

       return distance;
    }

public:
    // Do funkcji przekazujemy punkty z otoczki policzonej z algorytmu Graham Scan
    double findMinDistance(std::vector<Point> shell) {
        int n = shell.size();
        if (n < 2) return 0; // Gdy jest jeden punkt wartosc wynosi 0

        // double minDistance = DBL_MAX;
        std::vector<double> distances;
        std::vector<double> distancesForEachWall;

        for (int i = 0; i < shell.size(); i ++) {
            Point a = shell[i];
            Point b;

            if (i == shell.size() - 1) {
                b = shell[0];
            } else {
                b = shell[i + 1];
            }

            // Dla kazdej sciany otoczki liczymy odlegosc kazdego punktu i wybieramy ta ktora jest najdluzsza
            for (int j = 0; j < shell.size(); j++) {
                Point c = shell[j];
                
                double distance = distPointToLine(a, b, c);
                distances.push_back(distance); // Dystanse wszystkich punktow do prostej
            }

            // Wybieramy najdalszy dystans
            double greatesDistance = *std::max_element(distances.begin(), distances.end());
            distancesForEachWall.push_back(greatesDistance);
            distances.clear();
        }

        double minDistance = *std::min_element(distancesForEachWall.begin(), distancesForEachWall.end());

        return minDistance;
    }
};

#endif
