#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, X, a[20], i = 0, j = 0, k = 0, m = 0;
    int stu[51];
    scanf("%d %d", &N, &X);
    for(i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= N; i++)
    {
        stu[i] = i;
    }
    for(j = 0; j < 20; j++)
    {
        int count = 0;
        for(i = 1; i <= N; i++)
        {
            if(i % a[j] == 0)
            {
                count++;
                stu[i] = 0;
            }
            if(X == (N - count))
            {
                break;
            }
        }
        for(k = 1; k <= N; k++)
        {
            if(stu[k] == 0)
            {
                for(m = k; m < N; m++)
                {
                    stu[m] = stu[m + 1];
                }
            }
        }
        N -= count;
        if(N == X)
            break;
    }
    for(i = 1; i <= X; i++)
        printf("%d ", stu[i]);
    return 0;
}
