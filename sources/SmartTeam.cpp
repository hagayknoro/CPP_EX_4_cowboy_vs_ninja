#include "SmartTeam.hpp"
#include "Character.hpp"

  SmartTeam::SmartTeam(Character *commander):
    Team(commander)
  {
  }


 //class unique function
  void SmartTeam::attack(Team *other)
  {
    if(!other)
      throw invalid_argument("You have to get am enmmy for attack\n");
    if(other->stillAlive() == 0)
      return;
    setCommander(findClosestFigure(this));
    Character *target = findClosestFigure(other);
    for(Character *member : *this->getTeam())
    {
      if(member->getFigure() == "Ninja")
      {
        Character *target = findClosestFigureSmart(member, other);
          if(!target->isAlive())
          {
            target = findClosestFigureSmart(member, other);
            if(!target)
              return;
          }
      member->attack(target);
    }
    else if(member->getFigure() == "Cowboy")
      {
        Character *target = findFarestFigure(member, other);
          if(!target->isAlive())
          {
            target = findFarestFigure(member, other);
            if(!target)
              return;
          }
      member->attack(target);
    }
  }
  }

  void SmartTeam::print()
  {
    for(Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
  }
