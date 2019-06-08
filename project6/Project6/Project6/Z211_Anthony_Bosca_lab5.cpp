#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// klasy

class sprzet
{
	int id;
	static int startId;
	int tempId;

public:
	sprzet() : id(0), typ("") {}
	sprzet(const int nrtyp) : id(++startId) { this->typ = typy[nrtyp]; }
	~sprzet();

	// odczyt i zapis atrybutow

	int getId();
	int setId(int);
	string getTyp();
	string setTyp(string);

private:
	static string typy[3];
	string typ;
};

class osoba
{
public:
	osoba() : id(0), wiek(0), nazwisko("") {}
	osoba(int wiek, string nazw) : id(++startId), wiek(wiek), nazwisko(nazw) {}
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
	int id;
	int tempId;
};

class wypozyczenie
{
public:
	wypozyczenie();
	wypozyczenie(int typ, int wiek, string nazw) : idS(++startId), idO(startId), wypS(typ), wypO(wiek, nazw) {}
	~wypozyczenie();

	// odczyt i zapis atrybutow

	int getIdS();
	int setIdS(int);
	int getIdO();
	int setIdO(int);
	sprzet getSprzet(int);
	osoba getOsoba(int);

private:
	int idS, idO;
	int tempIdS, tempIdO;
	static int startId;
	osoba wypO;
	sprzet wypS;
};

// deklaracje atrybutow zewnetrzne

int sprzet::startId = 0;
string sprzet::typy[3] = {"rower", "hulajnoga", "rolki"};
int osoba::startId = 0;
int wypozyczenie::startId = 0;

// deklaracje funkcji

string *zapis(vector<wypozyczenie>, ofstream &, ofstream &, ofstream &, string *);
vector<wypozyczenie> stworzObiekty(vector<wypozyczenie>);
vector<wypozyczenie> zapisDoTablic(fstream &, string *);
wypozyczenie *zapisDoTablicW(ifstream &);
osoba *zapisDoTablicO(ifstream &);
sprzet *zapisDoTablicS(ifstream &);
void odczyt(ifstream &, ifstream &, ifstream &);
const char *charify(string *, int);
int wtoi(string);
int pot(int, int);

//

int main()
{
	// inicjalizacja zmiennych

	ifstream plikSI, plikOI, plikWI;
	ofstream plikSO, plikOO, plikWO;
	int x1 = 0, x2 = 0, x3 = 0;
	string s1 = "", s2 = "";
	string a = "";
	vector<wypozyczenie> wyp;
	string s[3] = {"sprzet_do_wyp.txt", "osoby_wyp.txt", "wypozyczenia.txt"};
	string *temp = s;
	string someNumber = "4325";

	// program

	// przykladowe tworzenie

	/*cin >> x1;
	cin >> x2;
	cin >> s1;
	sprzet b(x1);
	cout << b.getTyp() << endl;
	cout << b.getId() << endl;
	sprzet c(x2);
	cout << c.getId() << endl;
	cout << c.getTyp() << endl;*/
	//

	// tworzenie obiektow

	wyp = stworzObiekty(wyp);

	// 1 zapis do plikow

	temp = zapis(wyp, plikSO, plikOO, plikWO, temp);

	// 2 odczyt i zapis do tablic obiektow

	wypozyczenie *wypWz = zapisDoTablicW(plikWI);
	osoba *wypOs = zapisDoTablicO(plikOI);
	sprzet *wypSp = zapisDoTablicS(plikSI);

	// 3 wyswietlanie listy osob

	odczyt(plikWI, plikSI, plikOI);

	// usuwanie pamieci

	delete[] wypWz;
	delete[] wypOs;
	delete[] wypSp;

	// zatrzymanie pliku exe

	cin >> x1;
	return 0;
}

// definicje metod klasy w

wypozyczenie::wypozyczenie() : idS(0), idO(0), wypS(), wypO()
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

string *zapis(vector<wypozyczenie> wyp, ofstream &plikS, ofstream &plikO, ofstream &plikW, string *s)
{
	int check;
	plikS.clear();
	plikO.clear();
	plikW.clear();
	plikS.open(charify(s, 1));
	if (plikS.is_open())
	{
		cin >> check;

		for (int i = 0; i < static_cast<int>(wyp.size()); i++)
		{ // ID: 9 typ: hulajnoga length: 20 from_pos: 10
			plikS << "ID: " << wyp[i].getSprzet(wyp[i].getIdS()).getId() << " typ: " << wyp[i].getSprzet(wyp[i].getIdS()).getTyp() << endl;
		}
	}
	plikS.close();
	plikO.open(charify(s, 2));
	if (plikO.is_open())
	{
		cin >> check;
		for (int i = 0; i < static_cast<int>(wyp.size()); i++)
		{ // ID: 2 wiek: 20 nazwisko: grands length: 31 from_poz: 24
			plikO << "ID: " << wyp[i].getOsoba(wyp[i].getIdO()).getId() << " wiek: " << wyp[i].getOsoba(wyp[i].getIdO()).getWiek() << " nazwisko: " << wyp[i].getOsoba(wyp[i].getIdO()).getNazw() << endl;
		}
	}
	plikO.close();
	plikW.open(charify(s, 3));
	if (plikW.is_open())
	{
		cin >> check;
		for (int i = 0; i < static_cast<int>(wyp.size()); i++)
		{
			plikW << "ID Sprzetu: " << wyp[i].getIdS() << " ID Osoby: " << wyp[i].getIdO() << endl;
		}
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
		wyp.size();
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
			tempA[0][0] = static_cast<int>(wtoi(tempS));
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

wypozyczenie *zapisDoTablicW(ifstream &file)
{
	int x = 0;
	int temp, i = 0, i2 = 0;
	string tempS;
	while (file >> tempS)
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
	return a;
}

osoba *zapisDoTablicO(ifstream &file)
{
	int x = 0, temp, i = 0;
	string tempS;
	while (file >> tempS)
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
	return a;
}

sprzet *zapisDoTablicS(ifstream &file)
{
	int x = 0, temp, i = 0;
	string tempS;
	while (file >> tempS)
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
	return a;
}

void odczyt(ifstream &fileW, ifstream &fileS, ifstream &fileO)
{
	int wiek, id, i = 0;
	string typ, nazw;
	while (fileO >> wiek)
	{
		fileS >> typ;
		typ = typ.substr(11);
		if ((wiek > 25) && (typ == "rower"))
		{
			i++;
		}
	}
	if (i > 0)
		cout << "W naszej wypozyczalni jest " << i << " osob, ktore wypozyczyly rower majac ukonczone 25 lat badz wiecej." << endl;
}

const char *charify(string *s, int x)
{
	string temp;
	char *l_start = 0;
	temp = *(s + x - 1);
	for (int j = 0; j < static_cast<int>(temp.length()); j++)
	{
		*(l_start + j) = temp[j];
	}
	const char *l = l_start;
	return l;
}

int wtoi(string s)
{
	int x = 0;
	char c;
	int j = static_cast<int>(s.length());
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{ // 4 - 3 - 2 - 1
			c = s[i];				   // 4 3 2 5
			x = x + pot(10, j - 1) * (c - 48); // 0 + 10 ^ 3 * 4 = 4000, 4000 + 10 ^ 2 * 3 = 4300, 4300 + 10 ^ 1 * 2
			j--;
	}

	return x;
}
//       10,     3
int pot(int x, int y)
{
	int z = 1;
	for (int i = 0; i < y; i++)
	{
		z = z * x; // 1 1*10 2 10*10 3 100*10
	}
	return z;
}