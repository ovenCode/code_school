1. stoin
2. powe
3. itos

int stoin(string s)
{
    int x = 0;

    for(int i = 0; i < s.length(); i++)
    {
        x = x + (s[i] - 48) * powe(10,s.length() - i - 1);
        
    }
    return x;
}

int powe(int x, int y)
{
    int temp = 0;
    
        for(int i = 0; i < y;i++)
    {
        if(i == 0)
        {
        	temp = 1;
        	continue;
        }
        if(i == 1)
        {
        	temp = x;
            
        }
        temp = temp * x;
    }
    if(y == 0) temp = 1;
    if(y == 1) temp = x;
    
    return temp;
}

string itos(int x)
{
    int a = 0, b = 0;
    char c = ' ';
    string s = "";
	
	
    while (x > powe(10,a))
    {
        a++;
    }
	a--;
	
    for (int i = 0; i < powe(10,a); i++)
    {
        while (b * powe(10,a) < x)
        {
            b++;
        }
        if(b * powe(10,a) != x) b--;
        
        s = s + (char)(b + 48);
        
        x = x - b*powe(10,a);
        a--;
        b = 0;
    }
    

    return s;
}