#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "../Quadrilateral.h"

class Rectangle : public Quadrilateral {
private:
    int c;
public:
    Rectangle(int a, int b, int c);
};


#endif //GEOMETRICSHAPES_RECTANGLE_H
