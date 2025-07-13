#pragma once
void youDown(int p)
{
    board[p] = youw;
}

void youUp(int p)
{
    board[p] = ' ';
}

void robotDown(int p)
{
    board[p] = robotw;
}

void robotUp(int p)
{
    board[p] = ' ';
}
void robotChoose()
{
    int goodChoice[9]={4, 1, 3, 5, 7, 0, 2, 6, 8}, i;

    cout << "choosing..." << endl;

    for(i = 0; i < 9; i++)
    {
        if(isValid(i))
        {
            robotDown(i);
            if(!(winner() == robotw))
                robotUp(i);
            else
                return;

            youDown(i);
            if(winner() == youw)
            {
                youUp(i);
                robotDown(i);
                return;
            }
            else
                youUp(i);
        }
    }

    i = 0;

    while(i < 9)
    {
        if(isValid(goodChoice[i]))
        {
            robotDown(goodChoice[i]);
            return;
        }

        i++;
    }
}

void youChoose()
{
    int pl;

    do
        cin >> pl;
    while(!isValid(pl));

    youDown(pl);
}

void PvR(bool isYouStart)
{
    bool isYouNow = isYouStart;
    youw = (isYouStart?('O'):('X'));
    robotw = (isYouStart?('X'):('O'));

    output();

    while(winner() == ' ' && someValid())
    {
        if(isYouNow)
            youChoose();
        else
            robotChoose();

        isYouNow =! isYouNow;

        output();
    }

    if(winner() != ' ')
        cout << winner() << " wins!" << endl;
    else
        cout << "It\'s a tie!" << endl;
}
