#include <iostream>
using namespace std;

//依次试探每一格的左下右上是否可以走
int H[4] = {0, 1, 0, -1};
int V[4] = {-1, 0, 1, 0};

/**
 * 判断迷宫路径函数
 * 
 * 利用for循环，判断每一格的左下右上是否可以行走，如果可以，maze置为:，进入下一个循环
 * 当走到迷宫出口时，return 1
 * 
 * 如果迷宫没有出路，return 0
*/
int DFS(int in_x, int in_y, int out_x, int out_y, char maze[20][20])
{
    if(in_x == out_x && in_y == out_y)
    {
        maze[in_x][in_y] = ':';
        return 1;
    }                                                                                                                     
    for(int i = 0; i < 4; i++)
    {
        if(in_x + H[i] >= 0 && in_y + V[i] >= 0 && in_x + H[i] < 20 && in_y + V[i] < 20 && maze[in_x + H[i]][in_y + V[i]] == '.')
        {
            maze[in_x + H[i]][in_y + V[i]] = ':';
            if(DFS(in_x + H[i], in_y + V[i], out_x, out_y, maze))
                return 1;
        }
    }  
    return 0;    
}

int main()
{
    int n;
    int in_x[10], in_y[10], out_x[10], out_y[10];
    char maze[10][20][20];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> in_x[i] >> in_y[i] >> out_x[i] >> out_y[i];
        for(int j = 0; j < 20; j++)
        {
            cin >> maze[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        int judge = DFS(in_x[i], in_y[i], out_x[i], out_y[i], maze[i]);
        if(judge == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}