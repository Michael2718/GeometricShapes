#include "AbstractShape.h"
#include <stdexcept>

using std::invalid_argument;

AbstractShape::AbstractShape(ShapeID id)
    : id(id) {
    //if () throw invalid_argument("Invalid Shape Id.");
}
