// board.h
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "player.cpp"
#include "girls.cpp"
#include "bully.cpp"
#include "objectives.cpp"
using namespace std;
class board
{
private:
    int gameLevel;
    int row;
    int col;
    int x;
    int y;
    char **maps;
    char border;
    char defaultBoardState;
    player player;
    girls girl;
    bully bully;
    objectives objectives;
    char playerFacing;
    char girlChar;
    char objChar;
    bool lose;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    board(istream &, int, int, int);
    ~board();
    void PrintLevelTitle(int) const;
    void SeedBoard(int, int);
    void NextBoard(istream &file, int, int);
    bool CheckPlayerMoveBorder(int, int);
    bool CheckPlayerMoveGirl(int, int);
    bool CheckPlayerMoveObj(int, int);
    bool CheckPlayerMoveBully(int, int);
    void SetPlayerBuffs(int);
    void MovePlayer(istream &file, int, int &);
    void PrintBoard(int, int);
    bool CheckWin();
    bool CheckLoss();
};
#endif