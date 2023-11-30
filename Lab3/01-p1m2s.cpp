#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int m, n;
int step[10000], used[10000];

/**
 * 判断是否到达结果的函数
 * 如果没有被用过，used赋1，步数加一
 * 如果next == n，返回true，否则入队
*/
bool judge(int now, int next)
{
    if(next <= n && !used[next])
    {
        used[next] = 1;
        step[next] = step[now] + 1;
        if(next == n)
            return true;
        else
            q.push(next);
    }
    return false;
}

/**
 * 进行加一乘二平方三项操作的函数
*/
int change(int now, int i)
{
    if(i == 0)
        return now + 1;
    else if(i == 1)
        return now * 2;
    else
        return now * now;
}

/**
 * 分支限界法-广搜
 * 
 * 判断队列是否为空
 * 如果不为空，当前数字为队头元素，进行广搜
*/
int bfs()
{
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        used[now] = 1;
        for(int i = 0; i < 3; i++)
        {
            int next = change(now, i);
            if(judge(now, next))
                return step[next];
        }
    }
    return 0;
}

int main()
{
    cin >> m >> n;
    q.push(m);
    cout << bfs() << endl;
    return 0;
}