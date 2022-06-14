#include "AbstractEllipse.h"

AbstractEllipse::AbstractEllipse(ShapeID id, Point center)
    : AbstractShape(id), center(center), rotation_angle(0) {}

void AbstractEllipse::Rotate(double angle) {
    rotation_angle += angle;
}

void AbstractEllipse::Rotate(Point r_center, double angle) {
    rotation_angle += angle;
}

void AbstractEllipse::Translate(double dx, double dy) {
    center.Translate(dx, dy);
}
