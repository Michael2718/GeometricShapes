#include "AbstractEllipse.h"

AbstractEllipse::AbstractEllipse(unsigned int id, Point center)
    : AbstractShape(id), center(center), rotation_angle(0) {}

void AbstractEllipse::Rotate(double angle) {
    rotation_angle += angle;
}

void AbstractEllipse::Translate(double dx, double dy) {
    center.Translate(dx, dy);
}
