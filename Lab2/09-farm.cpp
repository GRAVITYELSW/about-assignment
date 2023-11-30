//农场灌溉问题
#include <iostream>
using namespace std;

int m, n;
char farm[100][100];
int out[128][5];
bool used[100][100];
int nextstep[4][2] = {0, -1,  -1, 0,  0, 1,  1, 0};

void init() //左上右下，有出口的赋1，对所有农场进行初始化
{
    out['A'][0] = 1, out['A'][1] = 1;

    out['B'][1] = 1, out['B'][2] = 1;

    out['C'][0] = 1, out['C'][3] = 1;

    out['D'][2] = 1, out['D'][3] = 1;

    out['E'][1] = 1, out['E'][3] = 1;

    out['F'][0] = 1, out['F'][2] = 1;

    out['G'][0] = 1, out['G'][1] = 1, out['G'][2] = 1;

    out['H'][0] = 1, out['H'][1] = 1, out['H'][3] = 1;

    out['I'][0] = 1, out['I'][2] = 1, out['I'][3] = 1;

    out['J'][1] = 1, out['J'][2] = 1, out['J'][3] = 1;

    out['K'][0] = 1, out['K'][1] = 1, out['K'][2] = 1, out['K'][3] = 1;
}

/**
 * 深搜进行灌溉渠选择
 * 
 * 将所有连通的农田分为一类，并used赋为1
 * 每一块农田均遍历左上右下，如果有一个方向是连通的，则进入搜索
*/
void dfs(int x, int y)
{
    used[x][y] = 1;
    int nx, ny;
    for(int i = 0; i < 4; i++)
    {
        nx = x + nextstep[i][0], ny = y + nextstep[i][1];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && used[nx][ny] == 0)
        {
            if(out[farm[x][y]][i] && out[farm[nx][ny]][(i + 2) % 4])
                dfs(nx, ny);
        }
    }
}

int main()
{
    init();
    while(cin >> m >> n, m != -1 || n != -1)
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                used[i][j] = 0;
        for(int i = 0; i < m; i++) 
            cin >> farm[i];

        int num = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(!used[i][j]) 
                {   
                    dfs(i, j);
                    num++;
                }
            }
        cout << num << endl;
    }
    return 0;
}