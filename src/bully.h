// bully.h
#ifndef BULLY_H
#define BULLY_H
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace chrono;
class bully
{
private: // Data Members
    char bullyChar;
    char minBullySpawn;
    char maxBullySpawn;

public:
    bully();
    void SeedBullies(char **, int, int, int, char, char, char, char);
    void CheckSpawn(char **, int &, int, int, char, char, char, char);
};
#endif
