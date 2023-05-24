#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Point
{
    double xAxis;
    double yAxis;

public:
    Point(double xAxis,double yAxis);
    double distance(const Point&);
    string print();
    static Point moveTowards(Point,Point,double);

};