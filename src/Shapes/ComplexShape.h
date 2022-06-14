#ifndef GEOMETRICSHAPES_COMPLEXSHAPE_H
#define GEOMETRICSHAPES_COMPLEXSHAPE_H

#include "AbstractShape.h"
#include "Point.h"
#include <vector>

class ComplexShape : public AbstractShape {
private:
    std::vector<AbstractShape*> shapes;
    Point center;
public:
    explicit ComplexShape(unsigned int id, const std::vector<AbstractShape*> &shapes);

    std::vector<AbstractShape*> GetShapes() const {return shapes;}
    Point GetCenter() const override {return center;}

    void Scale(double k) override;
    void Rotate(double angle) override;
    void Translate(double dx, double dy) override;

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_COMPLEXSHAPE_H
