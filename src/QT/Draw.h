#include <QApplication>
#include "Widget.h"
#include "AbstractShape.h"

int Draw(int argc, char *argv[], const std::vector<AbstractShape *>& shape_list) {
    QApplication a(argc, argv);

    Widget w(shape_list);
    w.setAutoFillBackground(true);
    w.setStyleSheet("background-color:white");
    w.setFixedSize(800, 800);
    w.show();

    return QApplication::exec();
}
