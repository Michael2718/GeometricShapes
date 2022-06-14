#include <string>
#include <sstream>
#include "AbstractPolygon.h"

using std::string, std::ostringstream;

AbstractPolygon::AbstractPolygon(ShapeID id, unsigned int vertex_count)
    : AbstractShape(id), vertex_count(vertex_count) {}

unsigned int AbstractPolygon::GetVertexCount() const {return vertex_count;}

string AbstractPolygon::Info() const {
    ostringstream oss;
    oss << "Vertex count: " << vertex_count;
    return oss.str();
}