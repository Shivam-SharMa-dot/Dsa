#include <bits/stdc++.h>
using namespace std;
vector<int> printSeries(int n, int k)
{
    vector<int> ans;
    n = n - k;
    if (n < 0)
    {
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> m = printSeries(n, k);
    for (int i : m)
    {
        cout << i << " ";
    }

    return 0;
}