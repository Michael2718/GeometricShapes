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
    Point P1() const {return p1;}
    Point P2() const {return p2;}
    Point P3() const {return p3;}
    Point P4() const {return p4;}

    double Perimeter() const override = 0;
    double Area() const override = 0;
protected:
    void SetPoints(const std::vector<Point>& new_points);
};

#endif //GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
