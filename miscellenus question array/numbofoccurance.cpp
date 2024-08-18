#include <bits/stdc++.h>
using namespace std;
int firstoccurance(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int lastoccurance(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 2, 1, 0};
    int x = 2; // Element to be counted in arr[]
    int n = sizeof(arr) / sizeof(arr[0]);
    int y = firstoccurance(arr, n, x);
    int z = lastoccurance(arr, n, x);
    cout<<z-y+1;

    return 0;
}
