//石子合并
//区间类型动态规划，dp为前缀和数组，有了dp可以计算任意区间数字和
#include <iostream>
#include <cmath>
using namespace std;

int stone[42], s[42], dp[42][42];
/**
 * 动态规划问题
 * 
 * 最终合并最小值 = 所有石子堆数量 + 左堆最小合并值 + 右堆最小合并值
 * 递归树
 * 考虑环形问题，将环形变成线性，即2 * n
 * 
 * 从0-n，计算所有个数为一堆的最小值，储存在dp中，最后选取最小的
*/
int main()
{
    int n;
    while(cin >> n, n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> stone[i];
            stone[n + i] = stone[i];
        }
        for(int i = 0; i < 2 * n; i++)
        {
            s[i] = s[i - 1] + stone[i];
        }
        for(int i = 0; i < 2 * n; i++)
        {
            for(int j = 0; j < 2 * n; j++)
            {
                if(i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 << 30;
            }
        }       
        for(int l = 0; l < 2 * n; l++)
        {
            for(int i = 0; i < 2 * n - l; i++)
            {
                int j = i + l;
                for(int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }   
        int result = 1 << 30;
        for(int i = 0; i < n; i++)
            result = min(result, dp[i][i + n - 1]);
        cout << result << endl;
    }
    return 0;
}