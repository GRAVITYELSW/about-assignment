//计算矩阵连乘积
#include <iostream>
using namespace std;

int n;
int m[11][11], s[10][10], p[11];

void matrixchain()
{
    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for(int r = 2; r <= n; r++)
    {
        for(int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for(int k = i + 1; k < j; k ++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n] << endl;
}

int main()
{
    cin >> n;
    int temp;
    cin >> p[0] >> p[1];
    for(int i = 2; i <= n; i++)
    {
        cin >> temp >> p[i];
    }
    matrixchain();
    return 0;
}