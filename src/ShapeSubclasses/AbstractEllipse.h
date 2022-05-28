#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "../AbstractShape.h"
#include "../Point.h"

class AbstractEllipse : public AbstractShape {
private:
    Point center;
public:
    explicit AbstractEllipse(unsigned int id, Point center);

    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
