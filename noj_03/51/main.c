//#include <stdio.h>
//#include <string.h>
//void paixu1(char arr[], int i)
//{
//    int t = i / 2;
//    int a, b;
//    char tmp;
//    for(a = 1; a < t; a++)
//    {
//        for(b = 0; b < t - a; b++)
//        {
//            if(arr[b] < arr[b + 1])
//            {
//                tmp = arr[b];
//                arr[b] = arr[b + 1];
//                arr[b + 1] = tmp;
//            }
//        }
//        for(b = t; b < i - a; b++)
//        {
//            if(arr[b] > arr[b + 1])
//            {
//                tmp = arr[b];
//                arr[b] = arr[b + 1];
//                arr[b + 1] = tmp;
//            }
//        }
//    }
//    for(a = 0; a < t; a++)
//    {
//        tmp = arr[a];
//        arr[a] = arr[a + t];
//        arr[a + t] = tmp;
//    }
//    return;
//}
//void paixu2(char arr[], int i)
//{
//    int t = (i - 1)/ 2;
//    int a, b;
//    char tmp;
//    for(a = 1; a < t; a++)
//    {
//        for(b = 0; b < t - a; b++)
//        {
//            if(arr[b] < arr[b + 1])
//            {
//                tmp = arr[b];
//                arr[b] = arr[b + 1];
//                arr[b + 1] = tmp;
//            }
//        }
//        for(b = 1 + t; b < i - a; b++)
//        {
//            if(arr[b] > arr[b + 1])
//            {
//                tmp = arr[b];
//                arr[b] = arr[b + 1];
//                arr[b + 1] = tmp;
//            }
//        }
//    }
//    for(a = 0; a < t; a++)
//    {
//        tmp = arr[a];
//        arr[a] = arr[a + t + 1];
//        arr[a + t + 1] = tmp;
//    }
//    return;
//}
//int main()
//{
//    char arr[101];
//    int i, j;
//    fgets(arr, 101, stdin);
//    i = strlen(arr) - 1;
//    if(i % 2 == 0)
//    {
//        paixu1(arr, i);
//    }
//    else
//    {
//        paixu2(arr, i);
//    }
//    for(j = 0; j < i; j++)
//    {
//        printf("%c", arr[j]);
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>
void paixu(char s[], int n)
{
    int i,t,k;
    for(i=1;i<n;i++){
        t=s[i];k=i-1;
        while(t>s[k]){
            s[k+1]=s[k];k--;
            if(k==-1)break;
        }
        s[k+1]=t;
    }
}
void paixu2(char s[], int n)
{
    int i,t,k;
    for(i=n+1;i<2*n;i++){
        t=s[i];k=i-1;
        while(t<s[k]){
            s[k+1]=s[k];k--;
            if(k==n-1)break;
        }
        s[k+1]=t;
    }
}
int main()
{
    char s[101],a;
    int n,i,k;
    fgets(s, 101, stdin);
    n=strlen(s);
    if(n%2==0){
        n=n/2;
        paixu(s,n);
        paixu2(s,n);
    for(i=n;i<2*n;i++)
        printf("%c",s[i]);
    for(i=0;i<n;i++)
        printf("%c",s[i]);
    }
    else{
        k=(n-1)/2;
        a=s[k];
        for(i=k;i<n-1;i++)
            s[i]=s[i+1];
        n=k;
        paixu(s,n);
        paixu2(s,n);
    for(i=n;i<2*n;i++)
        printf("%c",s[i]);
        printf("%c",a);
    for(i=0;i<n;i++)
        printf("%c",s[i]);

    }
    return 0;
}
