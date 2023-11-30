//僵尸又来了
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int x, y;
    int alltime, ftime;
    bool useful;
};

int m, n, t, p;
char maze[100][100];
int used[100][100][20];
int nextstep[4][2] = {-1, 0,  0, 1,  1, 0,  0, -1};
node start, end_;
queue<node> q;

/**
 * 更新食人花的时间
 * 
 * 如果时间>0，减一，否则不变
*/
int updateftime(int ft)
{
    if(ft > 0)
        ft -= 1;
    return ft;
}

/**
 * 新节点判定函数
 * 
 * 如果x、y或遇到墙或时间超了，返回false
 * 更新食人花时间
 * 如果遇到食人花：1.此时食人花时间>0，吃掉食人花，时间置-1
 *               2.此时食人花时间=0，被食人花吃掉，时间置t
 *               3.此时食人花时间=-1，已经没有食人花，时间置-1
 * 
 * 判断节点是否用过
 * 如果没走过，used置1，alltime+1返回
*/
node newplace(node now, int i)
{
    node next;
    next.x = now.x + nextstep[i][0], next.y = now.y + nextstep[i][1], next.ftime = now.ftime;
    if(next.x < 1 || next.x > m || next.y < 1 || next.y > n || maze[next.x][next.y] == '#' || now.alltime >= p)
    {
        next.useful = false;
        return next;
    }
    next.ftime = updateftime(now.ftime);
    if(maze[next.x][next.y] == '@')
    {
        if(next.ftime > 0)
            next.ftime = -1;
        else if(next.ftime == 0)
            next.ftime = t, next.x = start.x, next.y = start.y;
        else
            next.ftime = -1;
    }
    if(used[next.x][next.y][next.ftime] == 1)
    {
        next.useful = false;
        return next;
    }
    used[next.x][next.y][next.ftime] = 1;
    next.useful = true, next.alltime = now.alltime + 1;
    return next;
}

int bfs()
{
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            node next = newplace(now, i);
            if(next.useful)
            {
                if(next.x == end_.x && next.y == end_.y)
                    return next.alltime;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n >> t >> p;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '!')
                start.x = i, start.y = j, start.alltime = start.ftime = 0;
            if(maze[i][j] == '+')
                end_.x = i, end_.y = j, end_.alltime = end_.ftime = 0;
        }
    }
    q.push(start);
    used[start.x][start.y][start.ftime] = 1;
    cout << bfs();
    return 0;
}