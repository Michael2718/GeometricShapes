#ifndef GEOMETRICSHAPES_CONVEXPOLYGON_H
#define GEOMETRICSHAPES_CONVEXPOLYGON_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class ConvexPolygon : public AbstractPolygon {
private:
    std::vector<Point> vertices;
public:
    ConvexPolygon(unsigned int id, const std::vector<Point>& points);

    std::vector<Point> GetVertices() const {return vertices;}

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_CONVEXPOLYGON_H
