#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "../Point.h"

class AbstractEllipse {
private:
    Point center;
public:
    explicit AbstractEllipse(Point center);
    virtual double Area() const = 0;
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
