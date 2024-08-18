/* #include <bits/stdc++.h>
using namespace std;
void afterremovingX(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] != 'x')
    {
        afterremovingX(s + 1);
    }
    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        afterremovingX(s);
    }
}
int length(char s[])
{
    if (s[0] == '\0')
    {
        return 0;
    }
    int nextsmallerstring = length(s + 1);
    return 1 + nextsmallerstring;
}
int main()
{
    char str[100];
    cin >> str;
    cout << length(str) << endl;
    afterremovingX(str);
    cout << str << endl;
    cout << length(str) << endl;

    return 0;
} */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool issafe(vector<vector<int>> &m, vector<int> visited, int x, int y)
    {
    }
    void solve()
    {
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
    }
};

