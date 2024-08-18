/* #include <bits/stdc++.h>
using namespace std;
double  geometricsum(int n)
{
    if (n == 0)
    {
        return 1;
    }
    double ans = (double)1 / pow(2, n) + geometricsum(n - 1);
    return ans;
}
int main()
{
    int n = 4;
    cout << geometricsum(n);
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
void reverse(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str, i, j);
}
string reverseString(string str)
{
    // Write your code here.
    reverse(str, 0, str.length() - 1);
    return str;
}
int main()
{
    string str = "abcde ";
    cout << reverseString(str);
    return 0;
}