/* //complexity is O(log(root n))
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            cout << i << " " << n / i << endl;
            sum += i;
            if (n / i != i)
            {
                sum += n / i;
                cnt++;
            }
        }
    }
    cout << "total number of divisor is " <<  cnt << endl;
    cout << " sum of divisor is " <<  sum << endl;

    return 0;
} */
//pattern hackerrank 
//5 5 5 5 5 5 5 5 5 
//5 4 4 4 4 4 4 4 5 
//5 4 3 3 3 3 3 4 5 
//5 4 3 2 2 2 3 4 5 
//5 4 3 2 1 2 3 4 5 
//5 4 3 2 2 2 3 4 5
//5 4 3 3 3 3 3 4 5
//5 4 4 4 4 4 4 4 5
//5 5 5 5 5 5 5 5 5

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int m = 2 * n;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int everyindex =max(abs(i-n), abs(j-n));
            cout << everyindex+1 << " ";
        }
        cout << endl;
    }

    return 0;
}