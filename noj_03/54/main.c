#include <stdio.h>
#include <string.h>
void Left(char src[], int n, char dest[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}
void Right(char src[], int n, char dest[])
{
    int len = strlen(src) - 1;
    int i, j = 0;
    for (i = len - n; i < len; i++, j++)
    {
        dest[j] = src[i];
    }
}
void Mid(char src[], int loc, int n, char dest[])
{
    int i, j = 0;
    for (i = loc; i < loc + n; i++, j++)
    {
        dest[j] = src[i];
    }
}
int main()
{
    char arr[100];
    char l[100], r[100], m[100];
    fgets(arr, 100, stdin);
    int n, loc, i;
    scanf("%d %d", &n, &loc);
    Left(arr, n, l);
    for (i = 0; i < n; i++)
    {
        printf("%c", l[i]);
    }
    printf("\n");
    Right(arr, n, r);
    for (i = 0; i < n; i++)
    {
        printf("%c", r[i]);
    }
    printf("\n");
    Mid(arr, loc, n, m);
    for (i = 0; i < n; i++)
    {
        printf("%c", m[i]);
    }
    return 0;
}
