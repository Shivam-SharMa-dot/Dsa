#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleSolution(vector<int> &nums, int n, int k, int mid)
    {
        int countofsplit = 1;
        int succsum = 0;
        for (int i = 0; i < n; i++)
        {
            if (succsum + nums[i] <= mid)
            {
                succsum += nums[i];
            }
            else
            {
                countofsplit++;
                // we have to check if count of split not become greater than k beacuse we have to not split mpre than k
                if (countofsplit > k || nums[i] > mid)
                {
                    return false;
                }
                // make again succsum=0  and asign new sum
                succsum = 0;
                succsum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int s = 0;
        int e = sum;
        int ans = -1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (isPossibleSolution(nums, n, k, mid))
            {
                // so this could be a probable answer
                ans = mid;
                e = mid - 1;
            }
            else
            {
                // if they are not being able to make till mid then obviously they will not be able to makein
                // small sum of midso s=mid+1;
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};