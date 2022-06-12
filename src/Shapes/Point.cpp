#include "Point.h"
#include <cmath>

Point Point::Rotate(const Point &center, double angle) const {
    double r_angle = angle * (M_PI / 180.0);
    double new_x = center.X() + (x-center.X())*cos(r_angle) + (y-center.Y())*sin(r_angle);
    double new_y = center.Y() - (x-center.X())*sin(r_angle) + (y-center.Y())*cos(r_angle);
    return {new_x, new_y};
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.X() << ", " << point.Y() << ")";
    return os;
}

bool Point::operator==(const Point &point) const {
    return this->X() == point.X() && this->Y() == point.Y();
}
