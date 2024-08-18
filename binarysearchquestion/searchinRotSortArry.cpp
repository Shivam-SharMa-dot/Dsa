int pivot(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
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
int binarysearch(vector<int> &arr, int s, int e, int key)
{
    int start = s;
    int end = e;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key < arr[mid])
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
    int getpivot = pivot(arr, n);
    if (k >= arr[getpivot] && k <= arr[n - 1])
    {
        return binarysearch(arr, getpivot, n - 1, k);
    }
    else
    {
        return binarysearch(arr, 0, getpivot - 1, k);
    }
}
