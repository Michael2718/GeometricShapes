#include "Rectangle.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument, std::vector;

Rectangle::Rectangle(unsigned int id, Point center, double width, double height)
    : AbstractQuadrilateral(id, Point(center.X()-width/2, center.Y()+height/2),
                                Point(center.X()+width/2, center.Y()+height/2),
                                Point(center.X()+width/2, center.Y()-height/2),
                                Point(center.X()-width/2, center.Y()-height/2)),
    center(center),
    width(width), height(height) {
    if (width <= 0 || height <= 0) throw invalid_argument("Invalid sides.");
}

Rectangle::Rectangle(unsigned int id, Point p1, Point p2, Point p3, Point p4)
    : AbstractQuadrilateral(id, p1, p2, p3, p4),
    center((p1.X()+p3.X())/2, (p1.Y()+p3.Y())/2),
    width (sqrt(pow(p2.X()-p1.X(), 2) + pow(p2.Y()-p1.Y(), 2))),
    height(sqrt(pow(p4.X()-p1.X(), 2) + pow(p4.Y()-p1.Y(), 2))) {
    if ((p2.X()-p1.X()) * (p4.X()-p1.X()) + (p2.Y()-p1.Y()) * (p4.Y()-p1.Y()) != 0 ||
        (p4.X()-p3.X()) * (p2.X()-p3.X()) + (p4.Y()-p3.Y()) * (p2.Y()-p3.Y()) != 0) {
        throw invalid_argument("Invalid points.");
    }

    if (center.X() - p1.X() <= 0 || center.Y() - p1.Y() >= 0) throw invalid_argument("Invalid points.");
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
