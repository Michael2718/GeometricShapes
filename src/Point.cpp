#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.X() << ", " << point.Y() << ")";
    return os;
}