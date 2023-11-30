//活动排名
#include <iostream>
#include <cmath>
using namespace std;

int n, result = 0, bt = 24, et, ba, na;
int b[1001], e[1001], used[1001];

/**
 * 首先找到开始时间最小且同样开始时间下结束时间最小的活动
 * 
 * 之后n次遍历所有活动，找出开始时间距离上次活动结束时间最近的且同样开始时间下结束时间最小的活动，结果+1
*/
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i] >> e[i];
        if(b[i] < bt)
            bt = b[i], ba = i, et = e[i];
        if(b[i] == bt && e[i] < et)
            bt = b[i], ba = i, et = e[i];
    }
    result++, used[ba] = 1;
    for(int i = 1; i <= n; i++)
    {
        na = 1001, bt = 24;
        for(int j = 1; j <= n; j++)
        {
            if(b[j] >= e[ba] && abs(b[j] - e[ba]) <= bt && used[j] == 0)
            {
                if(abs(b[j] - e[ba]) == bt)
                {
                    if(e[j] < e[na])
                        na = j, bt = abs(b[j] - e[ba]);
                }
                else
                    na = j, bt = abs(b[j] - e[ba]);
            }
        }
        if(na != 1001)
            used[na] = 1, result++, ba = na; 
    }
    cout << result << endl;
    
    return 0;
}