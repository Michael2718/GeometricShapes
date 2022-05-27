#include "Circle.h"

Circle::Circle(Point center, double r) : AbstractEllipse(center), r(r) {}

double Circle::getRadius() const {return r;}
double Circle::Area() const {return 3.14 * r * r;}
