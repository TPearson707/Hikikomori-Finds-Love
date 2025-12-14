// player.cpp
#include "player.h"
player::player()
{
    facingLeft = '<';
    facingRight = '>';
    hasShower = 0;
    hasDeodorant = 0;
    hasHaircut = 0;
    hasNewClothes = 0;
}
char player::GetLeft() const
{
    return facingLeft;
}
char player::GetRight() const
{
    return facingRight;
}
void player::SetShower()
{
    hasShower = 1;
}
void player::SetDeodorant()
{
    hasDeodorant = 1;
}
void player::SetHaircut()
{
    hasHaircut = 1;
}
void player::SetClothes()
{
    hasNewClothes = 1;
}
int player::GetTotalObjectives()
{
    // return hasShower + hasDeodorant + hasHaircut + hasNewClothes;
    return hasShower + hasDeodorant + hasHaircut + hasNewClothes;
}