//  if smallest number is pivot
// this code will work only in sortes and rotated array not in only sorted array
/* #include <bits/stdc++.h>
using namespace std;
int pivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{
    int arr[7] = {8, 9, 10,3, 4, 5, 6};
    cout << pivot(arr, 5) << endl;
    return 0;
} */
// search in rotated array
#include <bits/stdc++.h>
using namespace std;
int getpivot(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
int binarysearch(vector<int> &arr, int start, int end, int key)
{
    start = 0;
    end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int findPosition(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int pivot = getpivot(arr, n);
    if (pivot == -1)
    {
        return binarysearch(arr, 0, n - 1, k);
    }
    else if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarysearch(arr, pivot, n - 1, k);
    }
    else
    {
        return binarysearch(arr, 0, pivot - 1, k);
    }
}
int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = arr.size();
    int k = 3;

    // Function calling
    cout << "Index of the element is : "
         << findPosition(arr, n, k);
    return 0;
}
