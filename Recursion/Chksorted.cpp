/* #include <bits/stdc++.h>
using namespace std;
bool Issorted(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = Issorted(arr + 1, n - 1);
        return ans;
    }
}
int main()
{
    int arr[5] = {1, 3, 5, 6, 8};
    if (Issorted(arr, 5))
    {
        cout << " Yes array is sortd" << endl;
    }
    else
    {
        cout << "nope array is not sorted" << endl;
    }
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;

string DecimalToBinary(long long num)
{
    string str;
    while (num)
    {
        if (num & 1) // 1
            str += '1';
        else // 0
            str += '0';
        num >>= 1; // Right Shift by 1
    }
    return str;
}
string reverse(string str)
{
    string s;
    for (int i = str.size() - 1; i >= 0; i--)
        s += str[i];
    return s;
}
bool chkpolindorme(string str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    return chkpolindorme(str, i++, j--);
}
bool checkPalindrome(long long N)
{
    int nDigits = floor(log10(abs(N))) + 1;
    if (chkpolindorme(reverse(DecimalToBinary(N)), 0, nDigits - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 10;
    if (checkPalindrome(n))
    {
        cout << "t";
    }
    else
    {
        cout << "n";
    }
    return 0;
}