#include <iostream>

using namespace std;

/*  PROGRAM DESCRIPTION

0 north 1 south 2 west 3 east
1 do 10 000 krokow
pole 20 000 x 20 000
3 5

*/

// FUNCTION DECLARATION

int dCode(int);

//

int main()
{
    // VARIABLES INITIALAZATION

    int ile_zest = 0, ile_wskaz = 0, kierunek = 0, ile_krok = 0;

    // MAIN CODE

    cin >> ile_zest;
    for (int i = 0; i < ile_zest; i++)
    {
        cin >> ile_wskaz;
        dCode(ile_wskaz);
    }

    // RETURN STATEMENT

    return 0;
}

// FUNCTION DEFINITION

int dCode(int c)
{
    // VARIABLES INITIALIZATION

    int *x = new int [c];
    int *y = new int [c];
    const int s = c;
    int a = 0, b = 0;
    int **map = new int * [c];

    // CODING


    for (int i = 0; i < c; i++)
    {
        *(map + i) = new int [c]; 
        cin >> a >> b;
        *(x + i) = a;
        *(y + i) = b;
        for (int j = 0; j < c; j++)
        {
            if((a == 0) && (i % 2 == 0)) map[i][j] = b;
            else if((a == 1) && (i % 2 == 0)) map[i][j] = -b;
            else if((a == 2) && (i % 2 == 1)) map[i][j] = -b;
            else if((a == 3) && (i % 2 == 1)) map[i][j] = b;
        }
    }
    
    
    // DECODING

    for (int i = 0; i < c;)
    {
       for (int j = 0; j < c - 1; j++)
       {
           a = map[i][j] + map[i][j+1];
       }
        i = i + 2;     
    }

    for (int i = 1; i < c;)
    {
        for (int j = 0; j < c - 1; j++)
       {
           b = map[i][j] + map[i][j+1];
       }
       i = i + 2;
    }

    if((a > 0) && (b > 0)) cout << "Idz " << a << " na polnoc i " << b << " na wschod" << endl;
    if((a < 0) && (b > 0)) cout << "Idz " << -a << " na poludnie i " << b << " na wschod" << endl;
    if((a > 0) && (b < 0)) cout << "Idz " << a << " na polnoc i " << -b << " na zachod" << endl;
    if((a < 0) && (b < 0)) cout << "Idz " << -a << " na poludnie i " << -b << " na zachod" << endl;
    
    return a;
}