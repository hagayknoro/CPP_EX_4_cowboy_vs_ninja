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
      if(!target->isAlive())
      {
        target = findClosestFigure(other);
        if(!target)
          return;
      }
      member->attack(target);
    }
  }

  void SmartTeam::print()
  {
    for(Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
  }
