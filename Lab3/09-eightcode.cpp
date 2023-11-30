//八数码问题
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int code[3][3];
int nextcode[4][2] = {0, -1,  -1, 0,  0, 1,  1, 0};
queue<int> q;
map<int, int> used, step;

int trans(int code[3][3])
{
    int num = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            num = (num * 10) + code[i][j];
    }
    return num;
}

int newnum(int temp[3][3], int m, int n, int num, int i)
{
    int x = m + nextcode[i][0], y = n + nextcode[i][1];
    if(x >= 0 && x <= 2 && y >= 0 && y <= 2)
    {
        int swap = temp[x][y];
        temp[x][y] = temp[m][n];
        temp[m][n] = swap;
        int num2 = trans(temp);
        if(used.count(num2) == 0)
        {
            q.push(num2);
            used[num2] = 1;
            step[num2] = step[num] + 1;
            temp[m][n] = temp[x][y];
            temp[x][y] = swap;
            return num2;
        }
        else
        {
            temp[m][n] = temp[x][y];
            temp[x][y] = swap;
            return -1;
        }
    }
    else 
        return -1;
}

int bfs()
{
    while(!q.empty())
    {
        int num = q.front();
        int use = num;
        q.pop();
        int temp[3][3];
        int m, n;
        for(int i = 2; i >= 0; i--)
        {
            for(int j = 2; j >= 0; j--)
            {
                temp[i][j] = use % 10, use /= 10;
                if(temp[i][j] == 0)
                {
                    m = i, n = j;
                }
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int re = newnum(temp, m, n, num, i);
            if(re != -1)
            {
                if(re == 123456780)
                    return step[re];
            }
        }
    }
    return -1;
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> code[i][j];
    }
    int num = trans(code);
    q.push(num);
    used[num] = 1, step[num] = 0;
    int result = bfs();
    cout << result << endl;
    return 0;
}