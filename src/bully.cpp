// bully.cpp
#include "bully.h"
bully::bully()
{
    bullyChar = '!';
    minBullySpawn = 95;
    maxBullySpawn = 1;
}
void bully::CheckSpawn(char **board, int &counter, int i, int j, char border, char girl, char player, char obj)
{
    if (board[i][j] == girl || board[i][j] == obj)
    { // check if bully spawns on top of another char
        if (board[i + 1][j] != '#' && board[i + 1][j] != girl && board[i + 1][j] != obj)
        {
            board[i + 1][j] = bullyChar;
            counter++;
        }
        else if (board[i][j + 1] != '#' && board[i][j + 1] != girl && board[i][j + 1] != obj)
        {
            board[i][j + 1] = bullyChar;
            counter++;
        }
        else if (board[i][j - 1] != '#' && board[i][j - 1] != girl && board[i][j - 1] != obj)
        {
            board[i][j - 1] = bullyChar;
            counter++;
        }
    }
    else
    { // if board did not spawn on another character assign board position to !
        board[i][j] = bullyChar;
        counter++;
    }
}
void bully::SeedBullies(char **board, int difficulty, int row, int col, char border, char girl, char player,
                        char obj)
{
    int bullyCounter, bullyRNG, spawnBully;
    bullyRNG = 100 + 1;
    if (difficulty == 1)
    { // game set to normal difficulty
        chrono::hours hours_to_add(7);
        system_clock::time_point today = system_clock::now();
        system_clock::time_point new_time = today + hours_to_add;
        auto GEN = system_clock::to_time_t(new_time);
        srand(time(&GEN));
        for (int i = 3; i < row - 1; i++)
        {
            bullyCounter = 0;
            for (int j = 1; j < col - 1; j++)
            {
                spawnBully = rand() % bullyRNG;
                if (spawnBully > minBullySpawn - 1)
                { // check if a bully is spawned
                    CheckSpawn(board, bullyCounter, i, j, border, girl, player, obj);
                    if (bullyCounter == maxBullySpawn)
                    {
                        break;
                    } // if max bullies per row is spawn go to next row
                }
            }
        }
    } // end of normal
    if (difficulty == 2)
    {
        minBullySpawn = 80;
        maxBullySpawn = 1;
        srand(time(NULL));
        for (int i = 2; i < row - 1; i++)
        {
            bullyCounter = 0;
            for (int j = 1; j < col - 1; j++)
            {
                spawnBully = rand() % bullyRNG;
                if (spawnBully > minBullySpawn - 1)
                {                                                                     // check if a bully is spawned
                    CheckSpawn(board, bullyCounter, i, j, border, girl, player, obj); // if bully is spawned check collisions and move accordingly
                    if (bullyCounter == maxBullySpawn)
                    {
                        break;
                    } // if max bullies per row is spawn go to next row
                }
            }
        }
    }
}