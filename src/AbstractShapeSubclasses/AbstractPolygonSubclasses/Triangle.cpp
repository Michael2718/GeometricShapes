#include "Triangle.h"
#include <stdexcept>
#include "cmath"

using std::invalid_argument;

Triangle::Triangle(unsigned int id, Point p1, Point p2, Point p3)
    : AbstractPolygon(id, 3), p1(p1), p2(p2), p3(p3) {
    if (this->Area() == 0) throw invalid_argument("Invalid points. Triangle doesn't exist.");
}

void Triangle::SetPoints(std::vector<Point> points) {
    p1 = points[0];
    p2 = points[1];
    p3 = points[2];
}

void Triangle::SetPoints(Point new_p1, Point new_p2, Point new_p3) {
    p1 = new_p1;
    p2 = new_p2;
    p3 = new_p3;
}

double Triangle::Perimeter() const {
    double a = sqrt(pow(p2.X() - p1.X(), 2) + pow(p2.Y() - p1.Y(), 2));
    double b = sqrt(pow(p3.X() - p2.X(), 2) + pow(p3.Y() - p2.Y(), 2));
    double c = sqrt(pow(p1.X() - p3.X(), 2) + pow(p1.Y() - p3.Y(), 2));
    return a + b + c;
}

double Triangle::Area() const {
    return 0.5*(p1.X()*std::abs(p2.Y() - p3.Y()) +
                p2.X()*std::abs(p3.Y() - p1.Y()) +
                p3.X()*std::abs(p1.Y() - p2.Y()));
}
