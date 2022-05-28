#include "Ellipse.h"
#include "cmath"

Ellipse::Ellipse(unsigned int id, Point center, double a, double b)
    : AbstractEllipse(id, center), a(a), b(b) {}

double Ellipse::GetA() const {return a;}
double Ellipse::GetB() const {return b;}

double Ellipse::Perimeter() const {return 2 * M_PI * sqrt((a*a + b*b)/2.0);}
double Ellipse::Area() const {return M_PI * a * b;}
