
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPossiblesolution(int n, int m, vector<int> time, long long mid)
{
    int timesum = 0;
    int daycount = 1;
    for (int i = 0; i < m; i++)
    {
        if (timesum += time[i] <= mid)
        {
            timesum += time[i];
        }
        else
        {
            daycount++;
            if (daycount > n || time[i] > mid)
            {
                return false;
            }
            // if all good you can allocate to 2nd student
            timesum = 0;
            timesum += time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
    }
    int s = 0;
    long long e = sum;
    long long mid = s + (e - s) / 2;
    long long ans = -1;
    while (s < e)
    {
        if (isPossiblesolution(n, m, time, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
// 1
// 3 5
// 1 2 2 3 1
int n = 3,m = 5;
vector <int> time={1,2,2,3,1};
cout<<ayushGivesNinjatest(n,m,time)<<endl;
    return 0;
}