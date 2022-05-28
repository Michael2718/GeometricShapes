#ifndef GEOMETRICSHAPES_ABSTRACTSHAPE_H
#define GEOMETRICSHAPES_ABSTRACTSHAPE_H

class AbstractShape {
private:
    unsigned int id;
public:
    AbstractShape();
    explicit AbstractShape(unsigned int id);

    unsigned int GetId() const {return id;}

    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTSHAPE_H
