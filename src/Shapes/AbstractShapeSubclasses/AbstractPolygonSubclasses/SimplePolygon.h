#ifndef GEOMETRICSHAPES_SIMPLEPOLYGON_H
#define GEOMETRICSHAPES_SIMPLEPOLYGON_H

#include "AbstractPolygon.h"
#include "Point.h"
#include <vector>
#include <string>

class SimplePolygon : public AbstractPolygon {
private:
    std::vector<Point> vertices;
    Point center;
public:
    explicit SimplePolygon(const std::vector<Point>& points);

    std::vector<Point> GetVertices() const {return vertices;}
    Point GetCenter() const override {return center;}

    void Scale(double k) override;
    void Rotate(double angle) override;
    void Rotate(Point r_center, double angle) override;
    void Translate(double dx, double dy) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
protected:
    void SetVertices(const std::vector<Point>& new_vertices);
};


#endif //GEOMETRICSHAPES_SIMPLEPOLYGON_H
