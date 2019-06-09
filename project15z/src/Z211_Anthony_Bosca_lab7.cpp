#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

class Bryla
{
public:
	Bryla();
	virtual ~Bryla();
	virtual int objetosc();
	virtual int pole_powierzchni_calkowitej();
	virtual int pobierz_dane();

private:
};

class Stozek : public Bryla
{
public:
	Stozek();
	~Stozek();
	int objetosc();
	int pole_powierzchni_calkowitej();
	int pobierz_dane();
	int tworzaca();

private:
	int r, h, l;
};

class Szescian : public Bryla
{
public:
	Szescian();
	~Szescian();
	int objetosc();
	int pole_powierzchni_calkowitej();
	int pobierz_dane();

private:
	int a;
};

class Walec : public Bryla
{
public:
	Walec();
	~Walec();
	int objetosc();
	int pole_powierzchni_calkowitej();
	int pobierz_dane();

private:
	int r, h;
};

class Czworoscian : public Bryla
{
public:
	Czworoscian();
	~Czworoscian();
	int objetosc();
	int pole_powierzchni_calkowitej();
	int wysokosc();
	int pobierz_dane();

private:
	int a, h1, h2;
};

class Prostopadloscian : public Bryla
{
public:
	Prostopadloscian();
	~Prostopadloscian();
	int objetosc();
	int pole_powierzchni_calkowitej();
	int pobierz_dane();

private:
	int a, b, c;
};

// deklaracja funkcji

void obsluga_bryly(Bryla &b);

//

int main()
{
	// inicjalizacja zmiennych

	Bryla *wsk = new Stozek;

	// kod glowny

	wsk->pobierz_dane();
	delete wsk;
	Stozek b;
	obsluga_bryly(b);

	// return statement
	
	return 0;
}

//  definicje metod/konstruktorow klasy bryla

Bryla::Bryla()
{
}

Bryla::~Bryla()
{
}

int Bryla::objetosc()
{
	int a = 0;
	cout << " Bryla ma objetosc " << a << endl;
	return a;
}

int Bryla::pole_powierzchni_calkowitej()
{
	int a = 0;
	cout << " Bryla ma pole powierzchni ca�kowitej o warto�ci " << a << endl;
	return 0;
}

int Bryla::pobierz_dane()
{
	int a = 0;
	cout << " Dane pobrane to " << a << endl;
	return a;
}

//  definicje metod/konstruktorow klasy stozek

Stozek::Stozek()
{
}

Stozek::~Stozek()
{
}

int Stozek::pobierz_dane()
{
	int a, b;
	cin >> a >> b;
	this->r = a;
	this->h = b;
	return a;
}

int Stozek::objetosc()
{
	return (PI * sqrt(r) * h) / 3;
}

int Stozek::pole_powierzchni_calkowitej()
{
	return PI * sqrt(r) + l * 2 * PI * r;
}

int Stozek::tworzaca()
{
	return pow((sqrt(r) + sqrt(h)), 1 / 2);
}

//  definicje metod/konstruktorow klasy szescian

Szescian::Szescian()
{
}

Szescian::~Szescian()
{
}

int Szescian::objetosc()
{
	return pow(this->a, 3);
}

int Szescian::pole_powierzchni_calkowitej()
{
	return 6 * (sqrt(this->a));
}

int Szescian::pobierz_dane()
{
	int a;
	cin >> a;
	this->a = a;
	return this->a;
}

// definicje metod/konstruktorow klasy Walec

Walec::Walec()
{
}

Walec::~Walec()
{
}

int Walec::objetosc()
{
	return PI * sqrt(this->r) * this->h;
}

int Walec::pole_powierzchni_calkowitej()
{
	return (PI * sqrt(this->r) * 2 + 2 * PI * this->r * this->h);
}

int Walec::pobierz_dane()
{
	int a;
	cin >> a;
	this->r = a;
	return this->r;
}

// definicje metod/konstruktorow klasy Czworoscian

Czworoscian::Czworoscian()
{
}

Czworoscian::~Czworoscian()
{
}

int Czworoscian::objetosc()
{
	return (this->a * this->h1 * this->h2 / 6);
}

int Czworoscian::wysokosc()
{
	this->h2 = (sqrt(this->h1) - sqrt(2 * this->h1 / 3));
	return this->h2;
}

int Czworoscian::pole_powierzchni_calkowitej()
{
	return 2 * this->h1 * this->a;
}

int Czworoscian::pobierz_dane()
{
	int x = 0;
	cin >> x;
	this->a = x;
	return this->a;
}

// definicje metod/konstruktorow klasy Prostopadloscian

Prostopadloscian::Prostopadloscian()
{
}

Prostopadloscian::~Prostopadloscian()
{
}

int Prostopadloscian::objetosc()
{
	return this->a * this->b * this->c;
}

int Prostopadloscian::pole_powierzchni_calkowitej()
{
	return (2 * this->a * this->b + 2 * this->c * this->b + 2 * this->a * this->c);
}

int Prostopadloscian::pobierz_dane()
{
	int x = 0;
	cin >> x;
	this->a = x;
	cin >> x;
	this->b = x;
	cin >> x;
	this->c = x;
	return this->a;
}

// definicje funkcji

void obsluga_bryly(Bryla &b)
{
	b.pobierz_dane();
	if (typeid(b).name() == "Szescian")
	{
		cout << "Objetosc szescianu  to " << b.objetosc() << endl;
		cout << "Pole powierzchni calkowitej szescianu  to " << b.pole_powierzchni_calkowitej() << endl;
	}
	else if (typeid(b).name == "Stozek")
	{
		cout << "Objetosc stozka to " << b.objetosc() << endl;
		cout << "Pole powierzchni calkowitej stozka to " << b.pole_powierzchni_calkowitej() << endl;
	}
	else if (typeid(b).name = "Walec")
	{
		cout << "Objetosc walca to " << b.objetosc() << endl;
		cout << "Pole powierzchni calkowitej walca to " << b.pole_powierzchni_calkowitej() << endl;
	}
	
	else if (typeid(b).name = "Czworoscian")
	{
		cout << "Objetosc czworoscianu to " << b.objetosc() << endl;
		cout << "Pole powierzchni calkowitej czworoscianu to " << b.pole_powierzchni_calkowitej() << endl;
	}
	else if (typeid(b).name = "Prostopadloscian")
	{
		cout << "Objetosc prostopadloscianu to " << b.objetosc() << endl;
		cout << "Pole powierzchni calkowitej prostopadloscianu to " << b.pole_powierzchni_calkowitej() << endl;
	}
	else
	{
		cout << "niezidentyfikowana bryla" << endl;
	}
}