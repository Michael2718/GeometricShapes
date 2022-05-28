#ifndef GEOMETRICSHAPES_ABSTRACTSHAPE_H
#define GEOMETRICSHAPES_ABSTRACTSHAPE_H

class Shape {
private:
    unsigned int id;
public:
    Shape();
    Shape(unsigned int id);

    unsigned int getId() const {return id;}

    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTSHAPE_H
