#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Character.hpp"

using namespace std;

class Cowboy : public Character
{
    int raunds;

public:
    Cowboy(string name, const Point &location);

    void shoot(Character* );
    bool hasboolets();
    void reload();
    string print() override;
    void attack(Character *enemy) override;
    
    string getFigure() override
    {
        return "Cowboy";
    }

};

