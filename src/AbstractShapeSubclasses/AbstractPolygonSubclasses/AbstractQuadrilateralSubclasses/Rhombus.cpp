#include "Rhombus.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument;

Rhombus::Rhombus(unsigned int id, Point center, double d1, double d2)
    : AbstractQuadrilateral(id), center(center), d1(d1), d2(d2) {
    if (d1 <= 0 || d2 <= 0) throw invalid_argument("Invalid diagonals.");
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
