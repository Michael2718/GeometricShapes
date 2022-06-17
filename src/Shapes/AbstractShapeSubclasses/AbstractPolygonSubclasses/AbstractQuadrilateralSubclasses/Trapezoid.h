#ifndef GEOMETRICSHAPES_TRAPEZOID_H
#define GEOMETRICSHAPES_TRAPEZOID_H

#include "AbstractQuadrilateral.h"
#include "Point.h"

class Trapezoid : public AbstractQuadrilateral {
private:
    double a, b, c, d, h; // 'a' is top side parallel to bottom 'b' side.
public:
    Trapezoid(Point p1, Point p2, Point p3, Point p4);

    [[maybe_unused]] std::vector<double> GetSides() const {return {a, b, c, d};}

    [[maybe_unused]] double GetHeight() const {return h;}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};


#endif //GEOMETRICSHAPES_TRAPEZOID_H
