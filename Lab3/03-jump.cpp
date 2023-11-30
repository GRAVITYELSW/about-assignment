#include <iostream>
#include <queue>
using namespace std;

int n;
int bx, by, ex, ey;
int step[200][200], used[200][200];
int nextplace[8][2] = {-1, -2,  -2, -1,  -2, 1,  -1, 2,  1, -2,  2, -1,  2, 1,  1, 2};
queue<int> q;

int newplace(int x, int y, int i)
{
    int x2 = x + nextplace[i][0];
    int y2 = y + nextplace[i][1];
    if(x2 >= 0 && x2 < 200 && y2 >= 0 && y2 < 200 && used[x2][y2] == 0)
    {
        used[x2][y2] = 1;
        step[x2][y2] = step[x][y] + 1;
        q.push(x2 * 200 + y2);
        return x2 * 200 + y2;
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
        int x1 = now / 200;
        int y1 = now % 200;
        for(int i = 0; i < 8; i++)
        {
            int next = newplace(x1, y1, i);
            if(next != -1)
            {
                int x2 = next / 200;
                int y2 = next % 200;
                if(x2 == (ex - 1) && y2 == (ey - 1))
                    return;
            }
        }
    }
}

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> bx >> by >> ex >> ey;
        q.push((bx - 1) * 200 + by - 1);
        used[bx - 1][by - 1] = 1;
        bfs();
        cout << step[ex - 1][ey - 1] << endl;
        for(int i = 0; i < 200; i++)
        {
            for(int j = 0; j < 200; j++)
            {
                used[i][j] = 0, step[i][j] = 0;
            }
        }
        while(!q.empty())
            q.pop();
    }
    return 0;
}