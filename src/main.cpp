#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <iostream>

using std::cout, std::cin;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qDebug() << "Hello world";
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
