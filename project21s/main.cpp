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

    for (int i = 0; i < graf.size(); i += 2)
    {
        if ((a <= graf[i]) && (graf[i] > graf[i + 1]))
        {
            maks = graf[i];
        }
        else if ((a <= graf[i]) && (graf[i] < graf[i + 1]))
        {
            maks = graf[i + 1];
        }

        if (a < graf[i])
        {
            temp = a;
            a = graf[i];
            graf[i] = temp;
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
       
        if (i==0)
        {
            wierzcholki.push_back(graf[i]);
        }
        for (int j = 0; j < wierzcholki.size(); j++)
        {
            if((graf[i] != wierzcholki[j]) && (graf[i] < wierzcholki[j]))
            {
                if (tempy[i] < 1)
                {
                    wierzcholki.push_back(i);
                }
                tempy[graf[i] - 1]++;
                if (i < tempy.size())
                {
                    i++;
                }
                else continue;
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

/*
1
5
1 2
1 3
1 4
2 4
4 6
 */