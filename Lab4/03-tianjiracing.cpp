//田忌赛马
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int speed1[101], speed2[101];

/**
 * 贪心算法
 * 
 *用最好的相比，如果可以则+1
 *用最差的相比，如果可以则+1
 *如果都不行，用最差的抵消最好的
*/
int main()
{
    int n;
    int speed1[101], speed2[101];
    while(cin >> n, n)
    {
        int f1, f2, s1, s2, count = 0;
        for(int i = 0; i < n; i++)
            cin >> speed1[i];
        for(int i = 0; i < n; i++)
            cin >> speed2[i];
        sort(speed1, speed1 + n, greater<int>());
        sort(speed2, speed2 + n, greater<int>());
        f1 = f2 = 0, s1 = s2 = n - 1;

        for(int i = 0; i < n; i++)
        {
            if(speed1[f1] > speed2[f2])
                count++, f1++, f2++;
            else if(speed1[s1] > speed2[s2])
                s1--, s2--, count++;
            else
            {
                if(speed1[s1] < speed2[f2])
                    s1--, f2++, count--;
            }
        }
        cout << count << endl;
    }
    return 0;
}