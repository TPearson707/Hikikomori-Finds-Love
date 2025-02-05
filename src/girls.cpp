// girls.cpp
#include "girls.h"
girls::girls()
{
    girlChar = '*';
    minGirlSpawn = 85;
    maxGirlsPerLevel = 5;
    girl = " ";
    discussion = " ";
    girlfriend = false;
}
char girls::GetGirlChar() const
{
    return girlChar;
}
void girls::SeedGirls(char **board, int row, int col, char player, char objective)
{
    // bounds for looping is start of board and end of board
    int girlCounter, girlRNG, spawnGirl;
    girlCounter = 0;
    girlRNG = 100 + 1;
    srand(time(NULL));
    for (int i = 2; i < row - 1; i++)
    {
        for (int j = 2; j < col - 1; j++)
        {
            spawnGirl = rand() % girlRNG;
            if (board[i][j] != player && spawnGirl > minGirlSpawn - 1)
            {
                if (board[i][j] == objective)
                {
                    if (board[i + 1][j] != '#')
                    {
                        board[i + 1][j] = girlChar;
                        girlCounter++;
                        break; // if girl spawns on row break to next row
                    }
                    else if (board[i][j + 1] != '#')
                    {
                        board[i][j + 1] = girlChar;
                        girlCounter++;
                        break; // if girl spawns on row break to next row
                    }
                }
                board[i][j] = girlChar;
                girlCounter++;
                break; // if girl spawns on row break to next row
            }
            if (girlCounter == maxGirlsPerLevel)
            {
                return; // if max girls per level have spawned return out of function
            }
        }
    }
}
void girls::GetGirlType()
{
    int typeRNG;
    typeRNG = 3;
    srand(time(NULL));
    int randomGirl = rand() % typeRNG;
    switch (randomGirl)
    {
    case 0:
        girl = "anxious";
        break;
    case 1:
        girl = "fun";
    case 2:
        girl = "serious";
    }
}
void girls::GetGirlInteraction(player player)
{
    int playerObj = player.GetTotalObjectives();
    if (girl == "anxious")
    {
        if (playerObj >= 4)
        {
            GetAnxiousRun();
            return;
        }
        else if (playerObj == 3)
        {
            GetAnxiousGirlfriend();
        }
        else
        {
            GetEwNo();
        }
    }
    else if (girl == "fun")
    {
        if (playerObj >= 4)
        {
            GetFunGirlfriend();
        }
        else
        {
            GetEwNo();
        }
    }
    else if (girl >= "serious")
    {
        if (playerObj >= 4)
        {
            GetSeriousGirlfriend();
        }
        else
        {
            GetEwNo();
        }
    }
}
void girls::GetEwNo()
{
    sleep(.200);
    system("CLS");
    discussion = "Hito approaches the young lady";
    dialogue.GetString(discussion);
    discussion = "She seems... " + girl;
    dialogue.GetString(discussion);
    discussion = "Hito: Hello!";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + " girl: Ew get away pervert!";
    dialogue.GetString(discussion);
    if (dialogue.fin())
    {
        return;
    }
}
void girls::GetAnxiousRun()
{
    sleep(.200);
    system("CLS");
    discussion = "Hito approaches the young lady";
    dialogue.GetString(discussion);
    discussion = "She seems... " + girl;
    dialogue.GetString(discussion);
    discussion = "Hito: Hello there gorgeous!";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + " girl: ...";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + " girl: ...";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + " girl: ...";
    dialogue.GetString(discussion);
    discussion = "The " + girl + " girl ran away!";
    dialogue.GetString(discussion);
    if (dialogue.fin())
    {
        return;
    }
}
void girls::GetAnxiousGirlfriend()
{
    sleep(.200);
    system("CLS");
    discussion = "Hito approaches the young lady";
    dialogue.GetString(discussion);
    discussion = "She seems... " + girl;
    dialogue.GetString(discussion);
    discussion = "Hito: W-Why hello there.";
    dialogue.GetString(discussion);
    discussion = "Hito is visibly shaking.";
    dialogue.GetString(discussion);
    discussion = "The " + girl + " girl looks away and asks";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + "girl: who are you?";
    dialogue.GetString(discussion);
    discussion = "Astonished that she would still look his way he responded";
    dialogue.GetString(discussion);
    discussion = "Hito: M-My name's Hito";
    dialogue.GetString(discussion);
    discussion = "the " + girl + " girl handcuffed Hito and took him to her dungeon";
    dialogue.GetString(discussion);
    if (dialogue.fin())
    {
        cout << endl;
        discussion = "You win!";
        dialogue.GetString(discussion);
        system("CLS");
        girlfriend = true;
    }
}
void girls::GetSeriousGirlfriend()
{
    sleep(.200);
    system("CLS");
    discussion = "Hito approaches the young lady";
    dialogue.GetString(discussion);
    discussion = "She seems... " + girl;
    dialogue.GetString(discussion);
    discussion = "Hito: W-Why hello there.";
    dialogue.GetString(discussion);
    discussion = "Hito is visibly shaking.";
    dialogue.GetString(discussion);
    discussion = "The " + girl + " girl look STRAIGHT INTO HIS EYEBALL SOCKETS and said";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + "girl: who are you?";
    dialogue.GetString(discussion);
    discussion = "Astonished that she would still look his way he responded";
    dialogue.GetString(discussion);
    discussion = "Hito: M-My name's Hito";
    dialogue.GetString(discussion);
    discussion = "the " + girl + " made him do his homework, and whipped him when he refused";
    dialogue.GetString(discussion);
    if (dialogue.fin())
    {
        cout << endl;
        discussion = "You win!";
        dialogue.GetString(discussion);
        system("CLS");
        girlfriend = true;
    }
}
void girls::GetFunGirlfriend()
{
    sleep(.200);
    system("CLS");
    discussion = "Hito approaches the young lady";
    dialogue.GetString(discussion);
    discussion = "She seems... " + girl;
    dialogue.GetString(discussion);
    discussion = "Hito: W-Why hello there.";
    dialogue.GetString(discussion);
    discussion = "Hito is visibly shaking.";
    dialogue.GetString(discussion);
    discussion = "The " + girl + " girl chuckles to herself and asks";
    dialogue.GetString(discussion);
    discussion = dialogue.name(girl) + "girl: who are you?";
    dialogue.GetString(discussion);
    discussion = "Astonished that she would still look his way he responded";
    dialogue.GetString(discussion);
    discussion = "Hito: M-My name's Hito";
    dialogue.GetString(discussion);
    discussion = "the " + girl + " girl forced Hito to party till he perished";
    dialogue.GetString(discussion);
    if (dialogue.fin())
    {
        cout << endl;
        discussion = "You win!";
        dialogue.GetString(discussion);
        system("CLS");
        girlfriend = true;
    }
}
bool girls::CheckLevel3And6(int level)
{
    if (level == 3 || level == 6)
    {
        return true;
    }
    return false;
}
bool girls::GetGirlfriend() const
{
    return girlfriend;
}