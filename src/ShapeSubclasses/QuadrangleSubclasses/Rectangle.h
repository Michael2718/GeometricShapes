#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "../../Shape.h"

class Rectangle : public Shape {
private:
    int c;
public:
    Rectangle(int a, int b, int c);
};


#endif //GEOMETRICSHAPES_RECTANGLE_H
