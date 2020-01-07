#include <iostream>
#include <vector>

using namespace std;

void odpowiedz(vector<int>);
void t(vector<int>);

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
    /* for (int i = 0; i < graf.size(); i++)
    {
        cout << graf[i] << endl;
    } */

    //t(graf);

    odpowiedz(graf);

    return 0;
}

void odpowiedz(vector<int> graf)
{

    int a = graf[0], b = graf[1], temp = 0, temp2 = 0, maks = 0;
    vector<int> wierzcholki, wynik, tempy;

    for (int i = 0; i < graf.size() - 2; i += 2)
    {
        if (a < graf[i])
        {
            maks = graf[i];
            temp = a;
            a = graf[i];
            graf[i] = temp;
            if(maks < graf[i+1]) maks = graf[i+1];
            temp2 = b;
            b = graf[i + 1];
            graf[i + 1] = temp2;
        }
    }

    for (int i = 0; i < maks; i++)
    {
        tempy.push_back(0);
    }
    
    for (int i = 0; i < graf.size(); i++)
    {
        if (temp != graf[i])
        {
            if (i==0)
            {
                wierzcholki.push_back(graf[i]);
                temp = graf[i];
            }
            cout << "Inside for 1: " << i << endl;
            for (int j = 0; j < wierzcholki.size(); j++)
            {
                cout << "Inside for 2: " << j << endl;
                if(graf[i] != wierzcholki[j])
                {
                    tempy[graf[i] - 1]++;
                }
            }
            
        }
        
    }

    for (int i = 0; i < wierzcholki.size(); i++)
    {
        cout << wierzcholki[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < graf.size() - 2; i += 2)
    {
        for (int j = 0; j < wierzcholki.size() - 1; j++)
        {
            if (((graf[i] == wierzcholki[j]) && (graf[i + 1] == wierzcholki[j + 1])) || ((graf[i] == wierzcholki[j + 1]) && (graf[i + 1] == wierzcholki[j])))
            {
                wynik.push_back(graf[i]);
                wynik.push_back(graf[i + 1]);
            }
        }
    }

    cout << "1: ";
    for (int i = 0; i < wynik.size(); i++)
    {
        cout << wynik[i] << " ";
    }
    cout << "2: " << wynik.size();
    /*for (int i = 1; i < wynik.size() - 1; i+=2)
        {
            cout << wynik[i] << " ";
        } */
}

void t(vector<int> graf)
{
    int a = graf[0], b = graf[1], c = 0;

    cout << a << " " << b << " " << c << endl;
    vector<int> sam;

    cin >> a;
    sam.push_back(a);
    cout << sam[0];
}