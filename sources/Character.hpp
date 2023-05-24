#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

class Character
{
    Point location;
    string name;
    string Degree;
    int life;
    bool TeeMember;

public:
    Character(string, const Point &, int life);
    Character(const Character &) = default;
    Character(Character &&) = default;
    virtual ~Character() = default;

    virtual void attack(Character *enemy) = 0;
    bool isAlive();
    double distance(Character *);
    void hit(int hurt);
    virtual string print() = 0;

    Character &operator=(const Character &) = default;
    Character &operator=(Character &&) = default;

    string getName();
    Point getLocation() const;
    void setLocation(Point);
    int getLife();
    bool getTeeMember();
    bool setTeeMember();
    virtual string getFigure() = 0;

};