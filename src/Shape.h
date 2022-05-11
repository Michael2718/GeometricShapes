#ifndef GEOMETRICSHAPES_SHAPE_H
#define GEOMETRICSHAPES_SHAPE_H

class Shape {
private:
    unsigned int id;
    double x, y;
public:
    Shape(unsigned int id, double x, double y);
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

#endif //GEOMETRICSHAPES_SHAPE_H
