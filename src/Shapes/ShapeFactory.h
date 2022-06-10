#ifndef GEOMETRICSHAPES_SHAPEFACTORY_H
#define GEOMETRICSHAPES_SHAPEFACTORY_H

#include "AbstractShape.h"
#include <vector>

class ShapeFactory {
private:
    std::vector<AbstractShape*> shapes;
    unsigned int quantity;
public:
    ShapeFactory();
    explicit ShapeFactory(const std::vector<AbstractShape*>& shapes);

    ~ShapeFactory();

    std::vector<AbstractShape*> GetShapes() const {return shapes;}
    unsigned int GetQuantity() const {return quantity;}

    void AddShape(AbstractShape* new_shape);
    void RemoveShape(unsigned int position);
};


#endif //GEOMETRICSHAPES_SHAPEFACTORY_H
