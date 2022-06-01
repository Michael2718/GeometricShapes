#include "Triangle.h"
#include <stdexcept>

using std::invalid_argument;

Triangle::Triangle(unsigned int id, Point p1, Point p2, Point p3)
    : AbstractPolygon(id, 3), p1(p1), p2(p2), p3(p3) {
    if (this->Area() == 0) throw invalid_argument("Invalid points. Triangle doesn't exist.");
}

double Triangle::Perimeter() const {return 1;}

double Triangle::Area() const {
    return 0.5*(p1.X()*std::abs(p2.Y() - p3.Y()) +
                p2.X()*std::abs(p3.Y() - p1.Y()) +
                p3.X()*std::abs(p1.Y() - p2.Y()));
}
