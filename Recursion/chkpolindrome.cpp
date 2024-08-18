// #include <bits/stdc++.h>
// using namespace std;
// bool chkpolindrome(string s)
// {

// }
// int main()
// {
//     string s="abcdcba";
//     cout << chkpolindrome(s);
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// bool present(int arr[], int n, int x)
// {
//     if (n == 0)
//     {
//         return false;
//     }
//     if (x == arr[n-1])
//     {
//         return true;
//     }
//     return present(arr, n - 1, x);
// }
// int main()
// {
//     int arr[5] = {1, 2, 3, 4, 9};
//     int key;
//     cin >> key;
//     if (present(arr, 5, key))
//     {
//         cout << "present";
//     }
//     else
//     {
//         cout << "NOT present";
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// gotten TLE from this 
bool chkpolindrome(string s, int l, int r)
{

    if (l >= r)
    {
        return true;
    }
    if (s[l] != s[r])
    {
        return false;
    }
    return chkpolindrome(s, l +1,r-1);
}
int isPalindrome(string S)
{
    if (chkpolindrome(S, 0,S.size()-1) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int present(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (x == arr[0])
    {
        return 0;
    }
    int ans = present(arr + 1, n - 1, x);

    if (ans == -1)
    {
        return -1;
    }
    else
    {
        return ans + 1;
    }
}
int main()
{
    // int arr[5] = {1, 2, 3, 4, 9};
    // int key;
    // cin >> key;
    // cout << (arr, 5, key);
    string s = "rhar";
    cout << isPalindrome(s);

    return 0;
}