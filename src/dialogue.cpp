// dialogue.cpp
#include "dialogue.h"
#include <unistd.h>
void dialogue::GetString(string String)
{
    for (int i = 0; i < String.length(); i++)
    {
        cout << String[i];
        sleep(.200);
    }
    cout << endl;
}
bool dialogue::fin()
{
    string fin = " ";
    do
    {
        cout << "Please enter \"fin\" to finish the interaction" << endl;
        cin >> fin;
    } while (fin != "fin");
    system("CLS");
    return true;
}
string dialogue::name(string String)
{
    String[0] = toupper(String[0]);
    return String;
}