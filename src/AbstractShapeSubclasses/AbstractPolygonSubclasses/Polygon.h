#ifndef GEOMETRICSHAPES_POLYGON_H
#define GEOMETRICSHAPES_POLYGON_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class Polygon : public AbstractPolygon {
private:
    std::vector<Point> vertices;
public:
    Polygon(unsigned int id, const std::vector<Point>& points);

    std::vector<Point> GetVertices() const;

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_POLYGON_H
