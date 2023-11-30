#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m, j, real = 0;
    int binary[5] = {};
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        real += pow(2, i);
    }

    for(int i = 0; i <= real; i++)
    {
        m = i;
        for(j = 0; m > 0; j++)
        {
            binary[j] = m % 2;
            m /= 2;
        }
        for(int k = n - 1; k >= 0; k--)
        {
            cout << binary[k];
        }
        cout << endl;
    }
    return 0;
}