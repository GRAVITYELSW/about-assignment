//01背包问题
#include <iostream>
using namespace std;
#define max(a, b) a > b ? a : b;

int c, n;
int weight[1001], dp[1001][1001];

void maxweight()
{
    for(int i = 1; i <= c; i++)
    {
        for(int left = 1; left <= n; left++)
        {
            if(left < weight[i])
                dp[i][left] = dp[i - 1][left];
            else
                dp[i][left] = max(dp[i - 1][left], dp[i - 1][left - weight[i]] + weight[i]);
        }
    }

    cout << dp[c][n] << endl;
}

int main()
{
    cin >> c >> n;
    for(int i = 1; i <= c; i++)
        cin >> weight[i];
    maxweight();
    return 0;
}