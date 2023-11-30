#include <iostream>
using namespace std;
int tsearch(int arr[], int x, int left, int right)
{
    if(left > right)
        return -1;
    int mid = (left + right) / 2;
    if(x < arr[mid])
    {
        return tsearch(arr, x, left, mid - 1);
    }
    else if(x > arr[mid])
    {
        return tsearch(arr, x, mid + 1, right);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int n, m, r, i = 0;
    int arr[10000], search[50000];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> search[i];
    }
    for(i = 0; i < m; i++)
    {
        r = tsearch(arr, search[i], 0, n - 1);
        if(r == -1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}