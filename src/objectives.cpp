// objectives.cpp
#include "objectives.h"
#include <cstdlib>
#include <ctime>
objectives::objectives()
{
    objChar = '@';
    minObjSpawn = 85;
}
char objectives::GetObjChar() const
{
    return objChar;
}
void objectives::SeedObj(char **board, int row, int col)
{
    srand(time(NULL));
    int objRNG, spawnObj;
    objRNG = 100 + 1;
    for (int i = 3; i < row - 2; i++)
    {
        for (int j = 5; j < col - 2; j++)
        {
            int spawnObj = rand() % objRNG;
            if (spawnObj > minObjSpawn - 1)
            {
                board[i][j] = objChar;
                return;
            }
        }
    }
    board[6][10] = objChar;
}