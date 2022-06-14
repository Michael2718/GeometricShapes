#include "Rectangle.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument, std::vector;

Rectangle::Rectangle(unsigned int id, Point center, double width, double height)
    : AbstractQuadrilateral(id, {center.X() - width / 2, center.Y() + height / 2},
                                {center.X() + width / 2, center.Y() + height / 2},
                                {center.X() + width / 2, center.Y() - height / 2},
                                {center.X() - width / 2, center.Y() - height / 2},
                                center),
    width(width), height(height) {
    if (width <= 0 || height <= 0) throw invalid_argument("Invalid sides.");
}

Rectangle::Rectangle(unsigned int id, Point p1, Point p2, Point p3, Point p4)
    : AbstractQuadrilateral(id, p1, p2, p3, p4,
                            {(p1.X()+p3.X())/2, (p1.Y()+p3.Y())/2}),
    width (sqrt(pow(p2.X()-p1.X(), 2) + pow(p2.Y()-p1.Y(), 2))),
    height(sqrt(pow(p4.X()-p1.X(), 2) + pow(p4.Y()-p1.Y(), 2))) {
    if ((p2.X()-p1.X()) * (p4.X()-p1.X()) + (p2.Y()-p1.Y()) * (p4.Y()-p1.Y()) != 0 ||
        (p4.X()-p3.X()) * (p2.X()-p3.X()) + (p4.Y()-p3.Y()) * (p2.Y()-p3.Y()) != 0) {
        throw invalid_argument("Invalid points.");
    }

    if (AbstractQuadrilateral::GetCenter().X() - p1.X() <= 0 ||
        AbstractQuadrilateral::GetCenter().Y() - p1.Y() >= 0) {
        throw invalid_argument("Invalid points.");
    }
}

void Rectangle::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    width  *= k;
    height *= k;
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(k*point.X()+(1-k)*GetCenter().X(),
                                k*point.Y()+(1-k)*GetCenter().Y());
    }
    SetPoints(new_points);
}

double Rectangle::Perimeter() const {return 2*(width+height);}

double Rectangle::Area() const {return width*height;}
