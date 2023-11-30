//计算最大连续子序列和
#include <iostream>
using namespace std;
#define max(a, b) a > b ? a : b;

int n;
int num[1001];
int dp[1000];

void maxsum()
{
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + num[i], num[i]);
    }
    int max;
    for(int i = 1; i <= n; i++)
    {
        if(max < dp[i])
            max = dp[i];
    }
    cout << max << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    maxsum();
    return 0;
}