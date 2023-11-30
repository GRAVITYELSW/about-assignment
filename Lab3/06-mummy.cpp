//木乃伊迷宫
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int mx, my;
    int px, py;
    bool useful;
};
node start, exit_;
int n, x, y, l;
int maze[6][6][2];
int used[6][6][6][6];
int nextstep[4][2] = {0, -1, 1, 0, 0, 1, -1, 0}; //左下右上
queue<node> q;

/**
 * 判断是否是墙的函数
 * 
 * 如果是墙返回1，否则返回0
*/
bool iswall(int x, int y, int i)
{
    switch(i)
    {
		case 0:
			return maze[x][y - 1][1];
		case 1:
			return maze[x][y][0];
		case 2:
			return maze[x][y][1];
		case 3:
			return maze[x - 1][y][0];
        default:
            return false;
    }
}

/**
 * 判断下一个节点是否有效
 * 
 * 如果人走的下一个节点不满足条件，返回false
 * 两次循环僵尸，先同列再同行（注意next和now，注意m和n，注意x和y啊啊啊啊啊啊啊啊啊不然调好久不知道是哪里的问题）
 * 判断僵尸是否追上
 * 判断节点是否使用过
*/
node nextplace(node now, int i)
{
    node next;
    next.px = now.px + nextstep[i][0], next.py = now.py + nextstep[i][1];
    if(next.px < 0 || next.px > 5 || next.py < 0 || next.py > 5 || iswall(now.px, now.py, i))
    {
        next.useful = false;
        return next;
    }
    else
    {
        next.mx = now.mx, next.my = now.my;
        for(int m = 0; m < 2; m++)
        {
            if((next.my < next.py) && !iswall(next.mx, next.my, 2))
                next.my++;
            else if((next.my > next.py) && !iswall(next.mx, next.my, 0))
                next.my--;
            else if(next.my == next.py)
            {
                if((next.mx < next.px) && !iswall(next.mx, next.my, 1))
                    next.mx++;
                else if((next.mx > next.px) && !iswall(next.mx, next.my, 3))
                    next.mx--;
                else if(next.mx == next.px)
                {
                    next.useful = false;
                    return next;
                }
            }
        }
    }
    if(next.mx == next.py && next.my == next.py)
    {
        next.useful = false;
        return next;
    }

    if(used[next.mx][next.my][next.px][next.py])
        next.useful = false;
    else
    {
        used[next.mx][next.my][next.px][next.py] = 1;
        next.useful = true;
    }
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
            node next = nextplace(now, i);
            if(next.useful)
            {
                if(next.px == exit_.px && next.py == exit_.py)
                    return 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> l;
        maze[x][y][l] = 1;
    }
    cin >> start.mx >> start.my >> start.px >> start.py >> exit_.px >> exit_.py;
    used[start.mx][start.my][start.px][start.py] = 1;
    q.push(start);
    if(bfs())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}