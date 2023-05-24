#pragma once
#include "Team.hpp"
#include <vector>
#include <string>
#include <istream>

using namespace std;

class Team2:public Team 
{
public:
  //constrctors
  Team2(Character *commander);

  //class unique function
  void attack(Team *other);
  void print();
};

