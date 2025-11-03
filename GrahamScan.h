#ifndef GRAHAMSCAN_H
#define GRAHAMSCAN_H

#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    double x;
    double y;
};

class GrahamScan {
private:
    // Odlegosc punktow, ale bez pierwiastka, bo to tylko do porownania
    double dist(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    // Oblicza orientacje 3 punktow (czy skreca w prawo, lewo czy wspoliniowe)
    // Iloczyn wektorowy dwoch wektorow (cross product) 
    int orientation(Point a, Point b, Point c) {
        double v = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

        if (v < 0) return -1; // Skret w prawo (wg wskazowek zegara)
        if (v > 0) return 1; // Skret w lewo (odwrotnie do wskazowek zegara)
        return 0; // Wspoliniowe
    }

public:
    std::vector<Point> findShell(std::vector<Point> points) {
        int n = points.size();
        if (n < 3) return points; // Otoczka nie ma sensu, gdy jest mniej niz 3 punkty

        // 1. Szukamy punkty o najmniejszym Y (gdy jest remis, bierzemy najmniejszego X)
        std::sort(points.begin(), points.end(), [](Point a, Point b) {
            if (a.y != b.y) {
                return a.y < b.y;
            } else {
                return a.x < b.x;
            }
        });

        Point p0 = points[0]; // To jest nasz punkt 0, od ktorego bedziemy sie odnosic

        // 2. Sortujemy punkty wedlug kata wzgledem p0, ale p0 zostanie juz na poczatku list przez: points.begin() + 1
        std::sort(points.begin() + 1, points.end(), [&](Point a, Point b) {
            double angleA = atan2(a.y - p0.y, a.x - p0.x); // Oblicza kat wektora wzgledem osi X
            double angleB = atan2(b.y - p0.y, b.x - p0.x);

            if (angleA == angleB) return dist(p0, a) < dist(p0,b); // Gdy punkty sa wspoliniowe pierwszym punktem bedzie ten ktory jest blizszy p0

            return angleA < angleB;
        });

        // 3. Tworzymy stos z vectorow, do ktorego przypisujemy 3 pierwsze punkty
        std::vector<Point> shell;
        shell.push_back(points[0]);
        shell.push_back(points[1]);
        shell.push_back(points[2]);

        // 4. Przechodzimy przez reszte punktow i kontrolujemy by skret byl w lewo (odwrotny do ruchu wskazowek zegara)
        for (int i = 3; i < n; i++) {
            while (shell.size() >= 2 && orientation(shell[shell.size()-2], shell.back(), points[i]) <= 0) {
                shell.pop_back(); // Jesli skret w prawo to usun
            }

            shell.push_back(points[i]);
        }

        return shell;
    }    
};

#endif
