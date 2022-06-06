#ifndef GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
#define GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class AbstractQuadrilateral : public AbstractPolygon {
private:
    Point p1, p2, p3, p4;
public:
    explicit AbstractQuadrilateral(unsigned int id, Point p1, Point p2, Point p3, Point p4);

    std::vector<Point> GetPoints() const;

    double Perimeter() const override = 0;
    double Area() const override = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
