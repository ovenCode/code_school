#include <iostream>
using namespace std;

void count(int *, int *,int);

int main() {
	// your code goes 
	
	int t = 0, n = 0;
	int *x,*y;
	
	cin >> t;
	
	for(int i = 0;i < t;i++)
	{
		cin >> n;
		x = new int [n];
		y = new int [n];
		for(int j = 0;j < n;j++)
		{
			cin >> x[j] >> y[j];
		}
		count(x,y,n);
	}
	return 0;
}

void count(int * x, int * y, n)
{
	int temp1 = 10000, temp2 = 10000;
	
	for(int i = 0, i < n - 1; i++)
	{
		for(int j = 0;j < n - 1; j++)
		{
			if((x[j] > x[j+1]) && (y[j] > y[j+1]))
			{
				temp1 = x[j];
				x[j] = x[j + 1];
				x[j+1] = temp1;
				
			}
		}
	}
}
