// #include <bits/stdc++.h>
// using namespace std;

// double e(int x, int n)
// {
//     static double p = 1, f = 1;
//     double r;
//     if (n == 0)
//         return 1;
//     r = e(x, n - 1);
//     p = p * x;
//     f = f * n;
//     return r + p / f;
// }
// int main()
// {
//     printf("%lf \n", e(4, 15));
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
       double x = log(n) / log(3);
        if ((int)x % 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
int n=27;
cout<<log(n) / log(3);
    return 0;
}