#pragma once
#include "Character.hpp"

class Cowboy : public Character
{
    int raunds;

public:
    Cowboy(string name, const Point &location);
    void shoot(Character* );
    bool hasboolets();
    void reload();
};

