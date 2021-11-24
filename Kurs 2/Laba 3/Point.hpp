#include <cmath>


#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;
public:
    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {}

    double get_x() const {return x;}
    double get_y() const {return y;}

    void set_x(double x) {this->x = x;}
    void set_y(double y) {this->y = y;}
    void set(double x, double y) {set_x(x); set_y(y);}

    double get_distance_to(Point p) const;
};

double Point::get_distance_to(Point p) const {
    return sqrt(pow(x - p.get_x(), 2) + pow(y - p.get_y(), 2));
}

#endif