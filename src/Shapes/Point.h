#ifndef GEOMETRICSHAPES_POINT_H
#define GEOMETRICSHAPES_POINT_H

#include <ostream>

class Point {
private:
    double x, y;
public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double X() const {return x;}
    double Y() const {return y;}

    Point Rotate(const Point& center, double angle) const;
    void Translate(double dx, double dy) {x += dx; y += dy;}

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    bool operator==(const Point& point) const;
};

#endif //GEOMETRICSHAPES_POINT_H
