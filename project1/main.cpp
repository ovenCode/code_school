#include <iostream>
#include <string>

using namespace std;

int c = 1, ilepetli = 0;
string wyraz;
int li = 0, poz = 0;

int main()
{
	cout << "Ile wyrazow chcialbys skrocic: ";
	cin >> ilepetli;
	
	for (int o = 0; o < ilepetli; o++)
	{
		//if (o == 0) cout << ilepetli << endl;
		cout << "Podaj wyraz " << o + 1 << endl;
		cin >> wyraz;
		cout << "Dlugosc wyrazu to " << wyraz.length() << endl;
		char * l = new char[wyraz.length()];
		for (int i = 0; i < wyraz.length() - 1; i++)
		{


			if ((i > 0) && (wyraz[i] == wyraz[i - 1]))
			{
				if (c == 1)
				{
					c++;
					poz = i; //  ppprooosssszee poz = 1 wyraz[1] = p
					li = 0;
					continue;
				}
				if (c > 1)
				{
					c++;
					*(l + li) = wyraz[i - 1];
					li++;
				}

			}
			if ((i > 0) && (wyraz[i] != wyraz[i - 1]))
			{
				if (c > 2)
				{
					char b;
					b = (char)(c + '0');
					wyraz[i - 1] = b;
					wyraz.erase(wyraz.begin() + poz, wyraz.begin() + poz + li);
					//if (c == 3) wyraz.erase(wyraz.begin() + poz);
				}
				c = 1;
			}
			if (i == wyraz.length())
			{
				cout << "Skrocony wyraz brzmi tak: " << wyraz << endl;
				cin >> c;
			}
		}
		//cout << "testowy pobior" << endl;
		//cin >> c;
		delete[] l;
	}
	return 0;
}