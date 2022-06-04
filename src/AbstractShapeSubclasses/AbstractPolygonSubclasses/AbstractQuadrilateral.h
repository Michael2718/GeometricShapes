#ifndef GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
#define GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class AbstractQuadrilateral : public AbstractPolygon {
public:
    explicit AbstractQuadrilateral(unsigned int id);

    double Perimeter() const override = 0;
    double Area() const override = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
