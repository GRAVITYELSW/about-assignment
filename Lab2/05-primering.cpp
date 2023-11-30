#include <iostream>
using namespace std;

int a[25];  //辅助数组，用于判断当前的数是否用过
int out = 0;

/**
 * 判断素数函数
 * 
 * 如果可以除尽则不是素数，否则是素数
*/

bool isp(int m)
{
    for(int i = 2; i < m; i++)
    {
        if(m % i == 0)
            return false;
    }
    return true;
}

/**
 * 生成素数环函数
 * 
 * 素数环第一个数置1，从2开始判断
 * 如果a[i] == 0即这个数没有被用过，并且这个数和上个数互为素数，则放入环中，进入下一次循环，否则回退，再次赋为0
 * 当cur == n且首尾互为素数时，输出素数环
*/

void dfs(int cur, int n, int A[])
{
    if(out == 0)
    {
        if(cur == n && isp(A[0] + A[n - 1]) == true)
        {
            for(int i = 0; i < n; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
            out = 1;
        }
        else
        {
            for(int i = 2; i <= n; i++)
            {
                if(a[i] == 0 && isp(i + A[cur - 1]) == true)
                {
                    A[cur] = i;
                    a[i] = 1;
                    dfs(cur + 1, n, A);
                    a[i] = 0;
                }
            }
        }  
    }
    else
        return;

}

int main()
{
    int A[20];  //存放最终结果
    A[0] = 1;
    a[1] = 1;
    dfs(1, 20, A);

    return 0;
}