#include<iostream>
#include<string>
#include <cstddef>

using namespace std;
 
 
class Silnik
{
	int pojemnosc;
	string producent;
public:
	Silnik() : pojemnosc(0), producent("-") {};
	Silnik(int pojemnosc,string producent) : pojemnosc(pojemnosc), producent(producent) {};
	~Silnik();
	int podajPoj();
	string podajPro();
};

class Urzadzenie
{
	const string producent;
	int obroty;
	Silnik silnik;
public:
	Urzadzenie() : obroty(0), producent("-") {}
	Urzadzenie(string producent, int obroty,Silnik silnik) : producent(producent), obroty(obroty), silnik(silnik) {}
	~Urzadzenie();
	Urzadzenie * przesz_tablice(Urzadzenie *,int, string);
	Urzadzenie * dodaj_urz(Urzadzenie *, int);
	string podajProducent();
	int podajObroty();
	Silnik podajSilnik();
	int podajPojemnoscS();
	string podajProducentS();
};

Urzadzenie * stworz_tab(int);
int menu(Urzadzenie *, int);
 
int main()
{
    int a = 2;
    // tworzenie podstawowych urzadzen
	Urzadzenie * urz = stworz_tab(a);
	// menu do reszty opcji
	menu(urz, a);
	
	return 0;
}

// Deklaracje metod/ funkcji od klas

Silnik::~Silnik()
{

}

Urzadzenie::~Urzadzenie()
{

}

Urzadzenie * stworz_tab(int x)
{
	string w,p;
	int l,c;
	for (int i = 0; i < x; i++)
	{
		cout << "Wpisz obroty urzadzenia " << i + 1 << endl;
		cin >> l;
		cout << "Wpisz producenta urzadzenia " << i + 1 << endl;
		cin >> w;
		cout << "Wpisz producenta silnika urzadzenia " << i + 1 << endl;
		cin >> p;
		cout << "Wpisz pojemnosc silnika urzadzenia " << i + 1 << endl;
		cin >> c;
		Silnik s = Silnik(c,p);
		Urzadzenie * a = new Urzadzenie(w,l,s);
		cout << a->podajObroty() << " " << a->podajProducent() << " " << endl;
        if(i != x-1) 	a++;
		else 
		{
			a = a - i;
			return a;
		}
	}
	return 0;
}

Urzadzenie * Urzadzenie::przesz_tablice(Urzadzenie *a,int x, string s)
{
	for(int i = 0; i < x; i++)
	{
		if (a->producent == a->podajProducentS()) 
		{
			a = a - i;
			return (a + i);
		}
		a++;
		
	}
	a = 0;
	return a;
}

Urzadzenie * Urzadzenie::dodaj_urz(Urzadzenie * a, int x)
{
	int ile;
	cout << "Ile urzadzen chcesz dodac: ";
	cin >> ile;
	a = a + x + 1;

	for (int i = x + 1; i < x + 1 + ile; i++)
	{
		string s,t;
		int w, y;
		cout << "Podaj nazwe producenta: " << endl;
		cin >> s;
		cout << "Podaj obroty: " << endl;
		cin >> w;
		cout << "Podaj pojemnosc silnika: " << endl;
		cin >> y;
		cout << "Podaj nazwe producenta silnika: " << endl;
		cin >> t;
		Silnik e(y,t);
		a = new Urzadzenie(s,w,e);
		a++;
	}
	a = a - (ile + x + 1);
	for (int i = 0; i < x + 1 + ile; i++)
	{
		cout << a[i].podajObroty() << " " << a[i].podajProducent() << " " << podajPojemnoscS() << " " << a[i].podajProducent() << endl;
	}
	return a;
}

string Silnik::podajPro()
{
	return this->producent;
}

int Silnik::podajPoj()
{
	return this->pojemnosc;
}
string Urzadzenie::podajProducentS()
{
	
	return this->silnik.podajPro();
}

int Urzadzenie::podajPojemnoscS()
{
	return this->silnik.podajPoj();
}

string Urzadzenie::podajProducent()
{
	return this->producent;
}

int Urzadzenie::podajObroty()
{
	return this->obroty;
}

Silnik Urzadzenie::podajSilnik()
{
	return this->silnik;
}

// Deklaracje funkcji

int menu(Urzadzenie * urz, int a)
{
	while (true)
	{
		int wybor;
		string s;
		cout << "Wybierz, co chcesz zrobic" << endl;
		cout << "1. Dodac obiekt/urzadzenie" << endl;
		cout << "2. Przeszukac tablice obiektow" << endl;
		cout << "3. Wyjsc z programu" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1: 	// dodaj urzadzenia
			urz->dodaj_urz(urz, a);
			break;
		case 2: 	// przeszukiwanie urzadzen
			cout << "Podaj nazwe producenta, ktorego szukasz w urzadzeniach i silnikach :" << endl;
			//cout << "Producent urz" << urz->podajProducent << endl;
			cin >> s;
			if (urz->przesz_tablice(urz, a, s) != 0)
			{
				cout << "Oto urzadzenie, ktorego producent silnika to " << urz->przesz_tablice(urz, a, s)->podajProducent() << " obroty: " << urz->przesz_tablice(urz, a, s)->podajObroty() << " pojemnosc silnika: " << urz->przesz_tablice(urz, a, s)->podajPojemnoscS() << " producent silnika: " << urz->przesz_tablice(urz, a, s)->podajProducentS() << endl;
			}
			else cout << "Nie ma takiego obiektu, ktory by miał takich samych producentow" << endl;
			break;
		case 3: // wyjscie z programu
			return 0;
			break;
		default: cout << "Wybrales zla opcje." << endl;
			break;
		}
	}
}