#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[1001];
    fgets(arr, 1001, stdin);
    int i, j;
    for(i = 0; i <1001; i++)
    {
        if(arr[i] == 'y' && arr[i + 1] == 'o' && arr[i + 2] == 'u')
        {
            arr[i] = 'w';
            arr[i + 1] = 'e';
            for(j = i + 2; j < 1001; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    i = 0;
    while(arr[i] != '\0')
    {
        printf("%c", arr[i]);
        i++;
    }
    return 0;
}
