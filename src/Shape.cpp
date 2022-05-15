#include "Shape.h"

using std::invalid_argument;

Shape::Shape() : id(0), x(0), y(0), rotation_angle(0) {}

Shape::Shape(unsigned int id, double x, double y, double rotation_angle)
    : id(id), x(x), y(y), rotation_angle(rotation_angle) {
    if (id < 0) throw invalid_argument("Invalid Shape Id.");
}

