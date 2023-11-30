//旅游预算
#include <iostream>
#include <iomanip>
using namespace std;

double dis, box, mile, cost;
int stanum;
double station[50][2], dp[50];  //dp表示到达第i个加油站的最小耗费
int pre[50], t[50];

/**
 * 动态规划
 * 
 * road为油箱加满时能跑的最远距离，m为两个加油站之间需要的汽油升数
 * 
 * 首先初始化dp数组，即每个加油站的最小花费
 * 当两个加油站之间的距离大于road或小于road/2(即油箱油量过半)时，不考虑加油
 * 否则在加油和不加油之间选择花费小的一个
 * 
 * 之后选择能到达终点且代价最小的加油站，其dp即为最终花费
*/
int main()
{
    cin >> dis >> box >> mile >> dp[0] >> stanum;
    for(int i = 1; i <= stanum; i++)
    {
        cin >> station[i][0] >> station[i][1];
        dp[i] = 1 << 30;
    }
    double road = box * mile;
    for(int i = 1; i <= stanum; i++)
    {
        for(int j = 0; j <= i - 1; j++)
        {
            if((station[i][0] - station[j][0]) > road || (station[i][0] - station[j][0]) * 2 < road)
                continue;
            double m = (station[i][0] - station[j][0]) / mile;
            if(dp[i] > dp[j] + m * station[i][1] + 2)
            {
                dp[i] = dp[j] + m * station[i][1] + 2;
                pre[i] = j;
            }
        }
    }

    double result = 1 << 30;
    int last = 0, count = 0;
    for(int i = 0; i <= stanum; i++)
    {
        if(road < dis - station[i][0])
            continue;
        if(result > dp[i])
        {
            result = dp[i];
            last = i;
        }
    }
    while(last)
    {
        t[++count] = last;
        last = pre[last];
    }
    cout.setf(ios::fixed);
    cout << setprecision(2) << result << " " << count << endl;
    for(int i = count; i >= 1; i--)
        cout << t[i] << " ";
    
    return 0;
}