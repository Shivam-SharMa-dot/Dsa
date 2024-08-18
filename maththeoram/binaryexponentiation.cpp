// we uses binary exponentiation to find power of a,b
// we uses modulo expression for large number and for it is used for large number
// a=1e18+7;

// case-1; if a=10^18 range use modulo like a=%m
//  case-2; if m is of range 10^18  then we will use another concept
// case-3 if b is of range 10^18 then
/* #include <bits/stdc++.h>
const int m = 1e9 + 7;
using namespace std;
int binaryExp(int a, int b)
{
    a=a%m;// if a is of big range
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans* 1LL* a)%m; // we cannot do direct multiplication in case number 2 because it will overflow
        }
        a =( a *1LL* a)%m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int a = 20;
    int b = 21;
    cout << binaryExp(a, b);
    return 0;
} */
// case 2  m=10^18 // it will overflow see concept luv
#include <bits/stdc++.h>
const int m = 1e18 + 7;
using namespace std;
int binaryMultiply(long long a, long long b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a)%m;
        }
        a = (a + a)%m;  
        b >>= 1;
    }
    return ans;
}
int binaryExp(int a, int b)
{
    a = a % m; // if a is of big range
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = binaryMultiply(ans, a);
        }
        a = binaryMultiply(a, a);
        b >>= 1;
    }
    return ans;
}
int main()
{
    int a = 200;
    int b = 200;
    cout << binaryMultiply(a, b) << endl;
    cout << binaryExp(a, b);
    return 0;
}