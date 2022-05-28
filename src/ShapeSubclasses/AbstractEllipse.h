#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "../AbstractShape.h"
#include "../Point.h"

class AbstractEllipse : public AbstractShape {
private:
    Point center;
public:
    AbstractEllipse(unsigned int id, Point center);

    double Perimeter() const override = 0;
    double Area() const override = 0;
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
