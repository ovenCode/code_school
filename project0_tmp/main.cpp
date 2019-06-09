/*
Program use:
checking if a number pair is readable both sides else adding the values together
*/
#include <iostream>
#include <string>

using namespace std;

// declaration of variables

int val;
string temp;

// declaration of functions

bool checker(int);
string ctos(char);
string reverse (string);

//

int main()
{
    cin >> val;
    if (!checker(val))
    {
        string t,s;
        t = to_string(val);
        s = reverse(t);
        for(int i = 0;i<static_cast<int>(t.length());i++) val = stoi(ctos(t[i]))*i + stoi(ctos(s[i]))*i;
    }
    else
    {
        cout << "brawo" << endl;
    }
    return 0;
}

// definition of functions

bool checker(int a)
{
    string s;
    int temp;
    s = to_string(a);
    if (static_cast<int>(s.length()) == 1)
        return false;
    reverse(s);
    if (s == to_string(a))
        return true;
    else return false;
}

string ctos(char x)
{
	string s(1, x);

	return s;
}

string reverse(string s)
{
    char l;
    for (int i = 0; i < static_cast<int>(s.length()); i++)
    {
        for (int k = static_cast<int>(s.length()); k >= 0; k--)
        {
            l = s[i];
            s[i] = s[k];
            s[k] = l;
        }
    }
    return s;
}