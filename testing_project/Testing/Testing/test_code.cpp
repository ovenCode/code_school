#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// CLASS

class someClass
{
private:
	int x;
	string s;

public:
	someClass();
	someClass(int x, string s) : x(x), s(s) {}
	~someClass();
	int getX();
	int setX(int);
	string getS();
	string setS(string);
};

someClass::someClass() : x(0), s("-")
{
}

someClass::~someClass()
{
}

// GLOBAL VARIABLES

// FUNCTIONS DECLARATIONS

void showSomeClass(someClass[], int);
void count(fstream &);
void read(ifstream &, ofstream &);
someClass *toArray();
int wtoi(string);
int pot(int, int);
string itos(int);
string sum(char*, int);
bool check(int);
int pMaker(int);
int swapper(int);

//

int main()
{
	//  VARIABLES

	// someClass *p = toArray();
	/*ofstream plik("temp1.txt", ios::app);
	ifstream plik2("temp1.txt");
	int x = 0;
	string s = "-";*/

	//  MAIN CODE

	// SOME PREVIOUS WORK

	//   showSomeClass(p, 5);
	//file.open("stop.txt");
	//plik.open("temp.txt", ios::in | ios::out);
	//if (file.is_open()) cout << "this one works" << endl;
	//if (plik.is_open())
	//{
	//	cin >> x >> s;
	//	plik >> x;
	//	// plik << s;
	//	plik.close();
	//}
	//else cout << "im not working properly" << endl;
	//   cout << "now let's count " << endl;
	//   count(plik);
	// cin >> x >> s;
	// plik.open("temp2.txt", fstream::in | fstream::out);
	// plik << x;
	// plik << s;
	// plik.close();
	// plik.clear();
	// plik2.open("temp3.txt");
	/*read(plik2, plik);*/

	// CURRENT TEST

	cout << itos(36) << endl;
	cout << pMaker(28) << endl;	
	
	// RETURN STATEMENT

	return 0;
}

// METHODS DEFINITIONS

int someClass::getX()
{
	return this->x;
}

int someClass::setX(int x)
{
	this->x = x;
	return this->x;
}

string someClass::getS()
{
	return this->s;
}

string someClass::setS(string s)
{
	this->s = s;
	return this->s;
}

// FUNCTIONS DEFINITIONS

void showSomeClass(someClass c[], int x)
{
	for (int i = 0; i < x; i++)
	{
		cout << c[i].getX() << " " << c[i].getS() << endl;
	}
}

void count(fstream &f)
{
	int x = 0, i = 0;
	string s = "", j = "";
	f.open("temp.txt", ios::in | ios::out);
	if (f.is_open())
	{
		cout << "You're in count" << endl;
		f >> x;
		cout << x << endl;
		while (getline(f, s))
		{
			i++;
			cout << s << " " << i << endl;
			// x = stoi(s);
			if (x == 14)
			{
				cout << "It's the " << i << " line" << endl;
			}
		}
		f.close();
	}
	else
	{
		cout << "Can't open file" << endl;
	}
}

void read(ifstream &f, ofstream &f2)
{
	int x;
	string s;
	f.open("temp1.txt");
	f >> x >> s;
	if (f.is_open())
	{
		f2.open("temp1.txt");
		f2 << x << " i " << s << endl;
	}
	f.close();
	f2.close();
	f.clear();
}

someClass *toArray()
{
	someClass *a = new someClass[5];
	int x[5] = {10, 56, 14, 43, 27};
	string s[5] = {"a", "b", "c", "d", "e"};

	for (int i = 0; i < 5; i++)
	{
		(a + i)->setX(x[i]);
		(a + i)->setS(s[i]);
	}

	return a;
}

int wtoi(string s)
{
	int z = 0;
	char c = 0, check = s[0];
	int j = static_cast<int>(s.length());
	if (check != '-')
	{
		for (int i = 0; i < static_cast<int>(s.length()); i++)
		{
			c = s[i];
			z = z + pot(10, j - 1) * (c - 48);
			j--;
		}
	}
	else
	{
		for (int i = 1; i < static_cast<int>(s.length()); i++)
		{
			c = s[i];
			z = z + pot(10, j - 2) * (c - 48);
			j--;
		}
		z = z * (-1);
	}

	return z;
}

int pot(int x, int y)
{
	int z = 1;
	for (int i = 0; i < y; i++)
	{
		z = z * x;
	}
	return z;
}

string itos(int x)
{
	string s = "";

	// defining the x with an upper limit and lower limit

	int i = 0, count = 0, sign = 0;
	if (x < 0)
	{
		x = x * (-1);
		sign = 1;
	}
	while (x >= pot(10, i))
	{
		i++;
	}

	// transcription of number into digits

	int* j = new int[i - 1];
	int pow = i - 1, y = x;
	for (int l = 0; l < i; l++)
	{
		for (int k = 0; k < 10; k++)
		{
			*(j + l) = k;
			if (*(j + l) * pot(10, pow) > y)
			{
				*(j + l) = *(j + l) - 1;
				y = y - *(j + l) * pot(10, pow);
				pow--;
				break;
			}
		}
	}

	// trancription of digits into chars

	char* c = new char[i];
	for (int k = 0; k < i; k++)
	{
		c[k] = j[count] + 48;
		count++;
	}

	// transcription of chars into single string

	for (int l = 0; l < i - 1; l++)
	{
		if (sign == 0)
			s = sum(c, i);
		else
			s = "-" + sum(c, i);
	}

	// cleaning up mem

	// delete[] c;
	// delete[] j;

	// return statement

	return s;
}

string sum(char* x, int y)
{
	string z = "";
	for (int i = 0; i <= y; i++)
	{
		if (i != y)
		{
			z = z + *(x + i);
		}
		else
			continue;
	}
	return z;
}

int swapper(int x)
{
	string s = itos(x);
	int j = static_cast<int>(s.length());
	string temp = "a";
	if (j == 1)
		return x;

	for (int i = 0; i < static_cast<int>(s.length() / 2); i++)
	{
		temp[0] = s[i];
		s[i] = s[j - 1];
		s[j - 1] = temp[0];
		j--;
	}
	x = wtoi(s);

	return x;
}

bool check(int x)
{
	string s = itos(x);
	int y = 0, count = 0;

	// exception $1

	if (static_cast<int>(s.length()) == 1)
		return x;

	// exception $2

	else if (static_cast<int>(s.length()) % 2 == 0)
	{
		for (int i = 0; i < static_cast<int>(s.length() / 2); i++)
		{
			if (s[i] == s[static_cast<int>(s.length()) - 1 - i]) y++;
		}

	}

	else // if (static_cast<int>(s.length()) % 2 == 1)
	{
		for (int i = 0; i < static_cast<int>(s.length() / 2); i++)
		{
			if (s[i] == s[static_cast<int>(s.length()) - 1 - i]) y++;
		}
	}

	if (y == static_cast<int>(s.length() / 2))
	{
		return true;
	}
	else
	{
		cout << "Palindrom nie istnieje" << endl;
		return false;
	}
	return false;
}

int pMaker(int x)
{
	int i = 0;
	while (check(x) == false)
	{
		x = x + swapper(x);
		i++;
	}
	cout << "Aby znalezc palindrom zajelo to " << i << " dodawan" << endl;
	return x;
}