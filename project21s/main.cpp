#include <iostream>
#include <vector>

using namespace std;

void odpowiedz(vector<int>);

int main()
{
    int n = 0, m = 0, wierzI = 0, wierzJ = 0;
    vector<int> graf;
    cin >> n >> m;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> wierzI >> wierzJ;
            graf.push_back(wierzI);
            graf.push_back(wierzJ);
        }
    }
    odpowiedz(graf);

    return 0;
}

void odpowiedz(vector<int> graf)
{

    int a = graf[0], b = graf[1], temp = 0, temp2 = 0;
    vector<int> wierzcholki, wynik;

    for (int i = 2; i < graf.size(); i + 2)
    {
        if (a < graf[i])
        {
            temp = a;
            a = graf[i];
            graf[i] = temp;
            temp2 = b;
            b = graf[i - 1];
            graf[i - 1] = temp2;
        }
    }

    for (int i = 0; i < graf.size(); i++)
    {
        if (graf[i] != graf[i + 1])
        {
            wierzcholki.push_back(graf[i]);
        }
        if (graf[i + 1] == graf.size())
            continue;
    }

    temp = wierzcholki.size();

    for (int i = 0; i < graf.size(); i+2)
    {
        for (int j = 0; j < wierzcholki.size(); j++)
        {
            if (((graf[i] == wierzcholki[i]) && (graf[i-1] == wierzcholki[i-1])) || ((graf[i] == wierzcholki[j-1]) && (graf[i-1] == wierzcholki[j])))
            {
                wynik.push_back(graf[i]);
                wynik.push_back(graf[i-1]);
            }
            
        }
        
        
    }
    

    cout << "1: ";
    for (int i = 0; i < wynik.size(); i+2)
    {
        cout << wynik[i] << " ";
    }
    cout << "2: " << endl;
    for (int i = 1; i < wynik.size(); i+2)
    {
        cout << wynik[i] << " ";
    }
}