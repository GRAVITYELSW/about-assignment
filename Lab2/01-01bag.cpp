#include <iostream>
using namespace std;

int n[100], c[100];
int w[100][10], p[100][10];
int maxv[100] = {0};

void dfs(int n, int c, int i, int tw, int tv, int k)
{
    if(i == n)
    {
        if(tw <= c && tv > maxv[k])
        {
            maxv[k] = tv;
        }
    }
    else
    {
        if(tw + w[k][i] <= c)
        {
            dfs(n, c, i + 1, tw + w[k][i], tv + p[k][i], k);  
        }
        
        dfs(n, c, i + 1, tw, tv, k);
    }
}

int main()
{
    int i, j;
    int count = 0;
    while(cin >> i >> j)
    {
        if(i != 0 || j != 0)
        {
            n[count] = i, c[count] = j;
            for(int k = 0; k < n[count]; k++)
            {
                cin >> w[count][k];
            }
            for(int k = 0; k < n[count]; k++)
            {
                cin >> p[count][k];
            }
            count++;
        }
        else
            break;
    }
    for(int k = 0; k < count; k++)
    {
        dfs(n[k], c[k], 0, 0, 0, k);
        cout << maxv[k] << endl;
    }
    return 0;
}