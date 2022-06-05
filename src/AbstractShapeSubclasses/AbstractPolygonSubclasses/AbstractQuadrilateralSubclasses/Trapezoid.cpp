#include "Trapezoid.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument;

Trapezoid::Trapezoid(unsigned int id, Point center, double a, double b, double height)
    : AbstractQuadrilateral(id), center(center), a(a), b(b), height(height) {
    if (a <= 0 || b <= 0 || height <= 0) throw invalid_argument("Invalid diagonals.");
}

void Trapezoid::SetA(double new_a) {
    if (new_a <= 0) throw invalid_argument("Invalid new 'a' side.");
    a = new_a;
}

void Trapezoid::SetB(double new_b) {
    if (new_b <= 0) throw invalid_argument("Invalid new 'b' side.");
    b = new_b;
}

void Trapezoid::SetHeight(double new_height) {
    if (new_height <= 0) throw invalid_argument("Invalid new height.");
    height = new_height;
}

double Trapezoid::Perimeter() const {return 0;}

double Trapezoid::Area() const {return (a + b)/2*height;}
