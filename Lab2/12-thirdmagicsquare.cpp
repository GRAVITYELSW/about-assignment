//三阶幻方
#include <iostream>
using namespace std;

int square[3][3], num[10];

bool judge(int x, int y, int i)
{
    if(num[i] == 1)
        return false;
    if(x == 2 || y == 2)
    {
        if(x == 2)
        {        
            if(square[0][y] + square[1][y] + square[2][y] != 15)
                return false;
            if(y == 0)
            {
                if(square[0][2] + square[1][1] + square[2][0] != 15)
                    return false;
            }
            if(y == 2)
            {
                if(square[0][0] + square[1][1] + square[2][2] != 15)
                    return false;
            }
        }
        if(y == 2)
        {
            if(square[x][0] + square[x][1] + square[x][2] != 15)
                return false;
        }
    }
    return true;
}

void dfs(int m)
{
    if(m >= 3 * 3)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(j < 2)
                    cout << square[i][j] << " ";  
                else
                    cout << square[i][j];      
            }

            cout << endl;
        }
        cout << endl;
    }
    int nx = m / 3, ny = m % 3;
    for(int i = 1; i <= 9; i++)
    {
        square[nx][ny] = i;
        if(judge(nx, ny, i))
        {
            num[i] = 1;
            dfs(m + 1);
            num[i] = 0;
        }
        square[nx][ny] = 0;
    }
}

int main()
{
    dfs(0);
    return 0;
}