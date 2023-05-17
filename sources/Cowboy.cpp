#include "Cowboy.hpp"
#include "Character.hpp"

Cowboy::Cowboy(string name, const Point &location):
    Character(name, location, 100), raunds(60)
    {

    }
void Cowboy::shoot(Character *enemy)
{

}
bool Cowboy::hasboolets()
{
    return true;
}
void Cowboy::reload()
{
    
}