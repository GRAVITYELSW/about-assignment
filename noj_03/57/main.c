#include <stdio.h>
#include <string.h>

int main()
{
    char arr[10];
    fgets(arr, 10, stdin);
    int i;
    int len = strlen(arr) - 1;

    if(arr[0] == 'A' && arr[1] == '#')
    {
        printf("Bb ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'B' && arr[1] == 'b')
    {
        printf("A# ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'C' && arr[1] == '#')
    {
        printf("Db ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'D' && arr[1] == 'b')
    {
        printf("C# ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'D' && arr[1] == '#')
    {
        printf("Eb ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'E' && arr[1] == 'b')
    {
        printf("D# ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'F' && arr[1] == '#')
    {
        printf("Gb ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'G' && arr[1] == 'b')
    {
        printf("F# ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }

    else if(arr[0] == 'G' && arr[1] == '#')
    {
        printf("Ab ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }
    else if(arr[0] == 'A' && arr[1] == 'b')
    {
        printf("G# ");
        for(i = 3; i < len; i++)
            printf("%c", arr[i]);
    }
    else
        printf("unique");
    return 0;
}
