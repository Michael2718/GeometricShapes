#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "../AbstractShape.h"
#include "../Point.h"

class AbstractEllipse : public AbstractShape {
private:
    Point center;
public:
    AbstractEllipse(unsigned int id, Point center);

    Point GetCenter() const {return center;}
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
