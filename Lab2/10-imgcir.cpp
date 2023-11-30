//求图像的周长
#include <iostream>
using namespace std;

int m, n, x, y;
char img[100][100];
int nextstep[8][2] = {0, -1,  -1, 0,  0, 1,  1, 0,  -1, -1,  -1, 1,  1, 1,  1, -1};
int used[100][100], cir[100][100];

/**
 * 深搜进行边长统计
 * 
 * 每个像素有八中延伸方式，判断每一种延伸方式是否符合条件
 * 如果符合条件，判断这一种延伸方式对于边长的影响
*/
void dfs(int x, int y)
{
    used[x][y] = 1;
    for(int i = 0; i < 8; i++)
    {
        int nx = x + nextstep[i][0], ny = y + nextstep[i][1];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && img[nx][ny] == 'X' && used[nx][ny] == 0)
        {
            used[nx][ny] = 1;
            int count = 0;
            for(int j = 0; j < 4; j++)
            {
                if(img[nx + nextstep[j][0]][ny + nextstep[j][1]] == 'X' && used[nx + nextstep[j][0]][ny + nextstep[j][1]] == 1)
                    count++;
            }
            if(count == 0)
                cir[nx][ny] = cir[x][y] + 4;
            else if(count == 1)
                cir[nx][ny] = cir[x][y] + 2;
            else if(count == 2)
                cir[nx][ny] = cir[x][y];
            else if(count == 3)
                cir[nx][ny] = cir[x][y] - 2;
            else
                cir[nx][ny] = cir[x][y] - 4;

            dfs(nx, ny);
        }
    }
}

int main()
{
    int num = 0;
    while(cin >> m >> n >> x >> y, m || n || x || y)
    {
        for(int i = 0; i < m; i++)
            cin >> img[i];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                used[i][j] = 0, cir[i][j] = 0;
        }
        cir[x - 1][y - 1] = 4;
        dfs(x - 1, y - 1);
        
        int result = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                result = result > cir[i][j] ? result : cir[i][j];
            }
        }
        cout << result << endl;
    }
    return 0;
}