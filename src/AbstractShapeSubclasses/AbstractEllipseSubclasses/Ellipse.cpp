#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

using std::invalid_argument;

Ellipse::Ellipse(unsigned int id, Point center, double a, double b)
    : AbstractEllipse(id, center), a(a), b(b) {}

void Ellipse::SetA(double new_a) {
    if (new_a <= 0) throw invalid_argument("Invalid value of new 'a' side.");
    a = new_a;
}

void Ellipse::SetB(double new_b) {
    if (new_b <= 0) throw invalid_argument("Invalid value of new 'b' side.");
    a = new_b;
}

double Ellipse::Perimeter() const {return 2 * M_PI * sqrt((a*a + b*b)/2.0);}

double Ellipse::Area() const {return M_PI * a * b;}
