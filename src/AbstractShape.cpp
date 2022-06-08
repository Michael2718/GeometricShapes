#include "AbstractShape.h"
#include <stdexcept>

using std::invalid_argument;

AbstractShape::AbstractShape() : id(0) {}

AbstractShape::AbstractShape(unsigned int id)
    : id(id) {
    if (id < 0) throw invalid_argument("Invalid Shape Id.");
}
