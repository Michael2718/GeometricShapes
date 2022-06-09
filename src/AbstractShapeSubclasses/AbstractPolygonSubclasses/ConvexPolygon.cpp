#include "ConvexPolygon.h"
#include <stdexcept>
#include <cmath>

using std::invalid_argument, std::vector;

bool isConvex(const vector<Point>& points) {
    size_t n = points.size();
    double x1, y1, x2, y2; // Coordinates of vectors (x1, y1) and (x2, y2)
    bool positive = false, negative = false;
    for (int i = 0; i < points.size(); i++) {
        x1 = (points[(i+1)%n].X()-points[i%n].X());
        y1 = (points[(i+1)%n].Y()-points[i%n].Y());
        x2 = (points[(i+2)%n].X()-points[(i+1)%n].X());
        y2 = (points[(i+2)%n].Y()-points[(i+1)%n].Y());
        if(x1*y2 - y1*x2 > 0) {
            positive = true;
        } else if (x1*y2 - y1*x2 < 0) {
            negative = true;
        }
    }
    return !(positive && negative);
}

double AreaOfTriangle(Point p1, Point p2, Point p3) {
    return 0.5*std::abs(p1.X()*(p2.Y() - p3.Y()) +
                           p2.X()*(p3.Y() - p1.Y()) +
                           p3.X()*(p1.Y() - p2.Y()));
}

Point CalculateCenter(const vector<Point>& points) {
    unsigned int n = points.size();
    double center_x = 0, center_y = 0;
    for (auto point: points) {center_x += point.X(); center_y += point.Y();}
    return {center_x/n, center_y/n};
}
ConvexPolygon::ConvexPolygon(unsigned int id, const vector<Point>& points)
    : AbstractPolygon(id, points.size()), vertices(points),
    center(CalculateCenter(points)) {
    if (vertices.size() < 3) throw invalid_argument("Invalid Polygon size.");
    for (int i = 0; i < points.size()-1; i++) {
        for (int j = i+1; j < points.size(); j++) {
            if (points[i] == points[j]) throw invalid_argument("Invalid Points.");
        }
    }
    //if (!isConvex(points)) throw invalid_argument("Invalid Points.");
}

void ConvexPolygon::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    vector<Point> new_vertices;
    for (auto point: GetVertices()) {
        new_vertices.emplace_back(k*point.X()+(1-k)*center.X(),
                                k*point.Y()+(1-k)*center.Y());
    }
    SetPoints(new_vertices);
}

void ConvexPolygon::Rotate(double angle) {
    vector<Point> new_vertices;
    double r_angle = angle * (M_PI / 180.0);
    double new_x, new_y;
    for (auto point: GetVertices()) {
        new_x = center.X() + (point.X()-center.X())*cos(r_angle) + (point.Y()-center.Y())*sin(r_angle);
        new_y = center.Y() - (point.X()-center.X())*sin(r_angle) + (point.Y()-center.Y())*cos(r_angle);
        new_vertices.emplace_back(new_x, new_y);
    }
    SetPoints(new_vertices);
}

double ConvexPolygon::Perimeter() const {
    double perimeter = 0;
    unsigned int n = GetVertexCount();
    for(int i = 0; i < n; i++) {
        perimeter += sqrt(pow(vertices[i%n].X()-vertices[(i+1)%n].X(),2) +
                             pow(vertices[i%n].Y()-vertices[(i+1)%n].Y(),2));
    }
    return perimeter;
}

double ConvexPolygon::Area() const {
    double area = 0;
    unsigned int n = GetVertexCount();
    for(int i = 0; i < n; i++) {
        area += AreaOfTriangle(vertices[i%n], vertices[(i+1)%n], center);
    }
    return area;
}

void ConvexPolygon::SetPoints(const std::vector<Point> &new_vertices) {
    vertices = new_vertices;
}
