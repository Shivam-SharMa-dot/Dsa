#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sort012(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = 0;
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[start]);
            mid++;
            start++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}
int main()
{
    int arr[8] = {1, 1, 2, 0, 2, 0, 1, 0};

    sort012(arr, 8);
    printArray(arr, 8);
    return 0;
}