// using pascal triangle method and recursion
// 2nd approch will be to find factorial alone and after doing it divide it according to formula
#include <bits/stdc++.h>
using namespace std;
int NCR(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << NCR(n, r);

    return 0;
}