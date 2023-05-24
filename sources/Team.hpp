#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

const int TEAM_SIZE = 10;
class Team 
{
  Character *commander;
  vector<Character *> team;

public:
  //constrctors
  Team(const Team& other) = default;
  Team(Character *commander);
  Team(Team&& other) = default;
  //operators overloding
  Team& operator=(const Team& other) = default;
  Team& operator=(Team&& other) = default;
  
  //class function and deconstractor
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  Character *findFarestFigure(Character *figure, Team * team);
  Character *findClosestFigure(Team *team);
  Character *findClosestFigureSmart(Character *figure, Team team);
  Character *getCommander();
  void setCommander(Character *newCommander);
  vector<Character *> *getTeam();

  virtual ~Team();
};

namespace ariel {};