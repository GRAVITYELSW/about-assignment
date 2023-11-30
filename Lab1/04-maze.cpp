#include <iostream>
using namespace std;

int H[4] = {0, 1, 0, -1};
int V[4] = {-1, 0, 1, 0};
int judge = 0;

void DFS(int in_x, int in_y, int m, int n, int out_x, int out_y, int maze[][20])
{
    //一定要加这个判断。。。不然过不了。。。我是sb
    if(judge == 1)
        return;
    if(in_x == out_x && in_y == out_y)
    {
        maze[in_x][in_y] = -1;
        judge = 1;
        return;
    }                                                                                                                     
    for(int i = 0; i < 4; i++)
    {
        if(in_x >= 0 && in_y >= 0 && in_x < m && in_y < n && maze[in_x][in_y] == 0)
        {
            maze[in_x][in_y] = -1;
            DFS(in_x + H[i], in_y + V[i], m, n, out_x, out_y, maze);
            maze[in_x][in_y] = 0;
        }
    }      
}

int main()
{
    int m, n, i, j;
    int in_x, in_y, out_x, out_y;
    int maze[20][20];

    cin >> m >> n;
    cin >> in_x >> in_y >> out_x >> out_y;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cin >> maze[i][j];
    }

    DFS(in_x, in_y, m, n, out_x, out_y, maze);
    if(judge == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}