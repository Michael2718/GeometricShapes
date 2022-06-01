#include "Circle.h"
#include "cmath"
#include <stdexcept>

using std::invalid_argument;

Circle::Circle(unsigned int id, Point center, double r)
    : AbstractEllipse(id, center), r(r) {}

void Circle::SetR(double new_r) {
    if (new_r <= 0) throw invalid_argument("Invalid value of new radius.");
    r = new_r;
}

double Circle::Perimeter() const {return 2 * M_PI * r;}
double Circle::Area() const {return M_PI * r * r;}
