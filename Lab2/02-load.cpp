#include <iostream>
using namespace std;

int c1[100], c2[100], n[100];
int wi[100][10];
int sumw[100] = {0};
int maxw[100] = {0};

void dfs(int k, int tw, int i)
{
    if(i == n[k])
    {
        if(tw <= c1[k] && tw > maxw[k])
            maxw[k] = tw;
    }
    else
    {
        if(tw + wi[k][i] <= c1[k])
            dfs(k, tw + wi[k][i], i + 1);
        dfs(k, tw, i + 1);
    }
}

int main()
{
    int i, j, k;
    int count = 0;
    while(cin >> i >> j >> k)
    {
        if(i != 0 || j != 0 || k != 0)
        {
            c1[count] = i, c2[count] = j, n[count] = k;
            for(int m = 0; m < k; m++)
            {
                cin >> wi[count][m];
            }
            count++;
        }
        else
            break;
    }
    for(int m = 0; m < count; m++)
    {
        for(int p = 0; p < n[m]; p++)
        {
            sumw[m] += wi[m][p];
        }
    }
    for(int m = 0; m < count; m++)
    {
        dfs(m, 0, 0);
        int max2 = sumw[m] - maxw[m];
        if(max2 <= c2[m])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}