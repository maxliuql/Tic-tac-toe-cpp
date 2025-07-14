#include <iostream>
using namespace std;
#include "./src/game.hpp"
#include "./src/pvp.hpp"
#include "./src/pvr.hpp"

extern char robotw, youw;
extern char board[9];



int main()
{
    int a;

    instructions();

    while(1)
    {
        showItems();

        cin >> a;

        if(a == 2)
            PvP();
        else if(a == 1)
            PvR(whoFirst());
        else
            break;

        for(int i = 0; i < 9; i++)
            board[i] = ' ';
    }

    return 0;
}

