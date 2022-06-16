#ifndef GEOMETRICSHAPES_WIDGET_H
#define GEOMETRICSHAPES_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <AbstractShape.h>

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(std::vector<AbstractShape *> shape_list, QWidget *parent = nullptr);
    ~Widget() override = default;
protected:
    void PaintShapes(QPainter* painter);
    void PaintShape(AbstractShape *shape, QPainter* painter);
    void paintEvent(QPaintEvent *event) override;
private:
    std::vector<AbstractShape *> shape_list;
    //Ui::Widget *ui;
};

#endif //GEOMETRICSHAPES_WIDGET_H
