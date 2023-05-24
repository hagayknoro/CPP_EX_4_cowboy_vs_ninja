#pragma once
#include "Team.hpp"
#include <vector>
#include <string>
#include <istream>

using namespace std;

class SmartTeam:public Team 
{
public:
  //constrctors
  SmartTeam(Character *commander);

  //class unique function
  void attack(Team *other);
  void print();
};