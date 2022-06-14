#include "AbstractPolygon.h"

AbstractPolygon::AbstractPolygon(ShapeID id, unsigned int vertex_count)
    : AbstractShape(id), vertex_count(vertex_count) {}

unsigned int AbstractPolygon::GetVertexCount() const {return vertex_count;}
