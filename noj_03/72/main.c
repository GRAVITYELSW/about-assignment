//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char a[102], b[102];
//    int c[102];
//    fgets(a, 102, stdin);
//    fgets(b, 102, stdin);
//    int lena = strlen(a) - 1;
//    int lenb = strlen(b) - 1;
//    int aa = lena - 1, bb = lenb - 1;
//    int i = 0, j = 0, k = 0, judge = 0;
//    if(a[0] == '-')
//    {
//        if((lena - 1) > lenb)
//        {
//            for(i = (lena - 1), j = 0; i > 0; i--, aa--, bb--, j++)
//            {
//                if(bb >= 0)
//                {
//                    if(a[aa] > b[bb])
//                        c[j] = a[aa] - b[bb] - 2 * '0';
//                    else if(a[aa] == b[bb])
//                        c[j] = 0;
//                    else
//                    {
//                        c[j] = 10 - (b[bb] - '0') + a[aa] - '0';
//                        a[aa - 1] -= 1;
//                    }
//                }
//                else
//                {
//                    c[j] = a[aa];
//                }
//            }
//            printf("-");
//            for(k = j - 1; k >= 0; k--)
//                printf("%d", c[k]);
//        }
//        else if((lena - 1) == lenb)
//        {
//
//        }
//        else
//        {
//
//        }
//    }
//    else if(b[0] == '-')
//    {
//
//    }
//    else
//    {
//        for(i = ((lena > lenb)? lena : lenb) - 1, j = 0; i>= 0; i--, j++, aa--, bb--)
//        {
//            if(i == (((lena > lenb)? lena : lenb) - 1))
//            {
//                judge = a[aa] + b[bb] - 2 * '0';
//                c[j] = judge % 10;
//            }
//            else
//            {
//                if(aa >= 0 && bb >= 0)
//                {
//                    judge = a[aa] + b[bb] - 2 * '0' + ((a[aa + 1] + b[bb + 1] - 2 * '0') / 10);
//                    c[j] = judge % 10;
//                }
//                else if(aa >=0 && bb < 0)
//                {
//                    if(bb == -1)
//                    {
//                        judge = a[aa] - '0' + ((a[aa + 1] + b[bb + 1] - 2 * '0') / 10);
//                        c[j] = judge % 10;
//                    }
//                    else
//                    {
//                        judge = a[aa] - '0' + ((a[aa + 1] - '0' + judge) / 10);
//                        c[j] = judge % 10;
//                    }
//                }
//                else
//                {
//                    if(aa == -1)
//                    {
//                        judge = b[bb] - '0' + ((a[aa + 1] + b[bb + 1] - 2 * '0') / 10);
//                        c[j] = judge % 10;
//                    }
//                    else
//                    {
//                        judge = b[bb] - '0' + (b[bb + 1] - '0' + judge) / 10;
//                        c[j] = judge % 10;
//                    }
//                }
//            }
//        }
//        if(judge >= 10 && judge <20)
//        {
//            c[j] = 1;
//        }
//        else if(judge >= 20)
//        {
//            c[j] = 2;
//        }
//        else
//            j -= 1;
//        for(k = j; k >= 0; k--)
//            printf("%d", c[k]);
//    }
//    return 0;
//}

#include<stdio.h>
#include<string.h>
int Maxlen ;
char a[110] , b[110] ;
int an1[110] , an2[110] ;
int Addition(int maxlen , int an1[] , int an2[] );
int main()
{
 int i , j  ;
 scanf("%s" , a) ;
 scanf("%s" , b) ;
 memset( an1 , 0 , sizeof(an1) ) ;
    memset( an2 , 0 , sizeof(an2) ) ;
 int len1 = strlen(a) ;
 int len2 = strlen(b) ;
 if(len1 > len2 )
  Maxlen = len1 ;
 Maxlen = len2 ;
 for(j = 0, i = strlen(a)- 1 ; i >= 0 ; i --)
  an1[j++] = a[i] - '0';
 for(j = 0 , i = len2 - 1 ; i >= 0 ; i --)
   an2[j++] = b[i] - '0';
 Addition ( Maxlen , an1 , an2 ) ;
 for( i = 100 ; i >= 0; i -- )
 {
  if( an1[i] != 0 )break;
 }
 for(;i>=0;i--)
  printf("%d" ,an1[i]) ;
 printf("\n") ;
}
int Addition( int maxlen , int  an1[] , int  an2[] )//大数相加函数
{
 for( int i = 0 ; i < maxlen ; i++ )
 {
  an1[i] += an2[i] ;
  if( an1[i] >= 10 )
  {
   an1[i] -= 10 ;
   an1[i + 1] ++ ;
  }
 }
 return 0;
}
