#include <iostream>
#include <math.h>
using namespace std;

int q[9];
char result[9][9];
int count = 0;

void display(int n) //输出一个解
{
    cout << "No " << ++ count << ":" << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == q[i])
                cout << "A";
            else
                cout << result[i][j];
        }
        cout << endl;
    }
}

/**
 * 放置皇后函数
 * 
 * 如果i == 1，即第一个皇后，直接放置，返回true
 * 如果j < i，即不是第一个，则从1~i - 1开始循环，如果有一个满足同行同列同对角线，返回false
*/

bool place(int i)
{
    int j = 1;
    if(i == 1)  
        return true;
    while(j < i)   
    {
        if((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i))) 
            return false;
        j++;
    }
    return true;
}

/**
 * 求解n皇后问题：同行、同列、同对角线不能出现两个皇后
 * 
 * i表示当前行，也表示放置第i个皇后（即每一行有一个皇后）
 * q[i]表示当前列，每个皇后的初始位置为0
 * 
 * 首先判断 如果q[i] <= n且!place()==true，即放置不成功，则列数q[i]++
 * 如果放置成功，进入if语句：如果i == n，表示所有皇后已经放置完毕，则输出一个解
 *                         否则放置未完毕，i++且q[i] = 0，继续放置下一个皇后
 * 如果未放置成功，即此皇后的q[i] > n，没有可以放置的列，则回溯到上一个皇后重新放置
*/

void queen(int n)   
{
    int i = 1; 
    q[i] = 0;   
    while(i >= 1)
    {
        q[i]++;
        while(q[i] <= n && !place(i))
            q[i]++;
        if(q[i] <= n)
        {
            if(i == n)
                display(n);
            else
            {
                i++;
                q[i] = 0;
            }
        }
        else
            i--;
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            result[i][j] = '.';
    }
    queen(8);
    return 0;
}