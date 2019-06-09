#include <iostream>

using namespace std;

// FUNCTION DECLARATION

//

int main()
{

    // VARIABLES INITIALIZATION

    int ile_zest = 0, n = 0;
    long long ile_wspol = 0;
    long *x = new long[n];
    long *y = new long[n];
    long *a = new long[n];
    long *b = new long[n];

    // MAIN CODE

    cin >> ile_zest;
    for (int i = 0; i < ile_zest; i++)
    {
        cout << "in 1st loop" << endl;
        cin >> n;
        if (n % 3 != 0)
        {
            cout << "N musi byc podzielne przez 3" << endl;
            continue;
        }

        // create

        for (int i = 0; i < n; i++)
        {
            cout << "in 2nd loop" << endl;
            cin >> *(a + i) >> *(b + i);
            *(x + i) = *(a + i);
            *(y + i) = *(b + i);
        }

        cout << endl;

        // sort

        for (int i = 0; i < n; i++)
        {
            long temp = 0, temp2 = *x;
            temp = *y;

            for (int j = 0; j < n; j++)
            {
                if ((temp > *(y + j)) && (j > 0))
                { // |         |         |
                    // *y = *(y + i);  // 5 3 1 / 3 5 1 / 1 5 5 /
                    *(y + j - 1) = *(y + j);
                    *(y + j) = temp;
                    *(x + j - 1) = *(x + j);
                    *(x + j) = temp2;
                }
                if ((temp < *(y + j)) && (j < n))
                {
                    temp = *(y + j);
                    temp2 = *(x + j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << *(x + i) << *(y + i) << endl;
        }
    }

    // find

    int counter = n;
    int *delta = new int[n];
    for (int i = 0; i < n; i++) // check if limit should be counter or n
    {
        for (int j = 0; j < counter; j++)
        {
            if ((*(b + i) == *(y + j)) && (i == counter))
            {
                *(delta + i) = i;
                i = 0;
                counter--;
                break;
            }
            continue;
        }
    }
    counter = n;
    for (int i = 0; i < n; i++)
    {
        cout << *(delta + i) << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    } a

    // RETURN STATEMENT

    return 0;
}

// FUNCTION DEFINITION