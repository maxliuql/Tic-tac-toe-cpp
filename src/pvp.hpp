#pragma once
void Xaction()
{
    int p;

	while(1)
	{
	    cin >> p;

	    if(isValid(p))
	    {
	        board[p] = 'X';
	        break;
		}
	}
}

void Oaction()
{
    int p;

	while(1)
	{
	    cin >> p;

	    if(isValid(p))
	    {
	        board[p] = 'O';
	        break;
		}
	}
}

void PvP()
{
    char now = 'O';

    output();

    while(winner() == ' ' && someValid())
    {
        if(now == 'O')
        {
            Oaction();
            now = 'X';
        }
        else
        {
            Xaction();
            now ='O';
        }

        output();
    }

    if(winner() != ' ')
        cout << winner() << " wins!" << endl;
    else
        cout << "It\'s a tie!" << endl;
}

