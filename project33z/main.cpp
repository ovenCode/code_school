#include <iostream>
#include <string>


using namespace std;

void needle(string, string, int);

int main()
{
    int x = 0;
    string _needle = " ", _haystack = " ";

    while (cin >> x)
    {
        cin >> _needle >> _haystack;
        needle(_needle,_haystack, x);
    }
    
    return 0;
}

void needle (string s, string _find, int x)
{
    size_t _pos = 0, _operand = 0;
    for (int i = 0; i < _find.size(); i++)
    {
       for (int j = 0; j < s.size(); j++)
       {
           if (s.find(_find,_pos + _operand) != string::npos)
           {
               _pos == s.find(_find,_pos);
               _operand = 1;
               cout << _pos << endl;
           }
           
       }
       
        
    }
    cout << endl;
}