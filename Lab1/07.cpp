//用分治算法生成循环赛日程表（1-2的n次方个人）

#include <iostream>
#include <math.h>
using namespace std;

void table(int n, int result[][129])
{
    int i, j, m, t, temp;
    m = 2;
    result[1][1] = 1, result[1][2] = 2;
    result[2][1] = 2, result[2][2] = 1;
    for(t = 1; t < n; t++)
    {
        temp = m;
        m *= 2;
        for(i = temp + 1; i <= m; i++)
        {
            for(j = 1; j <= temp; j++)
            {
                result[i][j] = result[i - temp][j] + temp;
            }
        }
        for(i = 1; i <= temp; i++)
        {
            for(j = temp + 1; j <= m; j++)
            {
                result[i][j] = result[i + temp][j - temp];
            }
        }
        for(i = temp + 1; i <= m; i++)
        {
            for(j = temp + 1; j <= m; j++)
            {
                result[i][j] = result[i - temp][j - temp];
            }
        }
    }
}

int main()
{
    int n, people;
    int result[129][129];
    cin >> n;
    people = pow(2, n);
    table(n, result);
    for(int i = 1; i <= people; i++)
    {
        for(int j = 1; j < people; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << result[i][people] << endl;
    }
    return 0;
}