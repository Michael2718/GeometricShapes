#ifndef GEOMETRICSHAPES_ABSTRACTPOLYGON_H
#define GEOMETRICSHAPES_ABSTRACTPOLYGON_H

#include "../AbstractShape.h"

class AbstractPolygon : public AbstractShape {
private:
    unsigned int vertex_count;
public:
    AbstractPolygon(unsigned int id, unsigned int vertex_count);

    unsigned int GetVertexCount() const;

    double Perimeter() const override = 0;
    double Area() const override = 0;
};


#endif //GEOMETRICSHAPES_ABSTRACTPOLYGON_H
