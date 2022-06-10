#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.X() << ", " << point.Y() << ")";
    return os;
}

bool Point::operator==(const Point &point) const {
    return this->X() == point.X() && this->Y() == point.Y();
}
