#ifndef GEOMETRICSHAPES_TRIANGLE_H
#define GEOMETRICSHAPES_TRIANGLE_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class Triangle : public AbstractPolygon {
private:
    Point p1, p2, p3;
    //std::vector<Point> points;
public:
    Triangle(unsigned int id, Point p1, Point p2, Point p3);

    std::vector<Point> GetPoints() const {return {p1, p2, p3};}

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_TRIANGLE_H
