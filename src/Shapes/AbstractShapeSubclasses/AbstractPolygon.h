#ifndef GEOMETRICSHAPES_ABSTRACTPOLYGON_H
#define GEOMETRICSHAPES_ABSTRACTPOLYGON_H

#include "AbstractShape.h"
#include <string>

class AbstractPolygon : public AbstractShape {
private:
    int vertex_count;
public:
    AbstractPolygon(ShapeId id, int vertex_count);

    int GetVertexCount() const;

    std::string Info() const override;
};

#endif //GEOMETRICSHAPES_ABSTRACTPOLYGON_H
