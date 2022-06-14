#include "Ellipse.h"
#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>

using std::invalid_argument, std::string, std::ostringstream;

Ellipse::Ellipse(Point center, double a, double b)
    : AbstractEllipse(ELLIPSE, center), a(a), b(b) {
    if (a <= 0 || b <= 0) throw invalid_argument("Invalid semi-axes.");
}

void Ellipse::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    a *= k;
    b *= k;
}

double Ellipse::Perimeter() const {return 2 * M_PI * sqrt((a*a + b*b)/2.0);}

double Ellipse::Area() const {return M_PI * a * b;}

string Ellipse::Info() const {
    ostringstream oss;

    oss << "Ellipse Info" << "\n"
        << AbstractEllipse::Info() << "\n"
        << "Semi-major axis 'a': " << a << "\n"
        << "Semi-minor axis 'b': " << b << "\n"
        << "Perimeter: " << Perimeter() << "\n"
        << "Area: " << Area();

    return oss.str();
}
