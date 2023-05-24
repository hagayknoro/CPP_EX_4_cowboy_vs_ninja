#include "Team2.hpp"
#include "Character.hpp"

  Team2::Team2(Character *commander):
    Team(commander)
  {
  }


 //class unique function
  void Team2::attack(Team *other)
  {
    if(!other)
      throw invalid_argument("You have to get am enmmy for attack\n");
    if(other->stillAlive() == 0 || this->stillAlive() == 0)
      throw runtime_error("One of the involved team is all ded");
    if(this == other)
      throw runtime_error("This is not the place for suicidal tendencies, we are in the middle of battle\n");
    if(!this->getCommander()->isAlive())
      this->setCommander(findClosestFigure(this));
    
    Character *target = findClosestFigure(other);
    for(Character *member : *this->getTeam())
    {
      if(!target->isAlive())
      {
        target = findClosestFigure(other);
        if(target == nullptr)
          return;
      }
      member->attack(target);
    }
  }

  void Team2::print()
  {
    for(Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
  }
