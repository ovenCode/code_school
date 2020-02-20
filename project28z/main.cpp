#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATION



//

int main()
{

// MAIN VARIABLES INITIALIZATION

int t = 0, n = 0, x = 0, y = 0, r = 0, z = 0;
char s = ' ';

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
            break;
        case 'c':
        break;
        case 'l':
        break;
        default:
            break;
        }
    }
}

return 0;

}

// FUNCTION DEFINITION



//