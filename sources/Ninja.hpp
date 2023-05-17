#pragma once
#include "Character.hpp"

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
    void move(const Character *enemy);
    void slash(Character *enemy);
};

class YoungNinja : public Ninja {

public:
  YoungNinja(string name, const Point &location):
    Ninja(std::move(name), location, YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) 
    {

    }
};

class TrainedNinja : public Ninja {

public:
  TrainedNinja(string name, const Point &location):
    Ninja(std::move(name), location, TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) 
    {

    }
};

class OldNinja : public Ninja {

public:
  OldNinja(string name, const Point &location):
    Ninja(std::move(name), location, OLD_NINJA_HP, OLD_NINJA_SPEED) 
    {
        
    }
};
