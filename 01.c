#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, a[40], b[20], i = 0, j = 0, k = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < m; i++)
    {
        if(b[i] > a[n - 1])
        {
            a[n] = b[i];
            n++;
        }
        else
        {
            for(j = 0; j < n; j++)
            {
                if(b[i] <= a[j])
                {
                    for(k = n; k > j; k--)
                    {
                        a[k] = a[k - 1];
                    }
                    a[j] = b[i];
                    n++;
                    break;
                }
            }
        }

    }
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
