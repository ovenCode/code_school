#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATION

string transform(string);

//

int main()
{

// MAIN VARIABLES INITIALIZATION

int t = 0;
string * expression = 0;

//

cin >> t;
expression = new string [t];
for (int i = 0; i < t; i++)
{
    cin >> *(expression + i);
    transform(*(expression + i));
}


return 0;

}

// FUNCTION DEFINITION

string transform(string a)
{

}

//