#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int arr[10000];
    for(i = 0; n > 0; i++)
    {
        arr[i] = n % 2;
        n /= 2;
    }
    for(j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    return 0;
}
