#pragma once
#include <iostream>
#include <string>

class Point
{
    double xAxis;
    double yAxis;

public:
    Point(double,double);
    double distance(const Point&);
    void print();
    static Point moveTowards(Point,Point,double);

};