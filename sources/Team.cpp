#include "Team.hpp"
#include "Character.hpp"
#include <vector>


  Team::Team(Character *commander):
    commander(commander)
  {
    //make shore the commander isn't part of a team.
    if(commander->getTeeMember())
      throw runtime_error("This commander is allready taken\n");
    team.push_back(commander);
    commander->setTeeMember();
  }


  //operators overloding
Team &Team::operator=(const Team &other) {
  commander = other.commander;
  team = other.team;
  return *this;
}

Team &Team::operator=(Team &&other) noexcept{
  commander = other.commander;
  team = other.team;
  return *this;
}

  //class function and deconstractor
  void Team::add(Character *member)
  {
    if(team.size() == 10 || member->getTeeMember())
      throw runtime_error("Team limit is ten figurs or the figure us allready part of a team\n");
    team.push_back(member);
    member->setTeeMember();
  }

  void Team::attack(Team *other)
  {
    if(!other)
      throw invalid_argument("You have to get am enmmy for attack\n");
    if(other->stillAlive() == 0 || this->stillAlive() == 0)
      throw runtime_error("One of the involved team is all ded");
    if(this == other)
      throw runtime_error("This is not the place for suicidal tendencies, we are in the middle of battle\n");
    if(this->commander->isAlive() == 0)
      this->commander = findClosestFigure(this);
    
    Character *target = findClosestFigure(other);
    for(Character *member : team)
    {
      if(member->getFigure() ==  "Cowboy")
      {
        if(!target->isAlive())
        {
          target = findClosestFigure(other);
          if(target == nullptr)
            return;
        }
        member->attack(target);
      }
      else
        continue;
    }
    for(Character *member : team)
    {
      if(member->getFigure() ==  "Ninja")
      {
        if(!target->isAlive())
        {
          target = findClosestFigure(other);
          if(target == nullptr)
            return;
        }
        member->attack(target);
      }
      else
        continue;
    }
  
  }

  int Team::stillAlive()
  {
    int inGeam = 0;
    for(Character *member : team)
    {
      if(member->isAlive())
      inGeam++;
    }
    return inGeam;
  }

  void Team::print()
  {
    for(Character *member : team)
    {
      if(member->getFigure() ==  "Cowboy")
      {
        cout << member->print() << endl;
      }
    }
    for(Character *member : team)
    {
      if(member->getFigure() ==  "Ninja")
      {
        cout << member->print() << endl;
      }
    }
    cout <<endl;
  }


Character *Team::findFarestFigure(Character *figure, Team * team)
{
  Character *findedFigure = nullptr;
  double findeDst = __DBL_MIN__;

  for(Character *member : team->team)
  {
    if(member->isAlive() && figure->distance(member) > findeDst)
    {
      findeDst = figure->distance(member);
      findedFigure = member;
    }
  }
return findedFigure;
}

Character *Team::findClosestFigure(Team *team)
{
  Character *findedFigure = nullptr;
  double findeDst = __DBL_MAX__;

  for(Character *member : team->team)
  {
    if(member->isAlive() && this->commander->distance(member) < findeDst)
    {
      findeDst = this->commander->distance(member);
      findedFigure = member;
    }
  }
return findedFigure;
}

Character *Team::findClosestFigureSmart(Character *figure, Team *team)
{
  Character *findedFigure = nullptr;
  double findeDst = __DBL_MAX__;

  for(Character *member : team->team)
  {
    if(member->isAlive() && figure->distance(member) < findeDst)
    {
      findeDst = figure->distance(member);
      findedFigure = member;
    }
  }
return findedFigure;
}

Character *Team::getCommander()
{
  return this->commander;
}

void Team::setCommander(Character *newCommander)
{
  this->commander = newCommander;
}

vector<Character *> *Team::getTeam()
{
  return &team;
}

  Team::~Team()
  {
    for(Character *member : team)
    {
      delete member;
    }
  }