//花生米二
#include <iostream>
using namespace std;

int n;
int dp[1001];

/**
 * 经典巴什博奕
 * 或许你看过名学吗
 * 
 * 当Jerry后手时：1, 3, 5, 7, 9, 11为必胜，dp赋值1
 * 当i颗花生米减掉1/5/10可以推导至必胜态时，需要先手，将局面稳定在必胜
*/
int main()
{
    dp[1] = dp[3] = dp[5] = dp[7] = dp[9] = dp[11] = 1;
    for(int i = 12; i <= 1000; i++)
    {
        if(dp[i - 1] && dp[i - 5] && dp[i - 10])
            dp[i] = 0;
        else
            dp[i] = 1;
    }
    while(cin >> n, n)
    {
        if(dp[n])
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}