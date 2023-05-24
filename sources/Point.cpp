#include "Point.hpp"


Point::Point(double xAxis, double yAxis):
    xAxis(xAxis), yAxis(yAxis)
{
}

double Point::distance(const Point &other)
{
    return sqrt(pow(xAxis - other.xAxis , 2) + pow(yAxis - other.yAxis , 2));
}

string Point::print()
{
    return "(" + to_string(this->xAxis) + "," + to_string(this->yAxis);
}

Point Point::moveTowards(Point sec, Point dst, double dist)
{
    if(dist == 0)
        return sec;
    else if (dist < 0)
        throw invalid_argument("It's impossebol to go negativ distans");
    
    double askedDist = sec.distance(dst);
    //make shoor the point is reachable
    if(askedDist <= dist)
        return dst;
    else
    {
        // github.com/erich666/GraphicsGems/blob/master/gems/NearestPoint.c - refrensed by Yogev Ofir
        double x1 = sec.xAxis;
        double y1 = sec.yAxis;
        double x2 = dst.xAxis;
        double y2 = dst.yAxis;
        double x3 = x1 + (dist * (x2 - x1) / sec.distance(dst));
        double y3 = y1 + (dist * (y2 - y1) / sec.distance(dst));
        return Point(x3, y3);
    }
    
}