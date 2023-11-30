#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * 假设总距离为n + m，每个点的位置为1,2,3……（整数）
 * 
 * n的距离是固定的，即平分放置
 * 而要使移动距离最小，则假设m个点直接放置在不需要移动的位置
 * 
 * 首先计算出每个n的初始位置，然后初始位置+0.5计算出每个n距离最近的整数，相减并累加起来就是需要移动的距离
 * 最后将距离根据弧长换算成真正的距离
*/
int main()
{
	int n, m;
	double pos, dis;   
 
	while(cin >> n >> m)
	{
		dis = 0;	
		for(int i = 0; i < n; i++)	
		{
			pos = (double)i / n * (n+m);	    
			dis += fabs((int)(pos + 0.5) - pos);	
		}
		dis = (double)dis / (m+n) * 10000;	
        cout.setf(ios::fixed);
        cout << setprecision(4) << dis << endl;
	}
	return 0;
}