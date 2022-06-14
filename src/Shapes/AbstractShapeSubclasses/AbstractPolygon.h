#ifndef GEOMETRICSHAPES_ABSTRACTPOLYGON_H
#define GEOMETRICSHAPES_ABSTRACTPOLYGON_H

#include "AbstractShape.h"
#include <string>

class AbstractPolygon : public AbstractShape {
private:
    unsigned int vertex_count;
public:
    AbstractPolygon(ShapeID id, unsigned int vertex_count);

    unsigned int GetVertexCount() const;

    std::string Info() const override;
};

#endif //GEOMETRICSHAPES_ABSTRACTPOLYGON_H
