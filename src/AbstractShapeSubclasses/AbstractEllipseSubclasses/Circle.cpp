#include "Circle.h"
#include "cmath"

Circle::Circle(unsigned int id, Point center, double r)
    : AbstractEllipse(id, center), r(r) {}

double Circle::Perimeter() const {return 2 * M_PI * r;}
double Circle::Area() const {return M_PI * r * r;}
