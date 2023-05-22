#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char arr[100];
    for(i = 0; i < 100; i++)
    {
        scanf("%c", &arr[i]);
        if(arr[i] == '=')
            break;
    }
    int left = 0;
    int right = i - 1;
    while(left < right)
    {
        char tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
    int j;
    for(j = 0; j < i; j++)
    {
        printf("%c", arr[j]);
    }
    return 0;
}
