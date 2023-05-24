#include "Cowboy.hpp"
#include "Character.hpp"

Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 110), raunds(6)
    {
    }

void Cowboy::shoot(Character *enemy)
{
    //check for make shoor the enmy is alive and the anmy and me isnt the same charcter
    if(!this->isAlive())
        throw runtime_error("The figure is dead he can't soot\n");
    if(this == enemy)
        throw runtime_error("This is not the place for suicidal tendencies, we are in the middle of battle\n");
    if(!enemy->isAlive())
        throw runtime_error("This is against the Geneva Convention, manslaughter is not verified\n");
    if(this->hasboolets())
    {
        this->raunds -=1;
        enemy->hit(10);
    }
}

bool Cowboy::hasboolets()
{
    return raunds > 0;
}

void Cowboy::reload()
{
    //make shoor the plyer alive
    if(!this->isAlive())
    {
        throw runtime_error("Don't be a hero, you'r deed you can't reload\n");
    }
    raunds = 6;
}

void Cowboy::attack(Character *enemy)
{
    if(!this->isAlive())
        return;
    if(this == enemy)
        throw runtime_error("This is not the place for suicidal tendencies, we are in the middle of battle\n");   
    if(!enemy->isAlive())
        return;
    if(this->hasboolets())
        this->shoot(enemy);
    else
        this->reload();    
}

string Cowboy::print()
{
    //for live cowboy
    if(isAlive())
    {
        return "Name: (C)" + this->getName() + ", life points: " + to_string(this->getLife()) 
                + ", character location: " + this->getLocation().print(); 
    }
    //for dead one
    return "Name: (C) (" + this->getName() + "), character location: " +  this->getLocation().print();
}