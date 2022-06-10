#include "ShapeFactory.h"
#include <utility>
#include <stdexcept>
#include <vector>

using std::vector, std::move, std::invalid_argument;

ShapeFactory::ShapeFactory() : shapes(vector<AbstractShape*>()), quantity(0) {}

ShapeFactory::ShapeFactory(const std::vector<AbstractShape*>& shapes)
    : shapes(shapes), quantity(shapes.size()) {
    for (int i = 0; i < quantity-1; i++) {
        for (int j = i+1; j < quantity; j++) {
            if (this->shapes[i]->GetId() == this->shapes[j]->GetId()) {
                throw invalid_argument("Invalid shape id. Shape id must be unique.");
            }
        }
    }
}

ShapeFactory::~ShapeFactory() {
    for (auto & shape: shapes) {
        delete shape;
    }
    shapes.clear();
}

void ShapeFactory::AddShape(AbstractShape *new_shape) {
    for (auto shape: shapes) {
        if (shape->GetId() == new_shape->GetId()) {
            throw invalid_argument("Invalid shape id. Shape id must be unique.");
        }
    }
    shapes.push_back(new_shape);
    quantity++;
}

void ShapeFactory::RemoveShape(unsigned int position) {
    if (position >= quantity) throw invalid_argument("Invalid removed shaped position.");
    delete shapes[position];
    shapes.erase(shapes.begin()+position);
    quantity--;
}
