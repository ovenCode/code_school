#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// klasy

class sprzet
{
	const int id;
	static int startId;
	int tempId = 0;

public:
	sprzet() : id(startId++), typ("") {}
	sprzet(const int nrtyp) : id(startId++) { this->typ = typy[nrtyp]; }
	~sprzet();

	// odczyt i zapis atrybutow

	int getId();
	int setId(int);
	string getTyp();
	string setTyp(string);

private:
	string typy[3] = {"rower", "hulajnoga", "rolki"};
	string typ;
};

class osoba
{
public:
	osoba() : id(startId++), wiek(0), nazwisko("") {}
	osoba(int wiek, string nazw) : id(startId++), wiek(wiek), nazwisko(nazw) {}
	~osoba();

	// odczyt i zapis atrybutow

	int getId();
	int setId(int);
	int getWiek();
	int setWiek(int);
	string getNazw();
	string setNazw(string);

private:
	int wiek;
	string nazwisko;
	static int startId;
	const int id;
	int tempId = 0;
};

class wypozyczenie
{
public:
	wypozyczenie();
	wypozyczenie(int typ, int wiek, string nazw) : idS(startId++), idO(startId++), wypS(typ), wypO(wiek, nazw) {}
	~wypozyczenie();

	// odczyt i zapis atrybutow

	int getIdS();
	int setIdS(int);
	int getIdO();
	int setIdO(int);
	sprzet getSprzet(int);
	osoba getOsoba(int);

private:
	const int idS, idO;
	int tempIdS = 0, tempIdO = 0;
	static int startId;
	osoba wypO;
	sprzet wypS;
};

// deklaracje atrybutow zewnetrzne

int sprzet::startId = 0;
int osoba::startId = 0;
int wypozyczenie::startId = 0;

// deklaracje funkcji

string *zapis(vector<wypozyczenie>, fstream &, fstream &, fstream &);
vector<wypozyczenie> stworzObiekty(vector<wypozyczenie>);
vector<wypozyczenie> zapisDoTablic(fstream &, string *);
wypozyczenie *zapisDoTablicW(fstream &);
osoba *zapisDoTablicO(fstream &);
sprzet *zapisDoTablicS(fstream &);

//

int main()
{
	// inicjalizacja zmiennych

	fstream plikS, plikO, plikW;
	int x1 = 0, x2 = 0, x3 = 0;
	string s1 = "", s2 = "";
	string a = "";
	vector<wypozyczenie> wyp;
	string *temp;

	// program

	// przykladowe tworzenie

	cin >> x1;
	cin >> x2;
	cin >> s1;
	sprzet b(x1);
	cout << b.getTyp() << endl;
	cout << b.getId() << endl;
	sprzet c(x2);
	cout << c.getId() << endl;
	cout << c.getTyp() << endl;

	// tworzenie obiektow

	stworzObiekty(wyp);

	// 1 zapis do plikow

	temp = zapis(wyp, plikS, plikO, plikW);

	// 2 odczyt i zapis do tablic obiektow

	zapisDoTablic(plikW, temp);

	// 3 wyswietlanie listy osob

	return 0;
}

// definicje metod klasy w

wypozyczenie::wypozyczenie() : idS(startId++), idO(startId++), wypS(), wypO()
{
}

wypozyczenie::~wypozyczenie()
{
}

int wypozyczenie::getIdS()
{
	return this->idS;
}

int wypozyczenie::setIdS(int x)
{
	this->tempIdS = x;
	return this->tempIdS;
}

int wypozyczenie::getIdO()
{
	return this->idO;
}

int wypozyczenie::setIdO(int x)
{
	this->tempIdO = x;
	return this->tempIdO;
}

sprzet wypozyczenie::getSprzet(int x)
{
	if (wypS.getId() == x)
		return this->wypS;
	else
		return sprzet();
}

osoba wypozyczenie::getOsoba(int x)
{

	if (x == wypO.getId())
		return this->wypO;
	else
		return osoba();
}

// definicje metod klasy o

osoba::~osoba()
{
}

int osoba::getId()
{
	return this->id;
}

int osoba::setId(int x)
{
	this->tempId = x;
	return this->tempId;
}

int osoba::getWiek()
{
	return this->wiek;
}

int osoba::setWiek(int x)
{
	this->wiek = x;
	return this->wiek;
}

string osoba::getNazw()
{
	return this->nazwisko;
}

string osoba::setNazw(string x)
{
	this->nazwisko = x;
	return this->nazwisko;
}

// definicje metod klasy s

sprzet::~sprzet()
{
}

int sprzet::getId()
{
	return this->id;
}

int sprzet::setId(int x)
{
	this->tempId = x;
	return this->tempId;
}

string sprzet::getTyp()
{
	return this->typ;
}

string sprzet::setTyp(string x)
{
	this->typ = x;
	return this->typ;
}

// definicje funkcji

string *zapis(vector<wypozyczenie> wyp, fstream &plikS, fstream &plikO, fstream &plikW)
{
	string a[3] = {"sprzet_do_wyp.txt", "osoby_wyp.txt", "wypozyczenia.txt"};
	string *s = a;
	plikS.open(s[0], fstream::out | fstream::app);
	for (int i = 0; i < static_cast<int>(wyp.size()); i++)
	{ // ID: 9 typ: hulajnoga length: 20 from_pos: 10
		plikS << "ID: " << wyp[i].getSprzet(wyp[i].getIdS()).getId() << " typ: " << wyp[i].getSprzet(wyp[i].getIdS()).getTyp() << endl;
	}
	plikS.close();
	plikO.open(s[1], fstream::out | fstream::app);
	for (int i = 0; i < static_cast<int>(wyp.size()); i++)
	{ // ID: 2 wiek: 20 nazwisko: grands length: 31 from_poz: 24
		plikO << "ID: " << wyp[i].getOsoba(wyp[i].getIdO()).getId() << " wiek: " << wyp[i].getOsoba(wyp[i].getIdO()).getWiek() << " nazwisko: " << wyp[i].getOsoba(wyp[i].getIdO()).getNazw() << endl;
	}
	plikO.close();
	plikW.open(s[2], fstream::out | fstream::app);
	for (int i = 0; i < static_cast<int>(wyp.size()); i++)
	{
		plikW << "ID Sprzetu: " << wyp[i].getIdS() << " ID Osoby: " << wyp[i].getIdO() << endl;
	}
	plikW.close();
	return s;
}

vector<wypozyczenie> stworzObiekty(vector<wypozyczenie> wyp)
{
	int tempI1, tempI2;
	string tempS;

	for (int i = 0; i < 10; i++)
	{
		cout << "Podaj 0 - rower, 1 - hulajnoga, 2 - rolki, wiek osoby wypozyczajacej i nazwisko" << endl;
		cin >> tempI1 >> tempI2 >> tempS;
		wyp.push_back(wypozyczenie(tempI1, tempI2, tempS));
	}
	return wyp;
}

vector<wypozyczenie> zapisdoTablic(fstream &plik, string *s)
{
	vector<wypozyczenie> wyp;
	int tempI1 = 0, tempI2 = 0;
	string tempS = "";
	string *comp = s;
	string tempA[1][3];

	for (int i = 0; i < static_cast<int>(wyp.size()); i++)
	{
		if (*(s + i) == *comp)
		{
			plik >> tempS;
			tempA[0][0] = static_cast<int>(stoi(tempS));
			tempA[0][1] = tempS.substr(11);
			string const answer[1][3];

			wyp.push_back(wypozyczenie(tempI1, tempI2, tempS));
		}
		if (*(s + i) == *(comp + 1))
		{
			plik >> tempI2;
			plik >> tempS;
			wyp.push_back(wypozyczenie(tempI1, tempI2, tempS));
		}
		if (*(s + i) == *(comp + 2))
		{
			plik >> tempI2;
			plik >> tempS;
			wyp.push_back(wypozyczenie(tempI1, tempI2, tempS));
		}
	}

	return wyp;
}

wypozyczenie *zapisDoTablicW(fstream &file)
{
	int x = 0;
	int temp, temp2, i = 0, i2 = 0;
	while (!file.eof())
		x++;
	wypozyczenie *a = new wypozyczenie[x];
	while (file >> temp)
	{
		if (i2 % 2 == 0)
		{
			(a + i)->setIdS(temp);
		}
		else
		{
			(a + i)->setIdO(temp);
			i++;
		}
		i2++;
	}
	file.close();
	return a;
}

osoba *zapisDoTablicO(fstream &file)
{
	int x = 0, temp, i = 0;
	string tempS;
	while (!file.eof())
		x++;
	osoba *a = new osoba[x];
	while (file >> tempS)
	{
		file >> temp;
		(a + i)->setId(temp);
		file >> temp;
		(a + i)->setWiek(temp);
		tempS = tempS.substr(25);
		(a + i)->setNazw(tempS);
		i++;
	}
	file.close();
	return a;
}

sprzet *zapisDoTablicS(fstream &file)
{
	int x = 0, temp, i = 0;
	string tempS;
	while (!file.eof())
		x++;
	sprzet *a = new sprzet[x];
	while (file >> tempS)
	{
		file >> temp;
		(a + i)->setId(temp);
		tempS = tempS.substr(11);
		(a + i)->setTyp(tempS);
		i++;
	}
	file.close();
	return a;
}
