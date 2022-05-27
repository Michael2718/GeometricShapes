#include "Ellipse.h"

Ellipse::Ellipse(Point center, double a, double b) : AbstractEllipse(center), a(a), b(b) {}

double Ellipse::getA() const {return a;}
double Ellipse::getB() const {return b;}

double Ellipse::Area() const {return 3.14 * a * b;}
