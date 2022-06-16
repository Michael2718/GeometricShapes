#ifndef GEOMETRICSHAPES_TRIANGLE_H
#define GEOMETRICSHAPES_TRIANGLE_H

#include "AbstractPolygon.h"
#include "Point.h"
#include <vector>
#include <string>

class Triangle : public AbstractPolygon {
private:
    Point p1, p2, p3, center; // Center defined as centroid
public:
    explicit Triangle(std::vector<Point> points);
    Triangle(Point p1, Point p2, Point p3);

    std::vector<Point> GetPoints() const {return {p1, p2, p3};}
    Point GetCenter() const override {return center;}

    void SetPoints(const std::vector<Point>& new_points);

    void Scale(double k) override;
    void Rotate(double angle) override;
    void Rotate(Point r_center, double angle) override;
    void Translate(double dx, double dy) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};


#endif //GEOMETRICSHAPES_TRIANGLE_H
