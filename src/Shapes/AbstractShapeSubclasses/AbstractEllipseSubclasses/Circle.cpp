#include "Circle.h"
#include "cmath"
#include <stdexcept>

using std::invalid_argument;

Circle::Circle(Point center, double r)
    : AbstractEllipse(CIRCLE, center), r(r) {
    if (r <= 0) throw invalid_argument("Invalid radius.");
}

void Circle::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    r *= k;
}

double Circle::Perimeter() const {return 2 * M_PI * r;}

double Circle::Area() const {return M_PI * r * r;}
