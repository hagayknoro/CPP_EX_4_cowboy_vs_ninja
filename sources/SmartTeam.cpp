#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>

SmartTeam::SmartTeam(const SmartTeam &other)
    : Team(other), commander(other.commander) {}

SmartTeam::SmartTeam(Character *commander) : Team(commander), commander(commander) {
  team.push_back(commander);
}

SmartTeam::SmartTeam(SmartTeam &&other) noexcept : Team(other) {
  commander = other.commander;
  team = other.team;
}

SmartTeam &SmartTeam::operator=(const SmartTeam &other) {
  commander = other.commander;
  team = other.team;
  return *this;
}

SmartTeam &SmartTeam::operator=(SmartTeam &&other) noexcept {
  commander = other.commander;
  team = other.team;
  return *this;
}

void SmartTeam::add(Character *member) {

}

void SmartTeam::attack(Team *other) 
{

}

int SmartTeam::stillAlive() 
{ 
    return 0; 
}

void SmartTeam::print() 
{

}

SmartTeam::~SmartTeam() 
{
    
}