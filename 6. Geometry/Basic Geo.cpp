///2D point class
struct pt {
    double x, y;

    pt() {}
    pt(double x, double y) : x(x), y(y) {}
};

/* https://cp-algorithms.com/geometry/oriented-triangle-area.html
   ccw = +ve, cw = -ve, linear = 0 */
double orient(pt a, pt b, pt c)
{
    return a.x * (b.y-c.y) + b.x * (c.y-a.y) + c.x * (a.y-b.y);
}
