/* #include <bits/stdtr1c++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count=0;
  while(n){
    if (n & 1 == 1)
    count++;

    n=n>>1;
  }
  cout<<count;
    return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>=1;
    }
    return count;
}
int main()
{
    int i = 15;
    cout << countSetBits(i);
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;

int count_bits(int n)
{
    int c = 0;
    while (n >= 1)
    {
        if ((n & 1) == 1)
            c++;
        n >>= 1;
    }
    return c;
}

void solve()
{
    int n;
    cin >> n;
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        counter += count_bits(i);
    }
    cout << counter << endl;
}

int main()
{
    solve();
    return 0;
}
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int count = 0;
        if (n > 9)
        {
            x = (n / 10) + 9;
            cout << x << endl;
        }
        else
        {
            cout << n << endl;
        }
    }

    return 0;
}