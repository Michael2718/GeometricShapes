#include "Rectangle.h"
#include <stdexcept>

using std::invalid_argument;

Rectangle::Rectangle(unsigned int id, Point top_left_corner, int width, int height)
    : AbstractQuadrilateral(id), top_left_corner(top_left_corner),
    width(width), height(height) {
    if (width <= 0 || height <= 0) throw invalid_argument("Invalid sides.");
}

void Rectangle::SetWidth(double new_width) {
    if (new_width <= 0) throw invalid_argument("Invalid new width.");
    width = new_width;
}

void Rectangle::SetHeight(double new_height) {
    if (new_height <= 0) throw invalid_argument("Invalid new height.");
    height = new_height;
}

double Rectangle::Perimeter() const {return 2*(width+height);}

double Rectangle::Area() const {return width*height;}
