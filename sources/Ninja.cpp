#include "Ninja.hpp"
#include "Character.hpp"

Ninja::Ninja(string name, const Point &location, int health, int speed):
    Character(name, location, health), speed(speed) 
{
}

void Ninja::slash(Character *enemy) 
{
    if(!this->isAlive())
        throw runtime_error("The figure is dead he can't soot\n");
    if(this == enemy)
        throw runtime_error("This is not the place for suicidal tendencies, we are in the middle of battle\n");
    if(!enemy->isAlive())
        throw runtime_error("This is against the Geneva Convention, manslaughter is not verified\n");
    if(this->distance(enemy) < 1)
        enemy->hit(40);
}

void Ninja::move(const Character *enemy) 
{
    if(!this->isAlive())
        throw runtime_error("Don't be a hero, you'r deed you can't move\n");
    setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
}

void Ninja::attack(Character *enemy)
{
    if(!this->isAlive())
        return;
    if(!enemy->isAlive())
        return;
    if(this->distance(enemy) < 1)
        this->slash(enemy);
    else
        move(enemy);
}

string Ninja::print()
{
    //for live ninja
    if(isAlive())
    {
        return "Name: (N)" + this->getName() + ", life points: " + to_string(this->getLife()) 
                + ", character location: " + this->getLocation().print(); 
    }
    //for dead one
    return "Name: (N) (" + this->getName() + "), character location: " +  this->getLocation().print();
}
