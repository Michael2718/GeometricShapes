#include "Notebook.h"
#include "Rectangle.h"
#include "gtkmm-4.0/gtkmm/entry.h"
#include "gtkmm-4.0/gtkmm/box.h"

void FillRectanglePage(Gtk::Box& rectangle) {
    Gtk::Label label1("Center: ");

    Gtk::Box center;
    Gtk::Label label_x("X: ");
    Gtk::Entry entry_x;
    Gtk::Label label_y("Y: ");
    Gtk::Entry entry_y;
    center.append(label_x);
    center.append(entry_x);
    center.append(label_y);
    center.append(entry_y);

    Gtk::Label label2("Size: ");

    Gtk::Box size;
    Gtk::Label label_width("Width: ");
    Gtk::Entry entry_width;
    Gtk::Label label_height("Height: ");
    Gtk::Entry entry_height;
    size.append(label_width);
    size.append(entry_width);
    size.append(label_height);
    size.append(entry_height);

    rectangle.append(label1);
    rectangle.append(center);
    rectangle.append(label2);
    rectangle.append(size);
}

void FillRhombusPage(Gtk::Box& rhombus) {
    Gtk::Label label1("Center: ");

    Gtk::Box center;
    Gtk::Label label_x("X: ");
    Gtk::Entry entry_x;
    Gtk::Label label_y("Y: ");
    Gtk::Entry entry_y;
    center.append(label_x);
    center.append(entry_x);
    center.append(label_y);
    center.append(entry_y);

    Gtk::Label label2("Diagonals: ");

    Gtk::Box diagonals;
    Gtk::Label label_d1("D1: ");
    Gtk::Entry entry_d1;
    Gtk::Label label_d2("D2: ");
    Gtk::Entry entry_d2;

    diagonals.append(label_d1);
    diagonals.append(entry_d1);
    diagonals.append(label_d2);
    diagonals.append(entry_d2);

    rhombus.append(label1);
    rhombus.append(center);
    rhombus.append(label2);
    rhombus.append(diagonals);
}

void FillTrapezoidPage(Gtk::Box& trapezoid) {
    Gtk::Label label1("P1: ");

    Gtk::Box p1;
    Gtk::Label label1_x("X: ");
    Gtk::Entry entry1_x;
    Gtk::Label label1_y("Y: ");
    Gtk::Entry entry1_y;
    p1.append(label1_x);
    p1.append(entry1_x);
    p1.append(label1_y);
    p1.append(entry1_y);

    Gtk::Label label2("P2: ");

    Gtk::Box p2;
    Gtk::Label label2_x("X: ");
    Gtk::Entry entry2_x;
    Gtk::Label label2_y("Y: ");
    Gtk::Entry entry2_y;
    p2.append(label2_x);
    p2.append(entry2_x);
    p2.append(label2_y);
    p2.append(entry2_y);

    Gtk::Label label3("P3: ");

    Gtk::Box p3;
    Gtk::Label label3_x("X: ");
    Gtk::Entry entry3_x;
    Gtk::Label label3_y("Y: ");
    Gtk::Entry entry3_y;
    p3.append(label3_x);
    p3.append(entry3_x);
    p3.append(label3_y);
    p3.append(entry3_y);

    Gtk::Label label4("P4: ");

    Gtk::Box p4;
    Gtk::Label label4_x("X: ");
    Gtk::Entry entry4_x;
    Gtk::Label label4_y("Y: ");
    Gtk::Entry entry4_y;
    p4.append(label4_x);
    p4.append(entry4_x);
    p4.append(label4_y);
    p4.append(entry4_y);


    trapezoid.append(label1);
    trapezoid.append(p1);
    trapezoid.append(label2);
    trapezoid.append(p2);
    trapezoid.append(label3);
    trapezoid.append(p3);
    trapezoid.append(label4);
    trapezoid.append(p4);
}

void FillTrianglePage(Gtk::Box& triangle) {
    Gtk::Label label1("P1: ");

    Gtk::Box p1;
    Gtk::Label label1_x("X: ");
    Gtk::Entry entry1_x;
    Gtk::Label label1_y("Y: ");
    Gtk::Entry entry1_y;
    p1.append(label1_x);
    p1.append(entry1_x);
    p1.append(label1_y);
    p1.append(entry1_y);

    Gtk::Label label2("P2: ");

    Gtk::Box p2;
    Gtk::Label label2_x("X: ");
    Gtk::Entry entry2_x;
    Gtk::Label label2_y("Y: ");
    Gtk::Entry entry2_y;
    p2.append(label2_x);
    p2.append(entry2_x);
    p2.append(label2_y);
    p2.append(entry2_y);

    Gtk::Label label3("P3: ");

    Gtk::Box p3;
    Gtk::Label label3_x("X: ");
    Gtk::Entry entry3_x;
    Gtk::Label label3_y("Y: ");
    Gtk::Entry entry3_y;
    p3.append(label3_x);
    p3.append(entry3_x);
    p3.append(label3_y);
    p3.append(entry3_y);

    triangle.append(label1);
    triangle.append(p1);
    triangle.append(label2);
    triangle.append(p2);
    triangle.append(label3);
    triangle.append(p3);
}

void FillEllipsePage(Gtk::Box& ellipse) {
    Gtk::Label label1("Center: ");

    Gtk::Box center;
    Gtk::Label label_x("X: ");
    Gtk::Entry entry_x;
    Gtk::Label label_y("Y: ");
    Gtk::Entry entry_y;
    center.append(label_x);
    center.append(entry_x);
    center.append(label_y);
    center.append(entry_y);

    Gtk::Label label2("Size: ");

    Gtk::Label label_a("Semi-major axis 'a': ");
    Gtk::Entry entry_a;
    Gtk::Label label_b("Semi-minor axis 'b': ");
    Gtk::Entry entry_b;

    ellipse.append(label1);
    ellipse.append(center);
    ellipse.append(label2);
    ellipse.append(label_a);
    ellipse.append(entry_a);
    ellipse.append(label_b);
    ellipse.append(entry_b);
}

void FillCirclePage(Gtk::Box& circle) {
    Gtk::Label label1("Center: ");

    Gtk::Box center;
    Gtk::Label label_x("X: ");
    Gtk::Entry entry_x;
    Gtk::Label label_y("Y: ");
    Gtk::Entry entry_y;
    center.append(label_x);
    center.append(entry_x);
    center.append(label_y);
    center.append(entry_y);

    Gtk::Box r;
    Gtk::Label label2("Radius: ");
    Gtk::Entry entry_r;
    r.append(label2);
    r.append(entry_r);

    circle.append(label1);
    circle.append(center);
    circle.append(r);
}

Notebook::Notebook()
    : rectangle(Gtk::Orientation::VERTICAL),
    rhombus(Gtk::Orientation::VERTICAL),
    trapezoid(Gtk::Orientation::VERTICAL),
    triangle(Gtk::Orientation::VERTICAL),
    ellipse(Gtk::Orientation::VERTICAL),
    circle(Gtk::Orientation::VERTICAL) {
    set_tab_pos(Gtk::PositionType::RIGHT);
    set_size_request(466, 768);

    append_page(complex_shape, "ComplexShape");
    append_page(simple_polygon, "SimplePolygon");
    append_page(rectangle, "Rectangle");
    append_page(rhombus, "Rhombus");
    append_page(trapezoid, "Trapezoid");
    append_page(triangle, "Triangle");
    append_page(ellipse, "Ellipse");
    append_page(circle, "Circle");

    FillRectanglePage(rectangle);
    FillRhombusPage(rhombus);
    FillTrapezoidPage(trapezoid);
    FillTrianglePage(triangle);
    FillEllipsePage(ellipse);
    FillCirclePage(circle);
}
