// main
#include <iostream>
#include "board.cpp"
const int MAXROW = 8;
const int MAXCOL = 12;
int SetDifficulty();
void StartGame(char &);
int main()
{
    int difficulty;
    int level = 1;
    char gameStart = ' ';
    cout << "Hello welcome to Hikikomori Finds Love, we hope you enjoy your stay!\n\n";
    cout << "Are you sure you want to play?" << endl;
    while (gameStart != 'y' && gameStart != 'Y')
    {
        StartGame(gameStart);
        if (gameStart == 'n' || gameStart == 'N')
        {
            return 0;
        }
    }
    cout << "Please input your desired difficulty!\n";
    cout << "\"easy\" This difficulty is for those who want an easy time picking up the ladies\n";                             // no bullies will spawn
    cout << "\"medium\" This difficulty contains bullies. Who will pick up ladies, and pick on you. Girls won't be so easy\n"; // bullies start spawning
    cout << "\"hard\" In this difficulty, you probably won't find love.\n";                                                    // lots of bullies player will have to play mr.steal yo girl with steal yo girl hidden ability

    difficulty = SetDifficulty();
    ifstream maps;
    maps.open("map.txt");
    if (maps.fail())
    {
        cout << "Error: file not found" << endl;
        return 1;
    }
    system("CLS");
    // init board
    board GameBoard(maps, MAXROW, MAXCOL, level);
    GameBoard.PrintLevelTitle(level);
    GameBoard.SeedBoard(difficulty, level);
    GameBoard.PrintBoard(difficulty, level);
    while (true)
    {
        // clear screen
        system("CLS");
        GameBoard.PrintBoard(difficulty, level);       // reprint board
        GameBoard.MovePlayer(maps, difficulty, level); // move player and check events
        if (GameBoard.CheckWin())
        {
            system("CLS");
            cout << "YOU WIN!" << endl;
            cout << "For the full game buy our DLC for $40" << endl;
            cout << "DLC include:" << endl;
            cout << "\t- new enemy types, Chads" << endl;
            cout << "\t- Multiple unique endings based on player choice" << endl;
            cout << "\t- 1000000 boost" << endl
                 << endl;
            cout << "EA sports it's in the game." << endl;
            Sleep(3000);
            return 0;
        }
        if (GameBoard.CheckLoss())
        {
            system("CLS");
            cout << "better luck next time." << endl;
            cout << "For the full game buy our DLC for $40" << endl;
            cout << "DLC include:" << endl;
            cout << "\t- new enemy types, Chads" << endl;
            cout << "\t- Multiple unique endings based on player choice" << endl;
            cout << "\t- 1000000 boost" << endl
                 << endl;
            cout << "EA sports it's in the game." << endl;
            Sleep(3000);
            return 0;
        }
    }
    maps.close();
    return 0;
}
int SetDifficulty()
{
    string difficultyInput;
    int difficulty;
    do
    {
        cin >> difficultyInput;
        if (difficultyInput == "easy")
        {
            difficulty = 0;
            cout << "You have selected easy difficulty." << endl;
            cout << "Starting game..." << endl;
        }
        else if (difficultyInput == "medium")
        {
            difficulty = 1;
            cout << "You have selected medium difficulty." << endl;
            cout << "Starting game..." << endl;
        }
        else if (difficultyInput == "hard")
        {
            difficulty = 2;
            cout << "You have selected hard difficulty." << endl;
            cout << "Starting game..." << endl;
        }
        else
        {
            cout << "Error: Invalid response choose \"easy\", \"medium\", or \"hard\"." << endl;
        }
    } while (difficultyInput != "easy" && difficultyInput != "medium" && difficultyInput != "hard");
    return difficulty;
}
void StartGame(char &game)
{
    cin >> game;
    if (game == 'y' || game == 'Y')
    {
        cout << "Good Luck in your adventure!" << endl;
        return;
    }
    else if (game == 'n' || game == 'N')
    {
        cout << "Goodbye!" << endl;
        return;
    }
    else
    {
        cout << "Please enter 'y' or 'n' please." << endl;
    }
}