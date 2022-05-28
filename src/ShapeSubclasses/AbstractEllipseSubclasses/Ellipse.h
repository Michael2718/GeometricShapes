#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

//#include "../../Shape.h"
#include "../AbstractEllipse.h"

class Ellipse : public AbstractEllipse {
private:
    double a, b;
public:
    Ellipse(unsigned int id, Point center, double a, double b);

    double GetA() const;
    double GetB() const;

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_ELLIPSE_H
