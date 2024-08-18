// here we check how many numbers of prime numbers are present till the number
// but here complexity is of n square

/* 
#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n % i == 0)
        {
            return false;
        }
        return true;
    }
}
int Countprime(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isprime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int m;
    cin >> m;
    // if (isprime(m))
    // {
    //     cout << "is aprime number"<<endl;
    // }
    // else
    // {
    //     cout << " not a prime number"<<endl;
    // }
    int k = Countprime(m);
    cout << k;
    return 0;
}*/

// Sieve of Eratosthenes theoram to check number of prime numbers till the number
// T.c=O(nloglogn)
/* #include <bits/stdc++.h>
using namespace std;
 int countPrimes(int n) {
        int count=0;
       vector<bool> prime(n+1,true);
       prime[0]=prime[1]=false;
       for(int i=2;i<n;i++){
           if(prime[i]){
               count++;
       for(int j=2*i;j<n;j=j+i){
           prime[j]=0;
       }
           }
       }
        return count;
    }
int main()
{
    int n;
    cin >> n;
cout<<countPrimes(n);
    return 0;
} */

// to print  prime numbers till n
#include <bits/stdc++.h>
using namespace std;
vector<int> sieveOfEratosthenes(int n)
{
    // Write Your Code here
    vector<int> ans;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            ans.push_back(i);
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
  
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> primes = sieveOfEratosthenes(n);
        for (auto l : primes)
        {
            cout << l << " ";
        }
        cout << endl;
    }

    return 0;
}