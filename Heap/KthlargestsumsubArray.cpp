#include <iostream>
#include <queue>
using namespace std;
// better approch t.c=O(n2) nad sc=O(k)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    //	Write your code here
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}