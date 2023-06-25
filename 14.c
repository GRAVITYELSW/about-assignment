//求广义表深度

//用了一些很下作的方法嘻嘻（能过就行）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[100];
    char s[100];
    fgets(s, 100, stdin);
    int i, j = 0;
    int len = strlen(s) - 1;
    for(i = 0; i < len; i++)
    {
        if(s[i] == '(')
        {
            nums[j] = 1;
            j++;
        }
        if(s[i] == ')')
        {
            nums[j] = 0;
            j++;
        }
    }
    int max = 1;
    int num = 1;
    for(i = 1; i < j - 1; i++)
    {
        if(nums[i] == 1)
        {
            num++;
            max = max > num ? max : num;
        }
        if(nums[i] == 0)
        {
            num = 1;
        }
    }
    printf("%d\n%d", max, max);
    return 0;
}
