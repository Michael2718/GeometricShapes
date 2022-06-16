#include "SimplePolygon.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath>

using std::invalid_argument, std::vector, std::string, std::ostringstream;

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

bool ccw(Point a, Point b, Point c) {
    return (b.X() - a.X()) * (c.Y() - a.Y()) > (c.X() - a.X()) * (b.Y() - a.Y());
}

bool isSegmentsIntersect(Point a1, Point a2, Point b1, Point b2) {
    if (a2 == b1 || a1 == b2) return false;
    return ccw(a1, b1, b2) != ccw(a2, b1, b2) &&
           ccw(a1, a2, b1) != ccw(a1, a2, b2);
}

bool isPolygonSelfIntersecting(const std::vector<Point>& points) {
    unsigned int n = points.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if(isSegmentsIntersect(points[i], points[i+1],
                                   points[j], points[(j+1)%n])) return true;
        }
    }
    return false;
}

SimplePolygon::SimplePolygon(const vector<Point>& points)
    : AbstractPolygon(SIMPLE_POLYGON, (int)points.size()), vertices(points),
    center(CalculateCenter(points)) {
    if (vertices.size() < 3) throw invalid_argument("Invalid Polygon size.");
    for (int i = 0; i < points.size()-1; i++) {
        for (int j = i+1; j < points.size(); j++) {
            if (points[i] == points[j]) throw invalid_argument("Invalid Points.");
        }
    }
    if (isPolygonSelfIntersecting(points)) throw invalid_argument("Invalid Points.");
}

void SimplePolygon::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    vector<Point> new_vertices;
    for (auto point: GetVertices()) {
        new_vertices.emplace_back(k*point.X()+(1-k)*center.X(),
                                  k*point.Y()+(1-k)*center.Y());
    }
    SetVertices(new_vertices);
}

void SimplePolygon::Rotate(double angle) {
    vector<Point> new_vertices;
    for (auto point: GetVertices()) {
        new_vertices.emplace_back(point.Rotate(center, angle));
    }
    SetVertices(new_vertices);
}

void SimplePolygon::Rotate(Point r_center, double angle) {
    vector<Point> new_vertices;
    for (auto point: GetVertices()) {
        new_vertices.emplace_back(point.Rotate(r_center, angle));
    }
    SetVertices(new_vertices);
}

void SimplePolygon::Translate(double dx, double dy) {
    for (auto vertex: vertices) vertex.Translate(dx, dy);
    center.Translate(dx, dy);
}

double SimplePolygon::Perimeter() const {
    double perimeter = 0;
    unsigned int n = GetVertexCount();
    for(int i = 0; i < n; i++) {
        perimeter += sqrt(pow(vertices[i%n].X()-vertices[(i+1)%n].X(),2) +
                             pow(vertices[i%n].Y()-vertices[(i+1)%n].Y(),2));
    }
    return perimeter;
}

double SimplePolygon::Area() const {
    double area = 0;
    unsigned int n = GetVertexCount();
    for(int i = 0; i < n; i++) {
        area += vertices[i].X()*vertices[(i+1)%n].Y();
        area -= vertices[(i+1)%n].X()*vertices[i].Y();
    }
    return std::abs(area/2);
}

string SimplePolygon::Info() const {
    ostringstream oss;

    oss << "Simple Polygon Info: " << "\n"
        << AbstractPolygon::Info() << "\n";

    oss << "Vertices: ";
    for (auto vertex: vertices) oss << vertex << " ";
    oss << "\n";

    oss << "Center: " << center << "\n"
        << "Perimeter: " << Perimeter() << "\n"
        << "Area: " << Area();

    return oss.str();
}

void SimplePolygon::SetVertices(const std::vector<Point> &new_vertices) {
    vertices = new_vertices;
}
