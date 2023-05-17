#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>

class Team {
  Character *commander;
  vector<Character *> team;

public:
  //constrctors
  Team(const Team& other);
  Team(Character *commander);
  Team(Team&& other)noexcept;
  //operators overloding
  Team& operator=(const Team& other);
  Team& operator=( Team&& other)noexcept;
  //class function and deconstractor
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~Team();
};

namespace ariel {};