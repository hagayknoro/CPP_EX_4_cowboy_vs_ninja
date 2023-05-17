#pragma once
#include "Team.hpp"
#include <vector>

class SmartTeam : public Team {
  Character *commander;
  vector<Character *> team;

public:
  //constrctors
  SmartTeam(const SmartTeam &other);
  SmartTeam(Character *commander);
  SmartTeam(SmartTeam &&other) noexcept;
  //operators overloding
  SmartTeam &operator=(const SmartTeam &other);
  SmartTeam &operator=(SmartTeam &&other) noexcept;
  //class function and deconstractor
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~SmartTeam();
};

namespace ariel {};