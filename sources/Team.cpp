#include "Team.hpp"
#include "Character.hpp"
#include <vector>

  Team::Team(const Team& other):
    commander(other.commander)
  {

  }

  Team::Team(Character *commander):
    commander(commander)
  {
    team.push_back(commander);
  }

  Team::Team(Team&& other)noexcept
  {
  commander = other.commander;
  team = other.team;
  }

  //operators overloding
Team &Team::operator=(const Team &other) {
  commander = other.commander;
  team = other.team;
  return *this;
}

Team &Team::operator=( Team &&other) noexcept{
  commander = other.commander;
  team = other.team;
  return *this;
}

  //class function and deconstractor
  void Team::add(Character *member)
  {

  }
  void Team::attack(Team *other)
  {

  }
  int Team::stillAlive()
  {
    return 0;
  }
  void Team::print()
  {

  }
  Team::~Team(){}
