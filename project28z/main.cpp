#include <iostream>
#include <string>
#include <vector>

using namespace std;

// FUNCTION DECLARATION

void mbr(vector<int>, char);

//

int main()
{

// MAIN VARIABLES INITIALIZATION

int t = 0, n = 0, x = 0, y = 0, r = 0, z = 0;
char s = ' ';
vector<int> box;

//

cin >> t;

for(int i = 0; i < t; i++)
{
    cin >> n;
    for(int j = 0; j < n; j++)
    {
        cin >> s;
        switch (s)
        {
        case 'p':
            cin >> x >> y;
            box.push_back(x);
            box.push_back(y);
            break;
        case 'c':
                cin >> x >> y >> r;
                box.push_back(x);
                box.push_back(y);
                box.push_back(r);
        break;
        case 'l':
                cin >> x >> y >> r >> z;
                box.push_back(x);
                box.push_back(y);
                box.push_back(r);
                box.push_back(z);
        break;
        default:
            break;
        }
        mbr(box,s);
    }
}



return 0;

}

// FUNCTION DEFINITION

void mbr(vector <int> a, char c)
{
    int left = 0, right = 0, top = 0, bottom = 0;
    if(c == 'p')
    {
        for (int i = 0; i < a.size(); i+2)
        {
            if(a[i] < left)
            {
                left = a[i];
            }
            if(a[i] > right)
            {
                right = a[i];
            }
        }
        for(int i = 1;i < a.size() - 1; i + 2)
        {
            if(a[i] < bottom)
            {
                bottom = a[i];
            }
            if(a[i] > top)
            {
                top = a[i];
            }
        }
        
    }
    else if(c == 'c')
    {

    }
    else if(c == 'l')
    {

    }
}

//