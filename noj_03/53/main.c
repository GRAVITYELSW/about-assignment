#include <stdio.h>
#include <string.h>
void Copy(char a[], char b[], int len, int n)
{
    int i;
    for(i = 0; n < len; i++, n++)
    {
        b[i] = a[n];
    }
}
int main()
{
    char a[101];
    char b[101] = { 0 };
    fgets(a, 101, stdin);
    int n, i;
    int len = strlen(a) - 1;
    scanf("%d", &n);
    Copy(a, b, len, n);
    for(i = 0; i < len - n; i++)
    {
        printf("%c", b[i]);
    }
    return 0;
}
