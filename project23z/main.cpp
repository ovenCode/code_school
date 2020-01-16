#include <iostream>
#include <string>

using namespace std;

int powe(int, int);
string iToString(int);
string rever(string);
int stringToI(string);
int palindrom(int);

int main()
{

    int sets = 0, number[80], temp = 0;

    cin >> sets;
    if (sets < 81)
    {
        for (int i = 0; i < sets; i++)
        {
            cin >> temp;
            if ((temp >= 1) && (temp <= 80))
            {
                number[i] = temp;
            }
            // i--;
        }
        for (int i = 0; i < sets; i++)
        {
            //if ((number[i] >= 1) && (number[i] <= 80))
            //{
                cout << palindrom(number[i]) << endl;
            //}
        }
    }
    return 0;
}

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
		wynik = wynik + (wyraz[i] - 48)*powe(10,wyraz.length() - i - 1);
	}
	return wynik;
}

string rever(string wyraz)
{
    string temp = "";

    for (int i = 0; i < wyraz.length(); i++)
    {
        temp = temp + wyraz[wyraz.length() - i - 1];
    }
    
    return temp;
}

int palindrom(int liczba)
{
    int temp = 0;

    if (iToString(liczba).length() == 1)
    {
        cout << liczba << " ";

        return 0;
    }
    else
    {
        while (iToString(liczba) != rever(iToString(liczba)))
        {
            liczba = liczba + stringToI(rever(iToString(liczba)));
            temp++;
        }
    }
    
    cout << liczba << " ";

    return temp;
}
