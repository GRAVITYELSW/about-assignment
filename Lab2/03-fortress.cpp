#include <iostream>
using namespace std;

int n;
char a[4][4];
int plan;
int maxn;

bool canplace(int m)
{
    int sx = m / n;
    int sy = m % n;
    if(a[sx][sy] == 'X')
        return false;
    for(int i = sy; i >= 0; i--)
    {
        if(a[sx][i] == '1')
            return false;
        if(a[sx][i] == 'X')
            break;
    }
    for(int i = sx; i >= 0; i--)
    {
        if(a[i][sy] == '1')
            return false;
        if(a[i][sy] == 'X')
            break;
    }
    return true;
}

void dfs(int m)
{
    if(m == n * n)
        maxn = max(plan, maxn);
    else
    {
        if(canplace(m))
        {
            a[m / n][m % n] = '1';
            plan++;
            dfs(m + 1);
            plan--;
            a[m / n][m % n] = '.';
        }
        dfs(m + 1);
    }
}

int main()
{
    int result[100] = {0};
    int count = 0;
    while((cin >> n) && n)
    {
        plan = maxn = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(0);
        result[count] = maxn;
        count++;
    }
    for(int i = 0; i < count; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}