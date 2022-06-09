#ifndef GEOMETRICSHAPES_SIMPLEPOLYGON_H
#define GEOMETRICSHAPES_SIMPLEPOLYGON_H

#include "../AbstractPolygon.h"
#include "../../Point.h"
#include <vector>

class SimplePolygon : public AbstractPolygon {
private:
    std::vector<Point> vertices;
    Point center;
public:
    SimplePolygon(unsigned int id, const std::vector<Point>& points);

    std::vector<Point> GetVertices() const {return vertices;}
    Point GetCenter() const {return center;}

    void Scale(double k) override;
    void Rotate(double angle) override;

    double Perimeter() const override;
    double Area() const override;
protected:
    void SetVertices(const std::vector<Point>& new_vertices);
};


#endif //GEOMETRICSHAPES_SIMPLEPOLYGON_H
