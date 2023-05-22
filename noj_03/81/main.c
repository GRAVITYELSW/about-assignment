#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i = 0, j = 0, count = 0;
    for(j = 1; j <= n; j++)
    {
        for(i = 1; i <= j; i++)
        {
            if((i * j + i + j) == n)
                count++;
        }
    }
    printf("%d", count);
    return 0;
}
