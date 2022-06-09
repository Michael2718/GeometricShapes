#ifndef GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
#define GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class AbstractQuadrilateral : public AbstractPolygon {
private:
    Point p1, p2, p3, p4, center;
public:
    AbstractQuadrilateral(unsigned int id, Point p1, Point p2, Point p3, Point p4, Point center);

    std::vector<Point> GetPoints() const;
    Point GetCenter() const {return center;}

    void Translate(double dx, double dy) override;
protected:
    void SetPoints(const std::vector<Point>& new_points);
};

#endif //GEOMETRICSHAPES_ABSTRACTQUADRILATERAL_H
