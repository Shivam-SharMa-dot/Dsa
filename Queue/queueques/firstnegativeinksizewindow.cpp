#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    deque<long long int> dq;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(A[i]);
        }
    }
    for (int i = K; i <= N; i++)
    {
        if (!dq.empty())
        {
            ans.push_back(dq.front());
        }
        else
        {
            ans.push_back(0);
        }
        // remove the others
        if (!dq.empty() && dq.front() == A[i - K])
        {
            dq.pop_front();
        }

        if (i < N && A[i] < 0)
        {
            dq.push_back(A[i]);
        }
    }

    return ans;
}
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<long long> ans;
    deque<long long int> dq;
    // first k size window processed
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(A[i]);
        }
    }

    for (int i = K; i <= N; i++)
    {
        if (!dq.empty())
        {
            ans.push_back(dq.front());
        }
        else
        {
            ans.push_back(0);
        }

        // removal of element from
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        if(A[i] < 0){
            dq.push_back(A[i]);
        }
    }
    return ans;
}

// vector<long long> printFirstNegativeInteger(long long int A[],
//                                             long long int N, long long int K)
// {

//     vector<long long> ans;
//     deque<long long int> dq;
//     for (int i = 0; i < K; i++)
//     {
//         if (A[i] < 0)
//         {
//             dq.push_back(A[i]);
//         }
//     }
//     for (int i = K; i <= N; i++)
//     {
//         if (!dq.empty())
//         {
//             ans.push_back(dq.front());
//         }
//         else
//         {
//             ans.push_back(0);
//         }
//         // remove the others
//         if (!dq.empty() && dq.front() == A[i - K])
//         {
//             dq.pop_front();
//         }

//         if (i < N && A[i] < 0)
//         {
//             dq.push_back(A[i]);
//         }
//     }

//     return ans;
// }
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;
        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}