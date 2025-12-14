// objectives.h
#ifndef OBJECTIVES
#define OBJECTIVES
class objectives
{
private:
    char objChar;
    int minObjSpawn;

public:
    objectives();
    char GetObjChar() const;
    void SeedObj(char **, int, int);
};
#endif