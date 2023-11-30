//推箱子
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int bx, by;
    int px, py;
    bool useful;
};
node start, end_;
queue<node> q;
char maze[10][10];
int used[10][10][10][10], step[10][10][10][10];
int nextstep[4][2] = {0, -1,  1, 0,  0, 1,  -1, 0}; //左下右上

/**
 * 判断下个节点的函数
 * 
 * 如果不符合条件（如x、y不在范围内，下个节点是墙），直接false并返回
 * 如果符合条件，判断人与箱子的位置是否重叠，如果重叠判断箱子是否可以向前推（注意同样判断xy范围和墙），不能推false并返回
 * 满足条件且没有使用过的节点，used置1，step+1，置true并返回
*/
node newplace(int i, node now)
{
    node next;
    next.px = now.px + nextstep[i][0], next.py = now.py + nextstep[i][1];
    next.bx = now.bx, next.by = now.by;
    if(next.px < 0 || next.px >= 10 || next.py < 0 || next.py >= 10 || maze[next.px][next.py] == '1')
    {
        next.useful = false;
        return next;
    }
    if(next.px == next.bx && next.py == next.by)
    {
        next.bx = next.bx + nextstep[i][0], next.by = next.by + nextstep[i][1];
        if(next.bx < 0 || next.bx >= 10 || next.by < 0 || next.by >= 10 || maze[next.bx][next.by] == '1')
        {
            next.useful = false;
            return next;
        }
    }
    if(used[next.bx][next.by][next.px][next.py] == 1)
    {
        next.useful = false;
        return next;
    }
    used[next.bx][next.by][next.px][next.py] = 1;
    step[next.bx][next.by][next.px][next.py] = step[now.bx][now.by][now.px][now.py] + 1;
    next.useful = true;
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
            node next = newplace(i, now);
            if(next.useful)
            {
                if(next.bx == end_.bx && next.by == end_.by)
                    return step[next.bx][next.by][next.px][next.py];
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '2')
                start.bx = i, start.by = j;
            if(maze[i][j] == '4')
                start.px = i, start.py = j;
            if(maze[i][j] == '3')
                end_.bx = i, end_.by = j;
        }
    }
    maze[start.bx][start.by] = maze[start.px][start.py] = maze[end_.bx][end_.by] = '0';
    q.push(start);
    used[start.bx][start.by][start.px][start.py] = 1;
    cout << bfs() << endl;
    return 0;
}