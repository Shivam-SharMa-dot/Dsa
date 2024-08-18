#include <bits/stdc++.h>
using namespace std;
void Saydigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;
    Saydigit(n, arr);
    cout << arr[digit] << " ";
}
int main()
{
    int n;
    cin >> n;
    string arr[10] = {"zero", "one", "two", "three", "four", "five",
                      "six", "seven", "eight", "nine"};
    Saydigit(n, arr);

    return 0;
}