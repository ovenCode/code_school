#include <iostream>
#include <string>

using namespace std;

// inicjalizacja zmiennych globalnych

// deklaracja funkcji

int wtoi(string);
int pot(int, int);
string itos(int);
string sum(char *, int);
bool check(int);
int pMaker(int);
int swapper(int);

//

int main()
{

    // inicjalizacja zmiennych glownych

    int t = 0, n = 0;

    // kod glowny

    cin >> t;
    if ((t > 80) || (t < 1))
        return 0;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if ((n < 1) || (n > 80))
            break;
        pMaker(n);
    }

    // return statement

    return 0;
}

// definicje funkcji

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

/*

OK so the check function has to check is a number is a palindrome. To do so we gotta go through a few steps:

- checking whether its already a palindrome || comparing digits
- if it's not we have to add up the number plus its let's call it mirror reflection || xy + yx
- then we have to repeat the process until we get a palindrome || a proper loop statement

exception #1

a single digit is a palindrome

exception #2

even numbers of digits are a palindrome only if all digits are the same /
odd are a palindrome if all are same with the possibility of any digit in the middle

*/

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
            if (s[i] == s[static_cast<int>(s.length()) - 1 - i])
                y++;
        }
    }

    else
    {
        for (int i = 0; i < static_cast<int>(s.length() / 2); i++)
        {
            if (s[i] == s[static_cast<int>(s.length()) - 1 - i])
                y++;
        }
    }

    if (y == static_cast<int>(s.length() / 2))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
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

    int *j = new int[i - 1];
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

    char *c = new char[i];
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

string sum(char *x, int y)
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

int pMaker(int x)
{
    int i = 0;
    while (check(x) == false)
    {
        x = x + swapper(x);
        i++;
    }
    cout << x << " " << i << endl;
    return x;
}

// PAST VERSIONS OF CODE (KEEPING ICE)

//   while (y == 0)
//     {
//         for (int i = 0; i < static_cast<int>(s.length()); i++)
//         {
//             if (s.length() == 1)
//             {
//                 x += x;
//                 s = itos(x);
//             }
//             else if (s.length() == 2)
//             {
//                 if (s[i] == s[i + 1])
//                 {
//                     x = wtoi(s);
//                     // y = 1;
//                     break;
//                 }
//                 else
//                 {
//                     x = x + swapper(x);
//                     s = itos(x);
//                 }
//             }
//             else if (s.length() == 3)
//             {
//                 if (s[i] == s[i + 2])
//                 {
//                     x = wtoi(s);
//                     // y = 1;
//                     break;
//                 }
//                 else
//                 {
//                     x = x + swapper(x);
//                     s = itos(x);
//                 }
//                 if (y == 10)
//                     return x;
//             }
//         }
//         count++;
//         if (count == pot(10, 6))
//         {
//             cout << "Palindrom nie istnieje ponizej 1 000 000" << endl;
//             y = 1;
//         }
//     }