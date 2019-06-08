#include <iostream>

using namespace std;

// deklaracje funkcji

int suma(int *, int);

//

int main()
{

// inicjalizacja zmiennych

int l_test = 0, l_liczb = 0, wynik = 0;

// kod glowny

cin >> l_test;
for (int i = 0; i < l_test; i++)
{
    cin >> l_liczb;
    int *l = new int [l_liczb];
    for(int j = 0; j < l_liczb; j++) cin >> *(l + j);
    wynik = suma(l, l_liczb);
    cout << wynik << endl;
}

// return statement

    return 0;
}

// definicje funkcji

int suma(int *a, int s)
{
    int x = 0;
    for (int i = 0; i < s; i++)
    {
        x = x + *(a + i);
    }
    return x;
}