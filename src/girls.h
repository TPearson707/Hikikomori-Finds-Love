// girls.h
#ifndef GIRLS_H
#define GIRLS_H
#include <stdlib.h>
#include <time.h>
#include <string>
#include "player.h"
#include "dialogue.cpp"
using namespace std;
class girls
{
private:
    char girlChar;
    int minGirlSpawn;
    int maxGirlsPerLevel;
    string girl;
    dialogue dialogue;
    string discussion;
    bool girlfriend;

public:
    girls();
    char GetGirlChar() const;
    void SeedGirls(char **, int, int, char, char);
    void GetGirlType();
    bool GetGirlfriend() const;
    void GetGirlInteraction(player);
    void GetEwNo();
    void GetAnxiousGirlfriend();
    void GetAnxiousRun();
    void GetSeriousGirlfriend();
    void GetFunGirlfriend();
    bool CheckLevel3And6(int);
};
#endif