//#include <stdio.h>
//int main()
//{
//    int a, b, c, i;
//    for (a = 4; ; a = a + 4)
//    {
//        b = 0;
//        c = a;
//        for (i = 1; i <= 4; i++)
//        {
//            b = c * 5 / 4 + 1;
//            if (b % 4 != 0)
//                break;
//            c = b;
//        }
//        if (i == 5)
//        {
//            printf("%d %d", b * 5 / 4 + 1, a);
//            break;
//        }
//    }
//    return 0;
//}

//奇特的分数数列
//#include <stdio.h>
//int main()
//{
//    double a = 1.0;
//    double b = 2.0;
//    double c = 3.0;
//    int i;
//    double sum = 0;
//    sum = (2.0 / 1.0) + (3.0 / 2.0);
//    for(i = 3; i <= 20; i++)
//    {
//        sum += ((b + c) / (a + b));
//        a = b;
//        b = c;
//        c = a + c;
//
//    }
//    printf("%.6lf", sum);
//    return 0;
//}

////整数数位
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    double a, b;
//    int count = 0;
//    scanf("%lf", &a);
//    b = fabs(a);
//    if(b < 1)
//        printf("0");
//    else
//    {
//        int c = (int)b;
//        while(c >= 1)
//        {
//            count++;
//            c = c / 10;
//        }
//        printf("%d", count);
//    }
//    return 0;
//}

////VOL大学乒乓球比赛
//#include <stdio.h>
//int main()
//{
//    char a, b, c;
//    for(a = 'X'; a <= 'Z'; a++)
//    {
//        for(b = 'X'; b <= 'Z'; b++)
//        {
//
//            for(c = 'X'; c <= 'Z'; c++)
//            {
//
//                if((a != 'X' && c != 'X') && (c != 'Z' && a != c) && (b != c && a != b))
//                {
//                    printf("A=%c\nB=%c\nC=%c\n", a, b, c);
//                }
//            }
//
//        }
//    }
//    return 0;
//}

////最次方数
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int x, a, i;
//    long long b;
//    scanf("%d %d", &x, &a);
//    int arr[3];
//    b = pow(x, a);
//    b = fabs(b);
//    if (b < 100 && b >= 10)
//    {
//        arr[0] = 0;
//        for (i = 2; i >= 1; i--)
//        {
//            arr[i] = b % 10;
//            b = b / 10;
//        }
//        for (i = 0; i <= 2; i++)
//        {
//            printf("%d", arr[i]);
//        }
//    }
//    else if (b < 10)
//    {
//        arr[0] = 0;
//        arr[1] = 0;
//        arr[2] = b;
//        for (i = 0; i <= 2; i++)
//        {
//            printf("%d", arr[i]);
//        }
//    }
//    else
//    {
//        for (i = 2; i >= 0; i--)
//        {
//            arr[i] = b % 10;
//            b = b / 10;
//        }
//        for (i = 0; i <= 2; i++)
//        {
//            printf("%d", arr[i]);
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int a1, a2, a3, a5, a8;
//    int y1, y2, y3, y5, y8;
//    double max = 0, fin;
//    for(a8 = 0; a8 <= 2; a8++)
//    {
//        for(a5 = 0; a5 <= ((20 - 8 * a8) / 5); a5++)
//        {
//            for(a3 = 0; a3 <= ((20 - 8 * a8 - 5 * a5) / 3); a3++)
//            {
//                for(a2 = 0; a2 <= ((20 - 8 * a8 - 5 * a5 - 3 * a3) / 2); a2++)
//                {
//                    a1 = 20 - 8 * a8 - 5 * a5 - 3 * a3 - 2 * a2;
//                    fin = 2000.0 * pow((1 + 8 * 12 * 0.0084), a8) * pow((1 + 5 * 12 * 0.0075), a5)* pow((1 + 3 * 12 * 0.0069), a3)* pow((1 + 2 * 12 * 0.0066), a2)* pow((1 + 1 * 12 * 0.0063), a1);
//                    if(fin > max)
//                    {
//                        max = fin;
//                        y1 = a1;
//                        y2 = a2;
//                        y3 = a3;
//                        y5 = a5;
//                        y8 = a8;
//                    }
//                }
//            }
//        }
//    }
//    printf("%d %d %d %d %d\n", y8, y5, y3, y2, y1);
//    printf("%.2lf", max);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    double result;
//    double mid;
//    double left = -10.0;
//    double right = 10.0;
//    while(1)
//    {
//        mid = (left + right) / 2.0;
//        if(2 * mid * mid * mid - 4 * mid * mid + 3 * mid - 6 == 0)
//        {
//            result = mid;
//            break;
//        }
//        else if(2 * mid * mid * mid - 4 * mid * mid + 3 * mid - 6 > 0)
//        {
//            right = mid;
//        }
//        else
//        {
//            left = mid;
//        }
//    }
//    printf("%.2lf", result);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a, b, i;
//    int c;
//    int count = 0;
//    for(a = 1; a <= 1000; a++)
//    {
//        c = 0;
//        for(b = 1; b < a; b++)
//        {
//            if(a % b == 0)
//            {
//                c += b;
//            }
//        }
//        if(c == a)
//        {
//            count = 0;
//            printf("%d=", a);
//            for(i = 1; i < a; i++)
//            {
//                if(a % i == 0)
//                {
//                    ++count;
//                    if(count == 1)
//                        printf("%d", i);
//                    else
//                        printf("+%d", i);
//                }
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    double a;
//    scanf("%lf", &a);
//    double xn1, xn2;
//    xn1 = a / 2.0;
//    xn2 = (1 / 2.0) * (xn1 + a / xn1);
//    while(1)
//    {
//        xn1 = xn2;
//        xn2 = (1 / 2.0) * (xn1 + a / xn1);
//        if(fabs(xn1 - xn2) <= 1e-5)
//        {
//            printf("%.5lf", xn2);
//            break;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    int i;
//    for(i = 10; i <= 100; i++)
//    {
//        if((i % 3 == a) && (i % 5 == b) && (i % 7 == c))
//        {
//            printf("%d", i);
//            break;
//        }
//    }
//    if(i == 101)
//    {
//        printf("-1");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n;
//    int count;
//    int sum = 0;
//    scanf("%d", &n);
//    long long i, j, k;
//    for(i = 0; ; i = i + 100)
//    {
//        for(j = i; j < i + 100; j++)
//        {
//            for(k = 2; k < j; k++)
//            {
//                if(j % k == 0)
//                {
//                    count++;
//                    break;
//                }
//            }
//            if(k == j)
//            {
//                break;
//                count = 0;
//            }
//        }
//        if(count == 100)
//        {
//            sum++;
//        }
//        if(sum == n)
//        {
//            printf("%lld %lld", i, i + 99);
//            break;
//        }
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double nlirun(int x)
{    double a;
    if(x==1)
    {
        a=1+0.0063*12*1;
    }
    else if(x==2)
    {
        a=1+0.0066*12*2;
    }
    else if(x==3)
    {
        a=1+0.0069*12*3;
    }
    else if(x==5)
    {
        a=1+0.0075*12*5;
    }
    else if(x==8)
    {
        a=1+0.0084*12*8;
    }
    return a;
}

//int main()
//{
//    int year =20;
//    int current=year;
//    double now=2000.0,max=0.0;
//    int out8,out5,out3,out2,out1;
//   for(int i=2;i>=0;i--)
//   {   now=2000.0;
//       year=20;
//       now=now*pow(nlirun(8),i);
//       //printf("%d ",i);
//       current=year-i*8;
//       for(int j=current/5;j>=0;j--)
//       {
//           now=now*pow(nlirun(5),j);
//           //printf("%d ",j);
//           current=current-j*5;
//           for(int k=current/3;k>=0;k--)
//           {
//               now=now*pow(nlirun(3),k);
//               //pritnf("%d")
//               current=current-k*3;
//               for(int l=current/2;l>=0;l--)
//               {
//                   now=now*pow(nlirun(2),l);
//                   current=current-l*2;
//                   for(int m=current;m>=0;m--)
//                   {
//                       now=now*pow(nlirun(1),m);
//                       if(now>max)
//                       {
//                           max=now;
//                           out8=i;out5=j;out3=k;out2=l;out1=m;
//
//                       }
//                   }
//               }
//           }
//       }
//   }
//   printf("%d %d %d %d %d\n%lf",out8,out5,out3,out2,out1,max);
//    return 0;
//}





























