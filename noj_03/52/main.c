#include <stdio.h>
#include <string.h>

int main()
{
    char a[82], b[82], c[82];
    fgets(a, 82, stdin);
    fgets(b, 82, stdin);
    fgets(c, 82, stdin);
    int i, n, big = 0, small = 0, num = 0, tab = 0, other = 0;
    n = strlen(a);
    for(i = 0; i < n; i++)
    {
        if(a[i] >= 65 && a[i] <= 90)
            big++;
        else if(a[i] >= 97 && a[i] <= 122)
            small++;
        else if(a[i] >= 48 && a[i] <= 57)
            num++;
        else if(a[i] == 32)
            tab++;
        else
            other++;
    }
    n = strlen(b);
    for(i = 0; i < n; i++)
    {
        if(b[i] >= 65 && b[i] <= 90)
            big++;
        else if(b[i] >= 97 && b[i] <= 122)
            small++;
        else if(b[i] >= 48 && b[i] <= 57)
            num++;
        else if(b[i] == 32)
            tab++;
        else
            other++;
    }
    n = strlen(c);
    for(i = 0; i < n; i++)
    {
        if(c[i] >= 65 && c[i] <= 90)
            big++;
        else if(c[i] >= 97 && c[i] <= 122)
            small++;
        else if(c[i] >= 48 && c[i] <= 57)
            num++;
        else if(c[i] == 32)
            tab++;
        else
            other++;
    }
    printf("%d %d %d %d %d", big, small, num, tab, other);
    return 0;
}
