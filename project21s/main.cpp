#include <iostream>
#include <vector>

using namespace std;

void odpowiedz(vector <int>);

int main()
{
    int n = 0, m = 0, wierzI = 0, wierzJ = 0;
    vector <int> graf;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> wierzI >> wierzJ;
        graf.push_back(wierzI);
        graf.push_back(wierzJ);
    }
    
    odpowiedz(graf);

    return 0;
}

void odpowiedz(vector <int> graf)
{

    int a = graf[0], b = graf[1], temp = 0, temp2 = 0;

    for (int i = 2; i < graf.size(); i + 2)
    {
        if (a < graf[i])
        {
            temp = a;
            a = graf[i];
            graf[i] = temp;
            temp2 = b;
            b = graf[i-1];
            graf[i-1] = temp2;
        }
        
    }
    

    cout << "1: " << endl;
    cout << "2: " << endl;
}