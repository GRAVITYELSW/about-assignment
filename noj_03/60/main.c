#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char arr[1001];
    fgets(arr, 1001, stdin);
    int len = strlen(arr) - 1;
    int i, u = 0, d = 0, j = 1;
    for(i = 0; i < len; i++)
    {
        if(arr[i] == 'U')
            u++;
        else if(arr[i] == 'D')
            d++;
        else
        {
            j = 0;
            printf("WA");
            break;
        }
    }
    if(j)
    {
        double result = u * 1.0 / ((u + d) * 1.0);
        double cha = fabs(result - 0.5);
        if(cha == 0)
            printf("1/2");
        else if(cha != 0 && cha <= 0.003)
        {
            printf("%d/%d", u, u + d);
        }
        else
            printf("Fail");
    }
    return 0;
}
