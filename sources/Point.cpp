#include "Point.hpp"


Point::Point(double xAxis, double yAxis):
    xAxis(xAxis), yAxis(yAxis)
{
}

double Point::distance(const Point &other)
{
    return sqrt(pow(xAxis - other.xAxis, 2) + pow(yAxis - other.yAxis, 2));
}

string Point::print()
{
    return "(" + to_string(this->xAxis) + "," + to_string(this->yAxis);
}

Point Point::moveTowards(Point sec, Point dst, double dist)
{
    if(dist == 0)
        return sec;
    if (sec.distance(dst) <= dist)
    return dst;
    if (dist < 0)
            throw invalid_argument("distance should be positive");
      
    double dx = dst.xAxis - sec.xAxis;
    double dy = dst.yAxis - sec.yAxis;
    double scale = dist / sec.distance(dst);
    return Point(sec.xAxis + scale * dx, sec.yAxis + scale * dy);
}