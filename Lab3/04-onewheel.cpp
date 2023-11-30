#include <iostream>
#include <queue>
using namespace std;

int n;
int bx, by, ex, ey, b_c, b_l, e_c;
char bc, bl, ec;
char maze[21][21];
int step[21][21][5][4], used[21][21][5][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef struct node
{
    int color;
    int location;
    int x, y;
} node;

queue<node> q;

node newplace(node n, int i)
{
    if(i == 0)
    {
        n.color = (n.color + 1) % 5;
        n.x = n.x + dx[n.location];
        n.y = n.y + dy[n.location];
    }
    else if(i == 1)
    {
        n.location = (n.location + 1) % 4;
    }
    else
    {
        n.location=(n.location + 3) % 4;
    }
    return n;
}

int bfs()
{
    node n1, n2;
    n1.x = bx;
    n1.y = by;
    n1.color = b_c;
    n1.location = b_l;
    q.push(n1);
    while(!q.empty())
    {
        n1 = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            n2 = newplace(n1, i);
            if(n2.x == ex && n2.y == ey && n2.color == e_c)
                return step[n1.x][n1.y][n1.color][n1.location] + 1;
            if(n2.x > 0 && n2.y < 21 && n2.y > 0 && n2.y < 21 && used[n2.x][n2.y][n2.color][n2.location] == 0 && maze[n2.x][n2.y] == '.')
            {
                q.push(n2);
                used[n2.x][n2.y][n2.color][n2.location] = 1;
                step[n2.x][n2.y][n2.color][n2.location] = step[n1.x][n1.y][n1.color][n1.location] + 1;
            }
        }
    }
    return -1;
}

int changecolor(char c)
{
    if(c == 'R')
        return 0;
    else if(c == 'Y')
        return 1;
    else if(c == 'B')
        return 2;
    else if(c == 'W')
        return 3;
    else 
        return 4;
}

int changedir(char d)
{
    if(d == 'E')
        return 0;
    else if(d == 'S')
        return 1;
    else if(d == 'W')
        return 2;
    else
        return 3;
}

int main()
{
    cin >> bx >> by >> bc >> bl;
    cin >> ex >> ey >> ec;

    b_c = changecolor(bc);
    b_l = changedir(bl);
    e_c = changecolor(ec);

    for(int i = 1; i < 21; i++)
    {
        for(int j = 1; j < 21; j++)
            cin >> maze[i][j];
    }

    used[bx][by][b_c][b_l] = 1;
    int result = bfs();
    cout << result << endl;

    return 0;
}