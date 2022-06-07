#include "Rhombus.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument;

Rhombus::Rhombus(unsigned int id, Point center, double d1, double d2)
    : AbstractQuadrilateral(id, Point(), Point(), Point(), Point()), center(center), d1(d1), d2(d2) {
    if (d1 <= 0 || d2 <= 0) throw invalid_argument("Invalid diagonals.");
}

Rhombus::Rhombus(unsigned int id, Point center, Point p1, Point p2)
    : AbstractQuadrilateral(id, p1, p2,
                            Point(2*center.X()-p1.X(), 2*center.Y()- p1.Y()),
                            Point(2*center.X()-p2.X(), 2*center.Y()- p2.Y())),
    center(center),
    d1(sqrt(pow(2*(p1.X() - center.X()), 2) + pow(2*(p1.Y() - center.Y()), 2))),
    d2(sqrt(pow(2*(p2.X() - center.X()), 2) + pow(2*(p2.Y() - center.Y()), 2))) {
    if ((p1.X()-center.X())*(p2.X()-center.X()) + (p1.Y()-center.Y())*(p2.Y()-center.Y()) != 0) {
        throw invalid_argument("Invalid points.");
    }
    if (p1.Y() < p2.Y()) throw invalid_argument("Invalid points.");
}

void Rhombus::SetD1(double new_d1) {
    if (new_d1 <= 0) throw invalid_argument("Invalid new first diagonal.");
    d1 = new_d1;
}

void Rhombus::SetD2(double new_d2) {
    if (new_d2 <= 0) throw invalid_argument("Invalid new second diagonal.");
    d2 = new_d2;
}

double Rhombus::Perimeter() const {return 2*sqrt(d1*d1 + d2*d2);}

double Rhombus::Area() const {return (d1*d2)/2;}
