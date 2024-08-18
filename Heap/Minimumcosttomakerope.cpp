#include <iostream>
#include <queue>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        // max heap of size 100 can be created
        // arr[100];
        size = 0;
    }
};
class Solution
{
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        long long size = pq.size();
        long long cost = 0;
        while (size > 1)
        {

            long long f = pq.top();
            pq.pop();

            long long s = pq.top();
            pq.pop();

            long long sum = f + s;
            cost += sum;

            pq.push(sum); 
        }
        return cost;
    }
};
int main()
{
    return 0;
}