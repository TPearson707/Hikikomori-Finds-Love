// board.cpp
#include "board.h"
board::board(istream &file, int rows, int cols, int level)
{
    gameLevel = level;
    row = rows;
    col = cols;
    x = 1;
    y = 1;
    border = '#';
    defaultBoardState = '-';
    playerFacing = player.GetRight();
    girlChar = girl.GetGirlChar();
    objChar = objectives.GetObjChar();
    lose = false;
    maps = new char *[row];
    for (int i = 0; i < row; i++)
    {
        maps[i] = new char[col];
        for (int j = 0; j < col; j++)
            file >> maps[i][j];
    }
}
board::~board()
{
    for (int i = 0; i < row; i++)
    {
        delete[] maps[i];
    }
    delete[] maps;
}
void board::PrintLevelTitle(int level) const
{
    switch (level)
    {
    case 1:
        cout << "LEVEL: " << level << " Take a Shower!" << endl;
        break;
    case 2:
        cout << "LEVEL: " << level << " Put on Some Deodorant!" << endl;
        break;
    case 3:
        cout << "LEVEL: " << level << " Welcome to the Outside World." << endl;
        break;
    case 4:
        cout << "LEVEL: " << level << " Maybe it's Time for a Haircut." << endl;
        break;
    case 5:
        cout << "LEVEL: " << level << " Some Clothes Would Help!" << endl;
        break;
    case 6:
        cout << "LEVEL: " << level << " Operation Find Love!" << endl;
        break;
    }
}
void board::SeedBoard(int difficulty, int level)
{
    if (level != 3)
    {
        objectives.SeedObj(maps, row, col);
    }
    if (level > 2)
    {
        girl.SeedGirls(maps, row, col, playerFacing, objChar);
    }
    if (difficulty > 0 && level > 2)
    {
        bully.SeedBullies(maps, difficulty, row, col, border, girlChar, playerFacing, objChar);
    }
}
void board::NextBoard(istream &file, int difficulty, int level)
{
    system("CLS");
    PrintLevelTitle(level);
    file.ignore();
    for (int rows = 0; rows < row; rows++)
    {
        for (int cols = 0; cols < col; cols++)
        {
            file >> maps[rows][cols];
        }
    }
    SeedBoard(difficulty, level);
    PrintBoard(difficulty, level);
}
bool board::CheckPlayerMoveBorder(int row, int col)
{
    if (maps[row][col] != border)
    {
        return false;
    }
    return true;
}
bool board::CheckPlayerMoveGirl(int row, int col)
{
    if (maps[row][col] != girlChar)
    {
        return false;
    }
    return true;
}
bool board::CheckPlayerMoveObj(int row, int col)
{
    if (maps[row][col] != objChar)
    {
        return false;
    }
    return true;
}
bool board::CheckPlayerMoveBully(int row, int col)
{
    if (maps[row][col] != '!')
    {
        return false;
    }
    return true;
}
void board::SetPlayerBuffs(int level)
{
    switch (level)
    {
    case 1:
        player.SetShower();
        system("CLS");
        cout << "Shower Achieved!";
        Sleep(2000);
        break;
    case 2:
        player.SetDeodorant();
        system("CLS");
        cout << "Deodorant Achieved!";
        Sleep(2000);
        break;
    case 4:
        player.SetHaircut();
        system("CLS");
        cout << "Haircut Achieved!";
        Sleep(2000);
        break;
    case 5:
        player.SetClothes();
        system("CLS");
        cout << "Clothes Achieved!";
        Sleep(2000);
        break;
    }
}
void board::MovePlayer(istream &file, int difficulty, int &level)
{
    static int counter = 0;
    system("pause>nul");
    if (GetAsyncKeyState(VK_UP))
    {
        bool checkBorder = CheckPlayerMoveBorder(x - 1, y);
        if (!checkBorder)
        {
            bool checkGirl = CheckPlayerMoveGirl(x - 1, y);
            if (checkGirl)
            {
                girl.GetGirlType();
                girl.GetGirlInteraction(player);
                if (girl.CheckLevel3And6(level))
                {
                    level++;
                    gameLevel++;
                    NextBoard(file, difficulty, level);
                    maps[x][y] = defaultBoardState;
                    x = 1;
                    y = 1;
                    return;
                }
            }
            bool checkObj = CheckPlayerMoveObj(x - 1, y);
            if (checkObj)
            {
                SetPlayerBuffs(level);
                level++;
                gameLevel++;
                NextBoard(file, difficulty, level);
                maps[x][y] = defaultBoardState;
                x = 1;
                y = 1;
                return;
            }
            bool checkBully = CheckPlayerMoveBully(x - 1, y);
            if (checkBully)
            {
                lose = true;
                return;
            }
            maps[x][y] = defaultBoardState;
            maps[x - 1][y] = playerFacing;
            x = x - 1;
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        bool checkBorder = CheckPlayerMoveBorder(x + 1, y);
        if (!checkBorder)
        {
            bool checkGirl = CheckPlayerMoveGirl(x + 1, y);
            if (checkGirl)
            {
                girl.GetGirlType();
                girl.GetGirlInteraction(player);
                if (girl.CheckLevel3And6(level))
                {
                    level++;
                    gameLevel++;
                    NextBoard(file, difficulty, level);
                    maps[x][y] = defaultBoardState;
                    x = 1;
                    y = 1;
                    return;
                }
            }
            bool checkObj = CheckPlayerMoveObj(x + 1, y);
            if (checkObj)
            {
                level++;
                gameLevel++;
                NextBoard(file, difficulty, level);
                maps[x][y] = defaultBoardState;
                x = 1;
                y = 1;
                return;
            }
            bool checkBully = CheckPlayerMoveBully(x + 1, y);
            if (checkBully)
            {
                lose = true;
                return;
            }
            maps[x][y] = defaultBoardState;
            maps[x + 1][y] = playerFacing;
            x = x + 1;
        }
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        playerFacing = player.GetLeft();
        bool checkBorder = CheckPlayerMoveBorder(x, y - 1);
        if (!checkBorder)
        {
            bool checkGirl = CheckPlayerMoveGirl(x, y - 1);
            if (checkGirl)
            {
                girl.GetGirlType();
                girl.GetGirlInteraction(player);
                if (girl.CheckLevel3And6(level))
                {
                    level++;
                    gameLevel++;
                    NextBoard(file, difficulty, level);
                    maps[x][y] = defaultBoardState;
                    x = 1;
                    y = 1;
                    return;
                }
            }
            bool checkObj = CheckPlayerMoveObj(x, y - 1);
            if (checkObj)
            {
                SetPlayerBuffs(level);
                level++;
                gameLevel++;
                NextBoard(file, difficulty, level);
                maps[x][y] = defaultBoardState;
                x = 1;
                y = 1;
                return;
            }
            bool checkBully = CheckPlayerMoveBully(x, y - 1);
            if (checkBully)
            {
                lose = true;
                return;
            }
            maps[x][y] = defaultBoardState;
            maps[x][y - 1] = playerFacing;
            y = y - 1;
        }
        else
        {
            maps[x][y] = playerFacing;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        playerFacing = player.GetRight();
        bool checkBorder = CheckPlayerMoveBorder(x, y + 1);
        if (!checkBorder)
        {
            bool checkGirl = CheckPlayerMoveGirl(x, y + 1);
            if (checkGirl)
            {
                girl.GetGirlType();
                girl.GetGirlInteraction(player);
                if (girl.CheckLevel3And6(level))
                {
                    level++;
                    gameLevel++;
                    NextBoard(file, difficulty, level);
                    maps[x][y] = defaultBoardState;
                    x = 1;
                    y = 1;
                    return;
                }
            }
            bool checkObj = CheckPlayerMoveObj(x, y + 1);
            if (checkObj)
            {
                SetPlayerBuffs(level);
                level++;
                gameLevel++;
                NextBoard(file, difficulty, level);
                maps[x][y] = defaultBoardState;
                x = 1;
                y = 1;
                return;
            }
            bool checkBully = CheckPlayerMoveBully(x, y + 1);
            if (checkBully)
            {
                lose = true;
                return;
            }
            maps[x][y] = defaultBoardState;
            maps[x][y + 1] = playerFacing;
            y = y + 1;
        }
    }
}
bool board::CheckWin()
{
    if (girl.GetGirlfriend())
    {
        return true;
    }
    return false;
}
bool board::CheckLoss()
{
    if (lose)
    {
        return true;
    }
    return false;
}
void board::PrintBoard(int difficulty, int level)
{
    PrintLevelTitle(gameLevel);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (maps[i][j] == border)
            {
                SetConsoleTextAttribute(console, 12);
            }
            else if (maps[i][j] == defaultBoardState)
            {
                SetConsoleTextAttribute(console, 12);
            }
            else if (maps[i][j] == playerFacing)
            {
                SetConsoleTextAttribute(console, 11);
            }
            else if (maps[i][j] == girlChar)
            {
                SetConsoleTextAttribute(console, 13);
            }
            else if (maps[i][j] == objChar)
            {
                SetConsoleTextAttribute(console, 14);
            }
            else if (maps[i][j] == '!')
            {
                SetConsoleTextAttribute(console, 5);
            }
            cout << maps[i][j] << " ";
        }
        cout << endl;
    }
    if (difficulty > 0 && level > 2)
    {
        bully.SeedBullies(maps, difficulty, row, col, border, girlChar, playerFacing, objChar);
    }
}