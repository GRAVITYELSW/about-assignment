#include <stdio.h>
#include <string.h>
void deletechar(char s[], char c)
{
    int n = strlen(s);
    int i, j;
    for(i = 0; i < n; i++)
    {
        if(s[i] == c)
        {
            for(j = i; j < n - 1; j++)
            {
                s[j] = s[j + 1];
            }
        }
    }
}
int main()
{
    char arr[100];
    fgets(arr, 100, stdin);
    char a;
    scanf("%c", &a);
    deletechar(arr, a);
    int i, n = strlen(arr);
    for(i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
        if(arr[i] == '\n')
            break;
    }
    return 0;
}
