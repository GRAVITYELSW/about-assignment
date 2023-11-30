//花生米三
#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;

int n;
int dp[1001][1001];

/**
 * res为剩余花生米数量，c为上一次拿的数量
 * 
 * 假设后手必胜，则第一次传入dfs的res为n - 1，最后输出1 - dfs()
 * 
 * 如果res为1，必须后手，返回0
 * 如果当前dp使用过，不为-1，则表明当前局面的先后手已经知道了，直接返回
 * 
 * 遍历所有情况从i到min(res, 2 * c)，下一次为jerry先手，必须全部返回1，如果没有全部返回1，则jerry需要先手
*/
int dfs(int res,int c){
    if(res == 1)
    {
        dp[res][c] = 0;
        return 0;
    }
    if(dp[res][c] != -1)
        return dp[res][c];

    int sign = 1;
    for(int i = 1; i <= min(res, 2 * c); i++)
    {
        sign = sign & dfs(res-i, i);
        if(sign == 0)
            break;
    }
    dp[res][c] = 0;
    if(sign == 0)
        dp[res][c] = 1;
    return dp[res][c];
}
int main(){
    int i, j;
    while(cin >> n, n)
    {
        if(n == 1)
        {
        	cout<< 0 <<endl;
        	continue;
		}
        for(i = 0; i <= 1000; i++)
        {
            for(j = 0; j <= 1000; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << 1 - dfs(n - 1, 1) << endl;
    }
}