#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream f;
    f.open("plik_t.txt");
    if(f.is_open())
    {
        int x = 0;
        cin >> x;
        f << x;
    }
    f.close();
    ifstream f2;
    f2.open("plik_t.txt");
    if(f2.is_open())
    {
        int y = 0;
        f2 >> y;
        cout << y;
    }
    f2.close();
    return 0;
}