#include "ComplexShape.h"
#include <stdexcept>
#include "Point.h"

using std::invalid_argument;

ComplexShape::ComplexShape(unsigned int id, const std::vector<AbstractShape *> &shapes)
    : AbstractShape(id), shapes(shapes), center({0, 0}) {
    if (shapes.empty()) throw invalid_argument("Invalid number of shapes. Complex shape can't be empty.");
    // TODO : Calculate center of ComplexShape
}

void ComplexShape::Scale(double k) {
    // Translate all shapes
    // Scale all shapes
}

void ComplexShape::Rotate(double angle) {
    // Rotate all shapes relatively around center of ComplexShape
}

void ComplexShape::Translate(double dx, double dy) {
    // Translate center
    // Translate all shapes
}

double ComplexShape::Perimeter() const {
    // Sum all perimeters
}

double ComplexShape::Area() const {
    //Sum all areas
}
