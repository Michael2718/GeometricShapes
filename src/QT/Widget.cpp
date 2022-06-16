#include "Widget.h"

#include "AbstractShape.h"
#include "Point.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapezoid.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Circle.h"
#include "ComplexShape.h"

#include <utility>
#include <vector>
#include <QPainterPath>

Widget::Widget(std::vector<AbstractShape *> shape_list, QWidget *parent)
    : QWidget(parent), shape_list(std::move(shape_list)) {
}

void Widget::PaintShapes(QPainter* painter) {
    for (auto shape: shape_list) {
        PaintShape(shape, painter);
    }
}

void Widget::PaintShape(AbstractShape *shape, QPainter* painter) {
    std::vector<Point> rectangle_points;
    QVector<QPointF> rectangle_q_points;
    QPolygonF rectangle;

    int simple_polygon_vertex_count;
    std::vector<Point> simple_polygon_points;
    QVector<QPointF> simple_polygon_q_points;
    QPolygonF simple_polygon;

    std::vector<Point> rhombus_points;
    QVector<QPointF> rhombus_q_points;
    QPolygonF rhombus;

    std::vector<Point> trapezoid_points;
    QVector<QPointF> trapezoid_q_points;
    QPolygonF trapezoid;

    std::vector<Point> triangle_points;
    QVector<QPointF> triangle_q_points;
    QPolygonF triangle;

    Point center;
    QPointF q_center;
    double a, b, r;

    switch (shape->GetId()) {
        case SIMPLE_POLYGON:
            simple_polygon_vertex_count = dynamic_cast<SimplePolygon*>(shape)->GetVertexCount();
            simple_polygon_points = dynamic_cast<SimplePolygon*>(shape)->GetVertices();
            simple_polygon_q_points = QVector<QPointF>(simple_polygon_vertex_count);

            for (int i = 0; i < simple_polygon_vertex_count; i++) {
                simple_polygon_q_points[i].setX(simple_polygon_points[i].X());
                simple_polygon_q_points[i].setY(simple_polygon_points[i].Y());
            }

            simple_polygon = QPolygonF(simple_polygon_q_points);
            painter->drawPolyline(simple_polygon);
            painter->drawLine(simple_polygon_q_points[simple_polygon_vertex_count-1],
                              simple_polygon_q_points[0]);
            break;
        case RECTANGLE:
            rectangle_points = dynamic_cast<Rectangle*>(shape)->GetPoints();
            rectangle_q_points = QVector<QPointF>(4);

            for (int i = 0; i < 4; i++) {
                rectangle_q_points[i].setX(rectangle_points[i].X());
                rectangle_q_points[i].setY(rectangle_points[i].Y());
            }

            rectangle = QPolygonF(rectangle_q_points);
            painter->drawPolyline(rectangle);
            painter->drawLine(rectangle_q_points[3],
                              rectangle_q_points[0]);
            break;
        case RHOMBUS:
            rhombus_points = dynamic_cast<Rhombus*>(shape)->GetPoints();
            rhombus_q_points = QVector<QPointF>(4);

            for (int i = 0; i < 4; i++) {
                rhombus_q_points[i].setX(rhombus_points[i].X());
                rhombus_q_points[i].setY(rhombus_points[i].Y());
            }

            rhombus = QPolygonF(rhombus_q_points);
            painter->drawPolyline(rhombus);
            painter->drawLine(rhombus_q_points[3],
                              rhombus_q_points[0]);
            break;
        case TRAPEZOID:
            trapezoid_points = dynamic_cast<Trapezoid*>(shape)->GetPoints();
            trapezoid_q_points = QVector<QPointF>(4);

            for (int i = 0; i < 4; i++) {
                trapezoid_q_points[i].setX(trapezoid_points[i].X());
                trapezoid_q_points[i].setY(trapezoid_points[i].Y());
            }

            trapezoid = QPolygonF(trapezoid_q_points);
            painter->drawPolyline(trapezoid);
            painter->drawLine(trapezoid_q_points[3],
                              trapezoid_q_points[0]);
            break;
        case TRIANGLE:
            triangle_points = dynamic_cast<Triangle*>(shape)->GetPoints();
            triangle_q_points = QVector<QPointF>(3);

            for (int i = 0; i < 3; i++) {
                triangle_q_points[i].setX(triangle_points[i].X());
                triangle_q_points[i].setY(triangle_points[i].Y());
            }

            triangle = QPolygonF(triangle_q_points);
            painter->drawPolyline(triangle);
            painter->drawLine(triangle_q_points[2],
                              triangle_q_points[0]);
            break;
        case ELLIPSE:
            center = shape->GetCenter();
            q_center.setX(center.X());
            q_center.setY(center.Y());

            a = dynamic_cast<Ellipse*>(shape)->GetA();
            b = dynamic_cast<Ellipse*>(shape)->GetB();
            painter->rotate(dynamic_cast<Ellipse*>(shape)->GetRotationAngle());
            painter->drawEllipse(q_center, a, b);
            painter->rotate(-dynamic_cast<Ellipse*>(shape)->GetRotationAngle());
            break;
        case CIRCLE:
            center = shape->GetCenter();
            q_center.setX(center.X());
            q_center.setY(center.Y());

            r = dynamic_cast<Circle*>(shape)->GetRadius();
            painter->drawEllipse(q_center, r, r);
            break;
        case COMPLEX_SHAPE:
            for (auto cs_shape: dynamic_cast<ComplexShape*>(shape)->GetShapes()) {
                PaintShape(cs_shape, painter);
            }
            break;
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    QPainter painter(this);
    painter.translate(QWidget::width()/2.0, QWidget::height()/2.0);
    painter.scale(40, -40);
    QPen pen(Qt::black, 0.05);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    PaintShapes(&painter);
    //painter.drawEllipse(0, 0, 6, 4);

    //PaintShapes(shape_list, &painter);
}
