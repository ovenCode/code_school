// Project3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// functions declaration
string kodWyr(string);
// variable declaration
int ile;
string linia;

//

int main()
{
	fstream plik("plik.txt");
	// checking if file.is_good()

	plik >> ile;
	plik << ile;
	cout << ile;
	cout << plik.good();

	// changing every line to encoded string

	if (plik.is_open())
	{
		int it = 0;
		plik >> ile;
		cout << "Plik oryginalny" << endl;
		while (ile > it)
		{

			getline(plik, linia);
			cout << linia << endl;
			cout << "Wyraz skrocony to: " << kodWyr(linia) << endl;
			it++;
		}
	}
	else
	{
		cout << "cant open file" << endl;
	}
	plik.close();
	return 0;
}

// function definition

string kodWyr(string s)
{
	int poz = 0, it = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i > 0)
		{
			if (s[i] == s[i - 1])
			{
				if (it == 0)
					poz = i - 1;
				it++;
			}
			if (s[i] != s[i - 1])
			{
				if (it > 1)
				{
					if (poz + it < s.length())
					{
						s.erase(s.begin() + poz, s.begin() + poz + it);
						s[poz + 1] = it;
						it = 0;
					}
					else
					{
						s.erase(s.begin() + poz, s.end());
					}
				}
			}
		}
	}

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
