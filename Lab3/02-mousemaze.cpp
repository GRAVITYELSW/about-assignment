#include <iostream>
#include <queue>
using namespace std;

int bx, by, ex, ey;
char maze[12][12];
int step[12][12], used[12][12];
int nextstep[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};    //上左右下
queue<int> q;

int newplace(int x, int y, int i)
{
    int x2 = x + nextstep[i][0];
    int y2 = y + nextstep[i][1];
    if(x2 >= 0 && x2 < 12 && y2 >= 0 && y2 < 12 && used[x2][y2] == 0 && maze[x2][y2] == '.')
    {
        used[x2][y2] = 1;
        step[x2][y2] = step[x][y] + 1;
        q.push(x2 * 12 + y2);
        return x2 * 12 + y2;
    }
    else
        return -1;
}

void bfs()
{
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        int x1 = now / 12;
        int y1 = now % 12;
        for(int i = 0; i < 4; i++)
        {
            int next = newplace(x1, y1, i);
            if(next != -1)
            {
                int x2 = next / 12;
                int y2 = next % 12;
                if(x2 == ex && y2 == ey)
                    return;
            }
        }
    }
}

int main()
{
    cin >> bx >> by >> ex>> ey;
    for(int i = 0; i < 12; i++)
    {
        cin >> maze[i];
    }
    q.push((bx - 1) * 12 + (by - 1));
    bfs();
    cout << step[ex - 1][ey - 1] << endl;
    return 0;
}