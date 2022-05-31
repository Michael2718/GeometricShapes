#include "Polygon.h"
#include <stdexcept>

using std::invalid_argument;

Polygon::Polygon(unsigned int id, const std::vector<Point>& vertices)
    : AbstractPolygon(id, vertices.size()), vertices(vertices) {
    if (vertices.size() < 3) throw invalid_argument("Invalid Polygon size.");
}

std::vector<Point> Polygon::GetVertices() const {return vertices;}

double Polygon::Perimeter() const {return 1;}
double Polygon::Area() const {return 2;}
