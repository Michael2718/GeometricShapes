#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::GetX() const {return x;}
double Point::GetY() const {return y;}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.GetX() << ", " << point.GetY() << ")";
    return os;
}