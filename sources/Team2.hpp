#pragma once
#include "Team.hpp"
#include <vector>

class Team2:public Team {
  Character *commander;
  vector<Character *> team;

public:
  //constrctors
  Team2(const Team2& other);
  Team2(Character *commander);
  Team2(Team2&& other)noexcept;
  //operators overloding
  Team2& operator=(const Team2& other);
  Team2& operator=( Team2&& other)noexcept;
  //class function and deconstractor
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~Team2();
};

namespace ariel {};