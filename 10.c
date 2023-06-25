//K阶斐波那切数列

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>

using namespace std;
const int maxn = 200010;

int f[maxn];
int maxnum,k;

int main()
{
   // freopen("test2.txt","r",stdin);
    cin >> maxnum >> k;
    for (int i=0;i<k-1;i++)
      f[i]=0;
    f[k-2]=1;
    f[k-1]=1;
    int sum=2;
    int i=k;
    int rec;
    while(1)
    {
    	int save = f[i%k];
        if (sum <= maxnum)
            f[i%k] = sum;
        else
          {
              rec=i%k;
              break;
          }
        sum = sum + f[i%k] - save;
        i++;
    }
    for (int i=rec;i<rec+k;i++)
       cout << f[i%k] << " ";
    return 0;
}
