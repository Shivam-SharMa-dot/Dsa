// 3pointer awessome question
//<--------question name 3sumcloset  leetcode--------->
//https://leetcode.com/problems/3sum-closest/description/
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int closet = 0;
    int mindiff = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            int x = nums[i] + nums[lo] + nums[hi];
            if (x == target)
            {
                return x;
            }
            if (x < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
            int diff = abs(x - target);
            if (diff < mindiff)
            {
                mindiff = diff;
                closet = x;
            }
        }
    }
    return closet;
}
int main()
{
    vector<int> a;
    for (int i = 0; i < a.size(); i++)
        cin>>a[i];
    int target = -7111;
    cout << threeSumClosest(a, target) << endl;
   
    return 0;
}
