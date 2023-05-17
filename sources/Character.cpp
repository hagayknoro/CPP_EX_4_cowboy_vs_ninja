#include "Character.hpp"

Character::Character(string name, const Point &location, int life):
    name(name), location(location), life(life)
{

}

bool Character::isAlive()
{
    return true;
}
double Character::distance(const Character &other)
{
    return 0.0;
}
void Character::hit(int hPow)
{

}
string Character::getName()
{
    return "Jon Doh";
}
Point Character::getLocation()
{
    return Point(0.0, 0.0);
}
string Character::print()
{
    return "Jon Doh, points";
}
int Character::getLife()
{
    return life;
}