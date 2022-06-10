#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      render_area(new RenderArea) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

