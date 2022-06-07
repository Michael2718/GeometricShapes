#ifndef GEOMETRICSHAPES_RHOMBUS_H
#define GEOMETRICSHAPES_RHOMBUS_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Rhombus : public AbstractQuadrilateral {
private:
    Point center;
    double d1, d2; // d1 - diagonal parallel to OX axis; d2 - diagonal parallel to OY axis.
public:
    Rhombus(unsigned int id, Point center, double d1, double d2);
    Rhombus(unsigned int id, Point center, Point p1, Point p2);

    double GetD1() const {return d1;}
    double GetD2() const {return d2;}

    void SetD1(double new_d1);
    void SetD2(double new_d2);

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_RHOMBUS_H
