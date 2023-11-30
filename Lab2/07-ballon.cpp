#include <iostream>
#include <algorithm>
using namespace std;

int small, big;
int mul1, mul2;//已经当前已经踩过的气球的乘积
bool judge1, judge2;

/**
 * 判断真假话函数
 * 
 * 从100开始向前判断
 * 判断小数和大数是否能够除尽k，如果可以，mul×k，进入dfs递归，后还原（如果不还原，会导致后面j1j2再次赋予错误值）
 * 
 * 判断small和big是否有可能为真话，进行judge赋值
*/
void dfs(int k)
{
    if(k <= 1)
    {
        if(mul1 == small && mul2 == big) 
            judge1 = 1, judge2 = 1;
        else if((!judge1 || !judge2) && mul1 == small)
            judge1 = 1, judge2 = 0;
        else if(!judge1 && !judge2 && mul2 == big)
            judge1 = 0, judge2 = 1;
        return;
    }

    if(mul1 * k <= small && small % k == 0)
    {
        mul1 *= k;
        dfs(k-1);
        mul1 /= k;
    }
    if(mul2 * k <= big && big % k == 0)
    {
        mul2 *= k;
        dfs(k-1);
        mul2 /= k;
    }
    dfs(k-1);
}

int main()
{
    while(cin >> big >> small, big || small)
    {
        if(small > big) 
            swap(small, big);

        mul1 = 1, mul2 = 1;
        judge1 = 0, judge2 = 0;

        dfs(100);

        if((judge1 && judge2) || (!judge1 && !judge2))
            cout << big << endl;
        else
        {
            if(judge1)
                cout << small << endl;
            else
                cout << big << endl;
        }
    }
    return 0;   
}
