#include "Team2.hpp"
#include "Character.hpp"
#include <vector>

  Team2::Team2(const Team2& other):
    Team(other), commander(other.commander)
  {

  }

  Team2::Team2(Character *commander):
    Team(commander),commander(commander)
  {
    team.push_back(commander);
  }

  Team2::Team2(Team2&& other)noexcept:
    Team(other)
  {
  commander = other.commander;
  team = other.team;
  }

  //operators overloding
Team2 &Team2::operator=(const Team2 &other) {
  commander = other.commander;
  team = other.team;
  return *this;
}

Team2 &Team2::operator=( Team2 &&other) noexcept{
  commander = other.commander;
  team = other.team;
  return *this;
}

  //class function and deconstractor
  void Team2::add(Character *member)
  {

  }
  void Team2::attack(Team *other)
  {

  }
  int Team2::stillAlive()
  {
    return 0;
  }
  void Team2::print()
  {

  }
  Team2::~Team2(){}
