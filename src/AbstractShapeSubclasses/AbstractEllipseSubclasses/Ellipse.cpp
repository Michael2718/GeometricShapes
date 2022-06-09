#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

using std::invalid_argument;

Ellipse::Ellipse(unsigned int id, Point center, double a, double b)
    : AbstractEllipse(id, center), a(a), b(b) {
    if (a <= 0 || b <= 0) throw invalid_argument("Invalid semi-axes.");
}

void Ellipse::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    a *= k;
    b *= k;
}

double Ellipse::Perimeter() const {return 2 * M_PI * sqrt((a*a + b*b)/2.0);}

double Ellipse::Area() const {return M_PI * a * b;}
