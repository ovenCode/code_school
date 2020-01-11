#include <iostream>
#include <vector>

using namespace std;

// FUNCTION DECLARATION

int minL(vector<int>);
int maksL(vector<int>);
void pozycja(vector<int>,int,int,int);

//

int main()
{

// MAIN VARIABLES INITIALIZATION

vector<int> zbiorLiczb;
int min = 0, maks = 0, liczba = 0;

//

while (cin >> liczba)
{
    zbiorLiczb.push_back(liczba);
}

min = minL(zbiorLiczb);
maks = maksL(zbiorLiczb);

pozycja(zbiorLiczb,min,maks,0);
pozycja(zbiorLiczb,min,maks,1);

return 0;

}

// FUNCTION DEFINITION

int minL(vector<int> zbior)
{
    int min = 0;

    for (int i = 0; i < zbior.size() - 1; i++)
    {
        if(zbior[i] > zbior[i+1])
        {
            min = zbior[i];
            zbior[i] = zbior[i+1];
            zbior[i+1] = min;
        }
    }
    
    min = zbior[0];

    return min;
}

int maksL(vector<int> zbior)
{
    int maks = 0;

    for (int i = 0; i < zbior.size() - 1; i++)
    {
        if(zbior[i] > zbior[i+1])
        {
            maks = zbior[i];
            zbior[i] = zbior[i+1];
            zbior[i+1] = maks;
        }
    }

    maks = zbior[zbior.size()-1];

    return maks;
}

void pozycja(vector<int> zbior,int min,int maks, int przel)
{
    int pozycjaMin = 0, pozycjaMaks = 0;

    for (int i = 0; i < zbior.size(); i++)
    {
        if(zbior[i] == min)
        {
            if(pozycjaMin == 0)
            {
                pozycjaMin = i + 1;
            }
        }
        else if(zbior[i] == maks)
        {
            pozycjaMaks = i + 1;
        }
    }

    if(przel == 0)
    {
        cout << min << endl << pozycjaMin << endl;
    }
    else if (przel == 1)
    {
        cout << maks << endl << pozycjaMaks;
    }
    
}

//