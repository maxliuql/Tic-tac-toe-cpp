#pragma once
char robotw, youw;
char board[9]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void output()
{
    char a[9];
    int i;

    for(i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
            a[i] = i + '0';
        else
            a[i] = board[i];
    }

    cout << a[0] << " | " << a[1] << " | " << a[2] << '\n' << "----------" << '\n' << a[3] << " | " << a[4] << " | " << a[5] << '\n' << "----------" << '\n' << a[6] << " | " << a[7] << " | " << a[8] << '\n';
}

char winner()
{
    int winLines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int i;

    for(i = 0; i < 8; i++)
    {
        if(((board[winLines[i][0]] == board[winLines[i][1]]) && (board[winLines[i][1]] == board[winLines[i][2]]))
           && ((board[winLines[i][0]]!=' ') && (board[winLines[i][1]]!=' ') && (board[winLines[i][2]]!=' ')))
            return board[winLines[i][0]];
    }

    return ' ';
}

bool isValid(int p)
{
    if((p >= 0 && p < 9) && (board[p] == ' '))
        return true;

    return false;
}

bool someValid()
{
    int invalidNum = 0;

    for(int i = 0; i < 9; i++)
    {
        if(!isValid(i))
            invalidNum++;
    }

    if(invalidNum == 9)
        return false;

    return true;
}

void instructions()
{
    cout <<
   "Tic Tac Toe - How to play:\n\
You can input numbers 0-8 to put on the board like this:\n\
\t 0 | 1 | 2 \n\
\t ----------\n\
\t 3 | 4 | 5 \n\
\t ----------\n\
\t 6 | 7 | 8 \n\
Every game have two players: \'X\' and \'O\'.\n\
In the start of the game, you can choose two modes in the game,\n\
by input the number on the left of the items at the bottom of this instruction.\n\
You can play several times, and you can quit if you want by input other numbers.\n\
And, You can choose who go down first by press 0(robot) and 1(you). And all game start with \'O\'.\n\n\
Now, let\'s play!\n\n\
";
}

bool whoFirst()
{
    int a;

    cout << "1: You first\n2: Robot first\n";
    cin >> a;

    return (a == 1) ? true : false;
}

void showItems()
{
    cout<<"1: Person VS Robot\n2: Person VS Person\n";
}
