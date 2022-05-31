#include "Polygon.h"
#include <stdexcept>

using std::invalid_argument;

Polygon::Polygon(unsigned int id, const std::vector<Point>& vertices)
    : AbstractPolygon(id, vertices.size()) {
    if (vertices.size() < 3) throw invalid_argument("Invalid Polygon size.");
}
