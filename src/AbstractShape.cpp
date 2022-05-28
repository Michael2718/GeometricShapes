#include "AbstractShape.h"
#include <stdexcept>

using std::invalid_argument;

Shape::Shape() : id(0) {}

Shape::Shape(unsigned int id)
    : id(id) {
    if (id < 0) throw invalid_argument("Invalid Shape Id.");
}

