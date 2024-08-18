//this approch is called 2pointer aapproch 
// we have maded fix one pointer and increasing one https://www.youtube.com/watch?v=fj1g_-BwCMk&t=25s
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int x)
{
    vector<vector<int>> ans;
    set<vector<int>> temp;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            int curr = arr[i] + arr[lo] + arr[hi];
            if (curr == x)
            {

                temp.insert({arr[i], arr[lo], arr[hi]});
              
            }
            if (curr < x)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }
      for (auto l : temp)
                {
                    ans.push_back(l);
                }
    return ans;
}

int main()
{

    return 0;
}