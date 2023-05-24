#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

Character::Character(string name, const Point &location, int life):
    name(name), location(location), life(life), TeeMember(false)
{
}

bool Character::isAlive()
{
    return 0 < life;
}

double Character::distance(Character *other)
{
    return this->location.distance(other->location);
}

void Character::hit(int hurt)
{
    //chack for valid hit
    if(hurt < 0)
    {
        throw invalid_argument("nice try, but you missed");
    }
    this->life -= hurt;
}

string Character::getName()
{
    return this->name;
}

Point Character::getLocation() const
{
    return this->location;
}

void Character::setLocation(Point goTo)
{
    this->location = goTo;
}

int Character::getLife()
{
    return this->life;
}

bool Character::getTeeMember()
{
    return this->TeeMember;
}

bool Character::setTeeMember()
{
    return this->TeeMember = true;
}