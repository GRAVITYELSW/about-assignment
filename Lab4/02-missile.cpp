//防卫导弹
#include <iostream>
using namespace std;
#define max(a, b) a > b ? a : b;

int n[100], dp[100][100];
int height[100][100];

void maxnum(int k)
{
    int result = 0;
    for(int i = 0; i < n[k]; i++)
    {
        dp[k][i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(height[k][j] >= height[k][i])
                dp[k][i] = max(dp[k][i], dp[k][j] + 1);
        }
    }
    for(int i = 0; i < n[k]; i++)
    {
        result = max(result, dp[k][i]);
    }
    cout << result << endl;
}

int main()
{
    int num, i = 0;
    while(cin >> num, num)
    {
        n[i] = num;
        for(int m = 0; m < num; m++)
            cin >> height[i][m];
        maxnum(i);
        i++;
    }
    return 0;
}