//求解最长公共子序列
#include <iostream>
#include <string>
using namespace std;
#define max(a, b) a > b ? a : b;

string A, B;
int lena, lenb;
int dp[200][200];
char LCS[200];

/**
 * 求最长公共子序列长度函数
 * 
 * 状态转移方程：dp[i][j] = 0   i = 0/j = 0边界条件
 *              dp[i][j] = dp[i - 1][j - 1] + 1   a[i - 1] == b[j - 1]
 *              dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])   a[i - 1] != b[j - 1]
 * dp[lena][lenb]为最终结果
*/
void LCSlength()
{
    int i, j;
    for(i = 0; i <= lena; i++)
        dp[i][0] = 0;
    for(j = 0; j < lenb; j++)
        dp[0][j] = 0;
    for(i = 1; i <= lena; i++)
    {
        for(j = 1; j <= lenb; j++)
        {
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[lena][lenb] << endl;
}

/**
 * 求子序列元素的函数
 * 
 * 三种状态
*/ 
void findLCS()
{
    int len = dp[lena][lenb];
    int a = lena, b = lenb;
    while(len > 0)
    {
        if(dp[a][b] == dp[a - 1][b])
            a--;
        else if(dp[a][b] == dp[a][b - 1])
            b--;
        else
        {
            LCS[len] = A[a - 1];
            a--, b--, len--;
        }
    }
    for(len = 1; len <= dp[lena][lenb]; len++)
        cout << LCS[len];
    cout << endl;
}

int main()
{
    cin >> A >> B;
    lena = A.length(), lenb = B.length();
    LCSlength();
    findLCS();
    return 0;
}