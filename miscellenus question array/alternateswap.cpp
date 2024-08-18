// for both even number of elements and odd number of element
/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int temp;
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        swap(ar[i], ar[i + 1]);
        // swap inside
       // temp = ar[i + 1];
       // ar[i+1] =ar[i];
       // ar[i]=temp;

    }

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int count;
    for (int i = 0; i < n; i++)
    {
       count=ar[i]^ar[i+1];
    }
    cout<<count<<endl;
    return 0;
} */
