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

    int sets = 0, number = 0;

    //

    cout << stringToI("27") << endl << endl << stringToI("328") << endl << endl << stringToI("8");

    return 0;
}

// FUNCTION DEFINITION

int powe(int podstawa, int wykladnik)
{
    int wynik = 1;

    for (int i = 0; i < wykladnik; i++)
    {
        if (wykladnik == 0)
        {
            return 1;
        }
        else if (wykladnik == 1)
        {
            return podstawa;
        }
        else
        {
            wynik *= podstawa;
        }
    }

    return wynik;
}

string iToString(int liczba)
{
    int licznik = 0, jednostka = 0, ilosc_petli = 0;
    string znaki = "";
    char temp = ' ';

    while (powe(10, licznik) < liczba)
    {
        licznik++;
    }

    licznik = licznik - 1;
    ilosc_petli = licznik + 1;

    
    if(licznik == 0)
    {
        
    }

    for(int i = 0; i < ilosc_petli; i++)
    {
        while (jednostka * powe(10,licznik) <= liczba)
        {
            jednostka++;
        }

       
        jednostka = jednostka - 1;

        temp = jednostka + 48;

        liczba = liczba - jednostka * powe(10,licznik);
        jednostka = 0;
        licznik = licznik - 1;
		
		znaki = znaki + temp;

    }
    
    return znaki;
}

int stringToI(string wyraz)
{
	int wynik = 0;
	
	for(int i = 0;i < wyraz.length(); i++)
	{
		wynik = wynik + (wyraz[i] - 48)*powe(10,wyraz.length()-i - 1);
	}
	return wynik;
}
