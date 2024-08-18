// question to find lowest prime and highest prime using Sieve of Eratosthenes theoram
// fault in this question something
/* #include <bits/stdc++.h>
using namespace std;
void Highestprime()
{
    int n;
    cin >> n;
    vector<int> lp(n, 0), hp(n, 0);
    vector<bool> isprime(n, true);
    isprime[0] = isprime[0] = false;
    for (int i = 2; i < n; i++)
    {
        if (isprime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = i * i; j < n; j += 2)
            {
                isprime[j] = false;
                hp[i] = j;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
}
int main()
{

    Highestprime();
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 10;

int main()
{
    vector<int> divisor(n);
    for (int i = 2; i < n; i++)
    {
        for (int j = i; j < n; j += i)
        {
            divisor[j].push_back(i);
        }
    }
    for (int i = 1; i < 10; i++)
    {
        for (int div : divisor[i])
        {
            cout << div << " " << endl ;
        }
        cout << endl;
    }

    return 0;
}