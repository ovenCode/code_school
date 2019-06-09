#include <iostream>

using namespace std;

/*

zalozenia: 7 zbiorow 3-elementowych wynik: 35

wypisanie : { 0, 1, 2} ; { 0, 2, 1} ; { 1, 0, 2} ; { 2, 0, 1} ; { 1, 2, 0} ; 
{ 2, 1, 0} ; { 7/6/5/4/3/2/1; 6/5/4/3/2/1; 5/4/3/2/1}

7! / 3! (7-3)! = 7 * 6 * 5 / 3 * 2 * 1 = 35

*/

// deklaracje funkcji

int dwumian(int, int);
int silnia(int);

//

int main()
{
    // inicjalizacja zmiennych

    int liczba_t = 0;
    cin >> liczba_t;
    int *n = new int[liczba_t];
    int *k = new int[liczba_t];

    // kod glowny

    for (int i = 0; i < liczba_t; i++)
    {
        cin >> *(n + i) >> *(k + i);
    }

    cout << dwumian(*n,*k) << endl;

    // release of mem

    delete[] n;
    delete[] k;

    // return statement

    return 0;
}

// definicje funkcji

int dwumian(int a, int b)
{
    return silnia(a) / (silnia(b) * silnia(a - b));
}

int silnia(int x)
{
    if (x - 1 == 1)
        return x;
    x = x * silnia(x - 1); // x = 3 x = 3 * silnia(2) x = 3 * 2 * silnia(1)
    return x;
}