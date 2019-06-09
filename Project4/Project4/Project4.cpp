  // Project4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string ctos(char);
void sprawdzam(int);
void dodaw(int,string,int);
bool check(int,string);

int main()
{
	int ile, val;
	cin >> ile;
	
	
	if (ile <= 80)
	{
		for (int i = 0; i < ile; i++)
		{
			cin >> val;
			sprawdzam(val);
		}
	}
	return 0;
}

void sprawdzam(int x)
{
	string a, b, c;
	int i = 0;
	// a = to_string(x);

	/*for (int i = 0; i < static_cast<int>(a.length()); i++)
	{
		if ((1 <= x) && (x <= 80))
		{
			if (static_cast<int>(a.length()) == 1)
			{
				x += x;
				a = to_string(x);
			}
			else if (((a[i] == a[i + 1]) && (i != static_cast<int>(a.length()))) || (((i + 1) != static_cast<int>(a.length())) && (a[i] == a[i + 2]) && (a[i] != a[i + 1])))
			{
				cout << "Znalazles palindrom rowny" << x;
				cout << "Musiales zrobic " << i + 1 << " dodawan" << endl;
			}
			else if ((i != static_cast<int>(a.length())) && (a[i] != a[i + 1]))
			{
				b = a[i];
				c = a[i + 1];
				x = stoi(b) * 10 + stoi(c) + stoi(c) * 10 + stoi(b);
				a = to_string(x);
			}
			else if ((i + 1) != static_cast<int>(a.length()) && (a[i] != a[i + 2]))
			{
				b = a[i];
				c = a[i + 1];
				a = a[i + 2];
				x = stoi(a) * 100 + stoi(c) * 10 * 2 + stoi(b) + stoi(b) * 100 + stoi(a);
				a = to_string(x);
}
        }
        else
            cout << "Wpisales zbyt duza cyfre" << endl;
    }*/

	if (!check(x, a))
	{
		dodaw(x, a, i);
	}
	else
	{
		cout << "Znalazles palindrom rowny" << x;
		cout << "Musiales zrobic " << i + 1 << " dodawan" << endl;
	}
}

bool check(int x, string s)
{
	char l;
	s = to_string(x);
	if (static_cast<int>(s.length() == 1)) return false;
	else
	{
		for (int i = 0; i < static_cast<int>(s.length()); i++)
		{
			for (int k = static_cast<int>(s.length()); k >= 0; k--)
			{
				l = s[i];
				s[i] = s[k];
				s[k] = l;
			}
			if (s == to_string(x)) return true;
			else return false;
		}
	}
	return false;
}

void dodaw(int x, string s, int y)
{
	for(int i = 0; i <= static_cast<int>(s.length()); i++)
	{
		x = x + stoi(s);
		cout << x << endl;
		y = i;
	}
}

string ctos(char x)
{
	string s(1, x);

	return s;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
