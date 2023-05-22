//24题 危险的组合
//#include <stdio.h>
//#include <math.h>
//int couple(int n)
//{
//    if(n <= 2)
//        return 0;
//    else if(n == 3)
//        return 1;
//    else
//        return (2 * couple(n - 1) + pow(2,(n - 4)) - couple(n - 4));
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int result = couple(n);
//    printf("%d", result);
//    return 0;
//}

//25题 除法
//#include <stdio.h>
//int judge(int n, int m)
//{
//    int arr[11], i, j;
//    if (n < 10000)
//    {
//        arr[5] = 0;
//        for (i = 1; i <= 4; i++)
//        {
//            arr[i] = n % 10;
//            n = n / 10;
//        }
//        for (i = 6; i <= 10; i++)
//        {
//            arr[i] = m % 10;
//            m = m / 10;
//        }
//    }
//    else
//    {
//        for (i = 1; i <= 5; i++)
//        {
//            arr[i] = n % 10;
//            n = n / 10;
//        }
//        for (i = 6; i <= 10; i++)
//        {
//            arr[i] = m % 10;
//            m = m / 10;
//        }
//    }
//    for (i = 1; i < 10; i++)
//    {
//        for (j = i + 1; j <= 10; j++)
//        {
//            if (arr[i] == arr[j])
//            {
//                return 0;
//            }
//        }
//    }
//    if (i == 10)
//        return 1;
//    else
//        return 0;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int a, b;
//    int x;
//    for (a = 1234; a <= 98765; a++)
//    {
//        if (a * n <= 98765)
//        {
//            b = a * n;
//            x = judge(a, b);
//        }
//        else
//            break;
//        if (x)
//        {
//            if (a < 10000)
//            {
//                printf("%d/0%d=%d\n", b, a, n);
//            }
//            else
//            {
//                printf("%d/%d=%d\n", b, a, n);
//            }
//
//        }
//    }
//    return 0;
//}

//26题 特殊整数
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int m, n, k;
//    scanf("%d %d", &m, &n);
//    long long num1 = pow(10, n - 1);
//    long long num2 = pow(10, n);
//    long long i, j, sum = 0;
//    int count = 0;
//    int arr[10];
//    for(i = num1; i < num2; i++)
//    {
//        j = i;
//        for(k = 1; k <= n; k++)
//        {
//            arr[k] = j % 10;
//            j = j / 10;
//            if(arr[k] == m)
//            {
//                if(i % m != 0)
//                {
//                    count++;
//                    sum += i;
//                    break;
//                }
//            }
//        }
//
//    }
//    printf("%d %lld", count, sum);
//    return 0;
//}

//27 分数化小数
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int a, b, c, i;
//    scanf("%d %d %d", &a, &b, &c);
//
//    int zheng = (int)a / b;
//    printf("%d.", zheng);
//
//    int xiao = a % b;
//    for(i = 1; i < c; i++)
//    {
//        xiao *= 10;
//        printf("%d", xiao / b);
//        xiao %= b;
//    }
//    xiao *= 10;
//    printf("%d", ((xiao % b) * 10 / b > 5) ? (xiao / b + 1) : (xiao / b));
//
//    return 0;
//}

//28幸运数字7
//#include <stdio.h>
//int main()
//{
//    int n, i, k, l;
//    scanf("%d", &n);
//    for(i = 1; i <= n; i++)
//    {
//        k = i;
//        if(i % 7 == 0)
//        {
//            printf("%d ", i);
//            continue;
//        }
//        while(k)
//        {
//            l = k % 10;
//            if(l == 7)
//            {
//                printf("%d ", i);
//                break;
//            }
//            k /= 10;
//
//        }
//    }
//    return 0;
//}

//29求解不等式
//#include <stdio.h>
//int main()
//{
//    int a, b, i;
//    scanf("%d %d", &a, &b);
//    int sum = 1;
//    int xiang = 1;
//    int chu, count = 0;
//    if((a < 1) && (1 < b))
//        printf("0");
//    else
//    {
//        for(i = 2; ; i++)
//        {
//            xiang = xiang + 1 / i;
//            chu = 1 / xiang;
//            sum += chu;
//            if((a < sum) && (sum < b))
//            {
//                count++;
//            }
//            if(count == 1)
//                printf("%d ", i);
//            if(sum > b)
//            {
//                printf("%d", i - 1);
//                break;
//            }
//        }
//    }
//
//    return 0;
//}

//30粒子裂变
//#include <stdio.h>
//int main()
//{
//    int t, i, j;
//    scanf("%d", &t);
//    int a = 0, b = 3;
//    if(t == 1)
//    {
//        printf("%d %d", a, b);
//    }
//    else
//    {
//        for(i = 2; i <= t; i++)
//        {
//            j = a;
//            a = 0;
//            a = b;
//            b = 3 * j + b * 2;
//        }
//        printf("%d %d", a, b);
//    }
//    return 0;
//}

//31发工资的日子
//#include <stdio.h>
//int main()
//{
//    int n, i, count = 0;
//    int arr[101];
//    scanf("%d", &n);
//    for(i = 1; i <= n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for(i = 1; i <= n; i++)
//    {
//        while(arr[i])
//        {
//            if(arr[i] >= 100)
//            {
//                count = count + (arr[i] / 100);
//                arr[i] -= (arr[i] / 100) * 100;
//            }
//            if(arr[i] >= 50 && arr[i] < 100)
//            {
//                count++;
//                arr[i] -= 50;
//            }
//            if(arr[i] >= 10 && arr[i] < 50)
//            {
//                count = count + (arr[i] / 10);
//                arr[i] -= (arr[i] / 10) * 10;
//            }
//            if(arr[i] >= 5 && arr[i] < 10)
//            {
//                count++;
//                arr[i] -= 5;
//            }
//            if(arr[i] >= 2 && arr[i] < 5)
//            {
//                count = count + (arr[i] / 2);
//                arr[i] -= (arr[i] / 2) * 2;
//            }
//            if(arr[i] == 1)
//            {
//                count++;
//                arr[i] = 0;
//            }
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//32最大整数
//#include <stdio.h>
//int getfloor(double n)
//{
//    int i = (int) n;
//    if(n >= 0)
//    {
//        return i;
//    }
//    else
//    {
//        i -= 1;
//        return i;
//    }
//}
//int main()
//{
//    double x;
//    scanf("%lf", &x);
//    printf("%d", getfloor(x));
//    return 0;
//}

//33循环移位
//#include <stdio.h>
//int move(int value, int n)
//{
//
//}
//int main()
//{
//    int value, n;
//    scanf("%d %d", &value, &n);
//    printf("%d", move(value, n));
//    return 0;
//}

//34 ACKERMAN
//#include <stdio.h>
//int ack(int m, int n)
//{
//    if(m == 0)
//        return n + 1;
//    else if(m != 0 && n == 0)
//        return ack(m - 1, 1);
//    else
//        return ack(m - 1, ack(m, n - 1));
//}
//int main()
//{
//    int m, n;
//    scanf("%d %d", &m, &n);
//    printf("%d", ack(m, n));
//    return 0;
//}

//35逆序整数
//#include <stdio.h>
//void print(long long n)
//{
//    if(n % 10 > 0)
//        printf("%lld", n % 10);
//    if(n / 10 > 0)
//        print(n / 10);
//}
//int main()
//{
//    long long n;
//    scanf("%lld", &n);
//    print(n);
//    return 0;
//}

//36高低交换
//#include <stdio.h>
//int main()
//{
//    int m;
//    scanf("%d", &m);
//    unsigned char n = (unsigned char) m;
//    printf("%d", inline int xchg())
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("ab c\t");
//	printf(" de\r");
//	printf("f\t");
//	printf("g\n");
//	printf("ab c\t de\rf\tg\n");
//	return 0;
//}

//37组合数
//#include <stdio.h>
//void combinations(int n, int m)
//{
//    if((n < 0 || m < 0) || n < m)
//    {
//        printf("wrong");
//        return;
//    }
//    else if(n == 0 || m == 0)
//    {
//        printf("1");
//        return;
//    }
//    else
//    {
//        int result = 1, a = 1, i;
//        for(i = 1; i <= m; i++)
//        {
//            result *= n;
//            a *= i;
//            n--;
//        }
//        result /= a;
//        printf("%d", result);
//    }
//
//}
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    combinations(n, m);
//    return 0;
//}

//38积分计算
//#include <stdio.h>
//double fx (double begin)
//{
//    double result = 1.0 / (1.0 + begin * begin);
//    return result;
//}
//double integral (double a, double b)
//{
//     double h = (b - a) / 10000000;
//     double begin;
//     double sum = 0;
//     for(begin = a; begin <= b - h; begin+=h)
//     {
//         sum += (fx(begin) + fx(begin + h)) * h / 2;
//     }
//     return sum;
//}
//int main()
//{
//    double a, b;
//    scanf("%lf %lf", &a, &b);
//    printf("%lf", integral(a, b));
//    return 0;
//}

//39最小整数
//#include <stdio.h>
//int fceil(double x)
//{
//    if(x >= 0)
//    {
//        int n = (int)x;
//        if(n == x)
//            return n;
//        else
//            return (n + 1);
//    }
//    else
//    {
//        int n = (int)x;
//        return n;
//    }
//}
//int main()
//{
//    double x;
//    scanf("%lf", &x);
//    printf("%d", fceil(x));
//    return 0;
//}

//40亲和数
//#include <stdio.h>
//void amicable(int a, int b)
//{
//    int suma = 1, sumb = 1, i;
//    for(i = 2; i < a; i++)
//    {
//        if(a % i == 0)
//        {
//            suma += i;
//        }
//    }
//    for(i = 2; i < b; i++)
//    {
//        if(b % i == 0)
//        {
//            sumb += i;
//        }
//    }
//    if(suma == b && sumb == a)
//    {
//        printf("YES");
//        return;
//    }
//    else
//    {
//        printf("NO");
//        return;
//    }
//}
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    amicable(a, b);
//    return 0;
//}

//41右上角
//#include <stdio.h>
//int main()
//{
//    int n, i, j;
//    scanf("%d", &n);
//    int arr[n][n];
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j <n ;j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for(i = 0; i < n; i++)
//    {
//        if(i > 0)
//        {
//            int a;
//            for(a = 1; a <= i; a++)
//            {
//                printf("  ");
//            }
//        }
//        for(j = i; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//42恐怖水母
//#include <stdio.h>
//void bubble(int arr[], int n)
//{
//    int a, b, tmp;
//    for(a = 1; a < n; a++)
//    {
//        for(b = 1; b < n - a + 1; b++)
//        {
//            if(arr[b] > arr[b + 1])
//            {
//                tmp = arr[b];
//                arr[b] = arr[b + 1];
//                arr[b + 1] = tmp;
//            }
//        }
//    }
//}
//int main()
//{
//    int n, m, i, j, money = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[n + 1];
//    int arr2[m + 1];
//    for(i = 1; i <= n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for(i = 1; i <= m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    bubble(arr1, n);
//    bubble(arr2, m);
//    int p = 0;
//    for(i = 1; i <= n; i++)
//    {
//        for(j = 1; j <= m; j++)
//        {
//            if(arr2[j] >= arr1[i])
//            {
//                money += arr2[j];
//                p = 1;
//                arr2[j] = 0;
//                break;
//            }
//        }
//        if(p == 0)
//        {
//            break;
//        }
//    }
//    if(p == 0)
//        printf("NULL");
//    else
//        printf("%d", money);
//    return 0;
//}

//43平均值函数
//#include <stdio.h>
//double avg(int A[], int s, int e)
//{
//    int a;
//    double sum = 0;
//    for(a = s; a <= e; a++)
//    {
//        sum += A[a];
//    }
//    double b = (double)(e - s + 1);
//    double result = sum / b;
//    return result;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int A[100], i;
//    for(i = 0; i < n; i++)
//    {
//        scanf("%d", &A[i]);
//    }
//    int s, e;
//    scanf("%d %d", &s, &e);
//    printf("%lf", avg(A, s, e));
//    return 0;
//}

//44边沿与内芯的差
//#include <stdio.h>
//int main()
//{
//    int n, m, i, j;
//    scanf("%d %d", &n, &m);
//    int arr[100][100];
//    for(i = 0; i <n; i++)
//    {
//        for(j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int s1 = 0, s2 = 0, sum = 0;
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//        {
//            sum += arr[i][j];
//        }
//    }
//    for(j = 0; j < m; j++)
//    {
//        s1 += (arr[0][j] + arr[n - 1][j]);
//    }
//    for(i = 1; i < n - 1; i++)
//    {
//        s1 += (arr[i][0] + arr[i][j - 1]);
//    }
//    s2 = sum - s1;
//    printf("%d", s1 - s2);
//    return 0;
//}

//45山迪的麻烦
//#include <stdio.h>
//int main()
//{
//    int n, count = 0, i, j, tmp;
//    scanf("%d", &n);
//    int arr[101];
//    for(i = 1; i <= n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for(i = 1; i < n; i++)
//    {
//        for(j = 1; j < n - i + 1; j++)
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                count++;
//                tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//46左上角
//#include <stdio.h>
//int main()
//{
//    int n, i, j, k;
//    scanf("%d", &n);
//    int arr[100][100];
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n - i; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        for(k = 0; k < i; k++)
//        {
//            printf("  ");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//47右下角
//#include <stdio.h>
//int main()
//{
//    int n, i, j, k;
//    scanf("%d", &n);
//    int arr[100][100];
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for(i = 0; i < n; i++)
//    {
//        for(k = 0; k < n - i - 1; k++)
//        {
//            printf("  ");
//        }
//        for(j = n - i - 1; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//48选择排序
//#include <stdio.h>
//void Selection(int A[], int s, int m)
//{
//    int a, b, k, tmp;
//    for (a = 1; a < m; a++)
//    {
//        k = s + a - 1;
//        for (b = s + a - 1; b < s + m - 1; b++)
//        {
//            if (A[k] < A[b + 1])
//                k = b + 1;
//        }
//        if (k != s + a - 1)
//        {
//            tmp = A[s + a - 1];
//            A[s + a - 1] = A[k];
//            A[k] = tmp;
//        }
//    }
//}
//int main()
//{
//    int n, i;
//    scanf("%d", &n);
//    int arr[100];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int s, m;
//    scanf("%d %d", &s, &m);
//    Selection(arr, s, m);
//    for (i = 0; i < n; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//49左下角
//#include <stdio.h>
//int main()
//{
//    int n, i, j, k;
//    scanf("%d", &n);
//    int arr[100][100];
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j <= i; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        for(k = 0; k < n - i - 1; k++)
//        {
//            printf("  ");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//50插入排序
//#include <stdio.h>
//void InsertionSort(int A[], int s, int m)
//{
//    int a, b;
//    int tmp;
//    for(a = 1; a < m; a++)
//    {
//        for(b = s + a; b > s; b--)
//        {
//            if(A[b] > A[b - 1])
//            {
//                tmp = A[b];
//                A[b] = A[b - 1];
//                A[b - 1] = tmp;
//            }
//        }
//    }
//}
//int main()
//{
//    int n, i;
//    scanf("%d", &n);
//    int arr[100];
//    for(i = 0; i < n; i++)
//        scanf("%d", &arr[i]);
//    int s, m;
//    scanf("%d %d", &s, &m);
//    InsertionSort(arr, s, m);
//    for(i = 0; i < n; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}














