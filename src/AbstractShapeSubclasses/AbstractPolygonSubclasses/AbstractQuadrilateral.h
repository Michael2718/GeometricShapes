#ifndef GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
#define GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class AbstractQuadrilateral : public AbstractPolygon {
public:
    AbstractQuadrilateral(unsigned int id);

    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};


#endif //GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
