class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y);
    Point(double val);
    Point();

    double get_x() const;
    double get_y() const;

    void set_x(double x);
    void set_y(double y);

    double get_distance_to(Point p) const;
};
