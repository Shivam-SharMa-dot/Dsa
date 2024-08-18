#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int countDistinctWays(int nStairs)
{
    //  Write your code here.
    if (nStairs == 0)
    {
        return 1;
    }
    if (nStairs == 1 || nStairs == 2)
    {
        return nStairs;
    }

    long long prev2 = 1;
    long long prev = 2;

    for (int i = 3; i <= nStairs; i++)
    {
        long long curr = prev + prev2;
        curr %= mod;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    long long n;
    cin >> n;
    cout << countDistinctWays(n);
    return 0;
}