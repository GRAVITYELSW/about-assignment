//僵尸来了
//结构体才是最终归宿，不要挣扎了啊！！！
#include <iostream>
#include <queue>
using namespace std;

struct zombie
{
    int t;
    int step;
    int x, y;
    bool judge;
};

int m, n, t;    //m行n列地图，僵尸生命为t
char maze[200][200];
int used[200][200][10];    //注意used是三维，因为血量也是一维数据
int nextstep[4][2] = {0, -1,  -1, 0,  0, 1,  1, 0};
queue<zombie> q;
zombie begin_, end_;

zombie newplace(int i, zombie now)
{
    zombie next;
    next.x = now.x + nextstep[i][0];
    next.y = now.y + nextstep[i][1];
    if(next.x >= 0 && next.y >= 0 && next.x < m && next.y < n)
    {
        if(maze[next.x][next.y] == 'w')
            next.t = now.t - 1;
        else
            next.t = now.t;

        if(next.t <= 0 || used[next.x][next.y][next.t] == 1)
        {
            next.judge = false;
            return next;
        }
    }
    else
    {
        next.judge = false;
        return next;
    }
    used[next.x][next.y][next.t] = 1;
    next.step = now.step + 1;
    q.push(next);
    return next;
}

int bfs()
{
    while(!q.empty())
    {
        zombie now = q.front();
        q.pop();
        if(now.x == end_.x && now.y == end_.y)
        {
            return now.step;
        }
        for(int i = 0; i < 4; i++)
        {
            zombie next = newplace(i, now);
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n >> t;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '!')
                begin_.x = i, begin_.y = j;
            if(maze[i][j] == '+')
                end_.x = i, end_.y = j;
        }
    }

    begin_.t = t, begin_.step = 0;
    used[begin_.x][begin_.y][begin_.t] = 1;
    q.push(begin_);
    cout << bfs();

    return 0;
}