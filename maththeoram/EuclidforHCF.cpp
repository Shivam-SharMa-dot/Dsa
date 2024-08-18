// Euclid algo is used to find gcd/hcf of two number
//  formula   gcd(a,b)=gcd(a-b,b)
// or GCD(x,y) = GCD(x%y,y)
//<--------------iterative approach---------------->
/* #include <bits/stdc++.h>
using namespace std;
int Findgcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return b;
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Findgcd(b, a % b);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << Findgcd(a, b);

    return 0;
} */
//<--------------recursive approach---------------->
//Time Complexity: O(Log min(a, b))
#include <bits/stdc++.h>
using namespace std;
int Findgcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Findgcd(b, a % b);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << Findgcd(a, b);

    return 0;
}


//
Some Problems Based on Euclid’s Algorithm:

Program to find the LCM of two numbers using GCD.
Program to find GCD of floating-point numbers.
Program to find the common ratio of three numbers.
Program to find GCD of an array of integers.
Program to find the sum of squares of N natural numbers.