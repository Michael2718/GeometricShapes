#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <iostream>
#include "Shape.h"

using std::cout, std::cin;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Shape shape(0, 1);
    qDebug() << shape.GetA();
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
