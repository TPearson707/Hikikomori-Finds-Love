// player.h
#ifndef PLAYER_H
#define PLAYER_H
class player
{
private:
    char facingLeft;
    char facingRight;
    int hasShower, hasDeodorant, hasHaircut, hasNewClothes;

public:
    player();
    char GetLeft() const;
    char GetRight() const;
    void SetShower();
    void SetDeodorant();
    void SetHaircut();
    void SetClothes();
    int GetTotalObjectives();
};
#endif