#ifndef GEOMETRICSHAPES_CONVEXPOLYGON_H
#define GEOMETRICSHAPES_CONVEXPOLYGON_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class ConvexPolygon : public AbstractPolygon {
private:
    std::vector<Point> vertices;
    Point center;
public:
    ConvexPolygon(unsigned int id, const std::vector<Point>& points);

    std::vector<Point> GetVertices() const {return vertices;}
    Point GetCenter() const {return center;}

    void Scale(double k) override;
    void Rotate(double angle) override;

    double Perimeter() const override;
    double Area() const override;
protected:
    void SetPoints(const std::vector<Point>& new_vertices);
};


#endif //GEOMETRICSHAPES_CONVEXPOLYGON_H
