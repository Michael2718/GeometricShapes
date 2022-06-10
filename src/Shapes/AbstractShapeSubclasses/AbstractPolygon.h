#ifndef GEOMETRICSHAPES_ABSTRACTPOLYGON_H
#define GEOMETRICSHAPES_ABSTRACTPOLYGON_H

#include "AbstractShape.h"

class AbstractPolygon : public AbstractShape {
private:
    unsigned int vertex_count;
public:
    AbstractPolygon(unsigned int id, unsigned int vertex_count);

    unsigned int GetVertexCount() const;
};

#endif //GEOMETRICSHAPES_ABSTRACTPOLYGON_H
