//滑雪问题
#include <iostream>
using namespace std;

int r, c;
int height[100][100], dp[100][100];
int nextstep[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};

/**
 * 动态规划-记忆化搜索
 * 每一点向四方扩展，如果满足条件，即x、y不超过边界且下一点高度比当前点低，则可以继续向下走，当前点dp为dp与下一点+1的最大值
 * 
 * 如果此点已经走过不为0，即已经获得了此点的max高度，则直接返回
*/
int updatedp(int x, int y)
{
    if(dp[x][y] != 0)
        return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + nextstep[i][0], ny = y + nextstep[i][1];
        if(height[x][y] > height[nx][ny] && nx >=0 && nx < r && ny >= 0 && ny < c)
            dp[x][y] = max(dp[x][y], updatedp(nx, ny) + 1);
    }
    return dp[x][y];
}

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> height[i][j];
    }
    int result = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            result = max(result, updatedp(i, j));
    }
    cout << result << endl;
    return 0;
}