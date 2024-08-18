#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
// naive approch
// int maxsumsubarray(int arr[], int n, int k)
// {
//     int maxsum = INT_MIN;
//     for (int i = 1; i <=n-k; i++)
//     {
//         int curr_sum = 0;
//         for (int j = 1; j <= k; j++)
//         {
//             curr_sum += arr[i+j];
//         }
//         maxsum = max(curr_sum, maxsum);
//     }
//     return maxsum;
// }

// think of like a bus window add one step forward and loose one step behind
int maxsumsubarray(int arr[], int n, int k)
{
    if (n < k)
    {
        return -1;
    }

    int maxsum = 0;
    for (int i = 0; i < k; i++)
    {
        maxsum += arr[i];
    }
    int windowsum = maxsum;
    for (int i = k; i < n; i++)
    {
        windowsum += arr[i] - arr[i - k]; //
        maxsum = max(windowsum, maxsum);
    }

    return maxsum;
}

// using window sliding technique

int main()
{
    int arr[] = {5, 2, -1, 0, 3, 5, 6, 3};
    int k = 3;
    cout << maxsumsubarray(arr, 8, k);

    return 0;
}