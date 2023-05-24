#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Character.hpp"

using namespace std;

constexpr int YOUNG_NINJA_HP = 100;
constexpr int YOUNG_NINJA_SPEED = 14;
constexpr int TRAINED_NINJA_HP = 120;
constexpr int TRAINED_NINJA_SPEED = 12;
constexpr int OLD_NINJA_HP = 150;
constexpr int OLD_NINJA_SPEED = 8;

class Ninja : public Character
{
    int speed;

public:
    Ninja(string name, const Point &location, int life, int speed);

    void slash(Character *enemy);
    void move(const Character *enemy);
    void attack(Character *enemy) override;
    string print() override;
    string getFigure() override
    {
        return "Ninja";
    }
};


