#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

class Character
{
    Point location;
    string name;
    int life;

public:
    Character(string, const Point &, int);
    bool isAlive();
    double distance(const Character &);
    void hit(int);
    string getName();
    Point getLocation();
    string print();
    int getLife();
};