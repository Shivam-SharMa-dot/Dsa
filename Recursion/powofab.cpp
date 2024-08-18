// #include <iostream>
// using namespace std;

// int power(int a, int b)
// {
//     // base case
//     if (b == 0)
//         return 1;

//     if (b == 1)
//         return a;

//     // RECURSIVE CALL
//     int ans = power(a, b / 2);

//     // if b is even
//     if (b % 2 == 0)
//     {
//         return ans * ans;
//     }
//     else
//     {
//         // if b is odd
//         return a * ans * ans;
//     }
// }

// int main()
// {

//     int a, b;
//     cin >> a >> b;
//     cout << endl;
//     int ans = power(a, b);

//     cout << "Answer is " << ans << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int power(int m, int n)
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}

// less number of steps
int power1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n / 2);
    return m * power1(m * m, (n - 1) / 2);
}
int main()
{
    int r = power1(2, 3);
    printf("%d ", r);
    return 0;
}