#ifndef GEOMETRICSHAPES_RHOMBUS_H
#define GEOMETRICSHAPES_RHOMBUS_H

#include "AbstractQuadrilateral.h"
#include "Point.h"
#include <string>

class Rhombus : public AbstractQuadrilateral {
private:
    double d1, d2; // d1 - diagonal parallel to OX axis; d2 - diagonal parallel to OY axis.
public:
    Rhombus(Point center, double d1, double d2);
    Rhombus(Point center, Point p1, Point p2);

    double GetD1() const {return d1;}
    double GetD2() const {return d2;}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};

#endif //GEOMETRICSHAPES_RHOMBUS_H
