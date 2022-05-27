#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

//#include "../../Shape.h"
#include "../AbstractEllipse.h"

class Ellipse : public AbstractEllipse {
private:
    double a, b;
public:
    Ellipse(Point center, double a, double b);
    double getA() const;
    double getB() const;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_ELLIPSE_H
