#ifndef GEOMETRICSHAPES_COMPLEXSHAPE_H
#define GEOMETRICSHAPES_COMPLEXSHAPE_H

#include "AbstractShape.h"
#include "Point.h"
#include <vector>
#include <string>

class ComplexShape : public AbstractShape {
private:
    std::vector<AbstractShape*> shapes;
    Point center;
public:
    explicit ComplexShape(const std::vector<AbstractShape*> &shapes);

    Point GetCenter() const override {return center;}
    std::vector<AbstractShape*> GetShapes() const override {return shapes;}

    void Scale(double k) override;
    void Rotate(double angle) override;
    void Rotate(Point r_center, double angle) override;
    void Translate(double dx, double dy) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};


#endif //GEOMETRICSHAPES_COMPLEXSHAPE_H
