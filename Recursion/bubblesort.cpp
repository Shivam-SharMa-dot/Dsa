/* #include <bits/stdc++.h>
#define v vector<int>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}
int main()
{
    v arr = {4, 1, 6, 9, 0};
    bubbleSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
} */
// find factorial number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> v;
    long long ans = 1;
    void fact(long long n, long long i)
    {
        ans = ans * i;
        if (ans > n)
        {
            return;
        }
        v.push_back(ans);
        fact(n, i + 1);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        fact(N, 1);
        return v;
    }
};
int main()
{
 

    return 0;
}