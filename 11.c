//循环右移

#include <stdio.h>

int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    int a[n + 1];
    a[0] = k;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    i = (n + 1) - k % n;
    int count;
    for( count = 0;count < n; i++, count++ )
    {
        printf("%d ", a[i]);
        if(i == n)
            i = 0;
    }
    return 0;
}