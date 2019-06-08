#include <iostream>

using namespace std;

// deklaracja funkcji

int policz(int, int, int, int, int);

//

int main()
{
    // zmienne lokalne

    int ile_zest = 0, ile_obz = 0, ile_ciast = 0, obz[10000], ciast[1000000000], czas[100000], s_dzien = 86400;

    // wypelnienie tablic

    for (int i = 0; i < 10000; i++)
    {
        obz[i] = i;
    }

    for (int i = 0; i < 1000000000; i++)
    {
        ciast[i] = i;
    }

    for (int i = 0; i < 100000; i++)
    {
        czas[i] = i;
    }

    // kod glowny

    cin >> ile_zest;

    for (int i = 0; i < ile_zest; i++)
    {
        cin >> ile_obz;
        cin >> ile_ciast;

        for (int i = 0; i < ile_obz; i++)
        {
            cin >> czas[i];
            ciast[i] = policz(s_dzien, czas[i], ile_ciast, ile_obz, ile_zest);
            cout << ciast[i] << endl;
        }
    }

    // return statement

    return 0;
}

// definicja funkcji

int policz(int x, int y, int w1, int w2, int w3)
{
    int z;
    z = (x / y * w1) / w2;
    cout << z << endl;
    if (((x / y * w1) % w2 != 0))
        x = z + 1;
    else
        x = z;
    return x;
}
