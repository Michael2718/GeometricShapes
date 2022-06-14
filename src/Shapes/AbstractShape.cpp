#include "AbstractShape.h"
#include <stdexcept>

using std::invalid_argument;

AbstractShape::AbstractShape(ShapeID id)
    : id(id) {
}


std::string AbstractShape::GetStringId() const {
    switch (id) {
        case SIMPLE_POLYGON:
            return "Simple Polygon";
        case RECTANGLE:
            return "Rectangle";
        case RHOMBUS:
            return "Rhombus";
        case TRAPEZOID:
            return "Trapezoid";
        case TRIANGLE:
            return "Triangle";
        case ELLIPSE:
            return "Ellipse";
        case CIRCLE:
            return "Circle";
        case COMPLEX_SHAPE:
            return "Complex Shape";
        default:
            return "";
    }
}
