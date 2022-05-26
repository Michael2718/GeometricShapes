#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

#include "../Shape.h"

class Ellipse {
private:
    Point center;
    double a, b;
public:
    Ellipse(Point center, double a, double b);
    double getA() const {return a;}
    double getB() const {return b;}
    virtual double Area() const {return 3.14 * a * b;}
};


#endif //GEOMETRICSHAPES_ELLIPSE_H
