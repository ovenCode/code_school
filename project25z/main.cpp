#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATION



//

int main()
{

// MAIN VARIABLES INITIALIZATION

int T = 0, P = 0, C = 0, M = 0, B = 0, W = 0; // T - test cases, P - number of pins, C - number of colours, M - number of already played guesses, B - black points, W - white points
int * S = 0, * G = 0, * H = 0;

//

cin >> T;

for (int i = 0; i < T; i++)
{
    cin >> P >> C >> M;
    S = new int [P];
    G = new int [P];
    H = new int [2*P];

    for (int j = 0; j < M; j++)
    {

        for (int k = 0; k < P; k++)
        {
            cin >> G[k];
        }
        cin >> B >> W;

        if (W > 0)
        {

            // for (int k = 0; k < P; k++)
            // {
            //     S[k] = G[k];
            // }
            
            // if (B == P)
            // {
                
            //     for (int k = 0; k < P; k++)
            //     {
            //         cout << G[k] << " ";
            //     }
                
            // }
            
        }
        
        
    }
    
}


return 0;

}

// FUNCTION DEFINITION



//

/*

POTENTIAL SOLUTION

cin >> T >> P >> C >> M;

M:
0 1 2 ... P
B W

*/