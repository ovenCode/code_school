#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATION

int powe(int, int);
string iToString(int);
int stringToI(string);
int palindrom(int, int);

//

int main()
{

    // MAIN VARIABLES INITIALIZATION

    //

    return 0;
}

// FUNCTION DEFINITION

int powe(int podstawa, int wykladnik)
{
    for (int i = 0; i < wykladnik; i++)
    {
        if (i == 0)
        {
            return 1;
        }
        else if (i == 1)
        {
            return podstawa;
        }
        else
        {
            podstawa *= podstawa;
        }
    }
}

string iToString(int liczba)
{
    int licznik = 0;

    while (powe(licznik, 10) < liczba)
    {
        licznik++;
    }
}

//