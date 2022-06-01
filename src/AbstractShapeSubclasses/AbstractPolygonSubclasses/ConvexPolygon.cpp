#include "ConvexPolygon.h"
#include <stdexcept>

using std::invalid_argument;

ConvexPolygon::ConvexPolygon(unsigned int id, const std::vector<Point>& points)
    : AbstractPolygon(id, points.size()), vertices(points) {
    if (vertices.size() < 3) throw invalid_argument("Invalid Polygon size.");
    // TODO : Implement ConvexPolygon check
}

double ConvexPolygon::Perimeter() const {return 1;} // TODO : Implement Perimeter()
double ConvexPolygon::Area() const {return 2;} // TODO: Implement Area()
