#include "Rectangle.h"
#include <stdexcept>

using std::invalid_argument;

Rectangle::Rectangle(unsigned int id, Point top_left_corner, int a, int b)
    : AbstractQuadrilateral(id), top_left_corner(top_left_corner), a(a), b(b) {
    if (a <= 0 || b <= 0) throw invalid_argument("Invalid sides.");
}

void Rectangle::SetA(double new_a) {
    if (new_a <= 0) throw invalid_argument("Invalid new 'a' side.");
    a = new_a;
}

void Rectangle::SetB(double new_b) {
    if (new_b <= 0) throw invalid_argument("Invalid new 'b' side.");
    b = new_b;
}

double Rectangle::Perimeter() const {return 2*(a+b);}

double Rectangle::Area() const {return a*b;}
