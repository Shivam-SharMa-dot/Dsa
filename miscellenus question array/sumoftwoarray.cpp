#include <bits/stdc++.h>
#define v vector<int>
using namespace std;
class Solution
{
public:
    vector<int> reverse(vector<int> nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(nums[s++], nums[e--]);
        }
        return nums;
    }
    vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
    {
        vector<int> ans;
        int sum = 0;
        int carry = 0;
        int i = n - 1;
        int j = m - 1;
        while (i >= 0 && j >= 0)
        {
            sum = a[i] + b[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
            j--;
        }
        while (i >= 0)
        {
            sum = a[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }
        while (j >= 0)
        {
            sum = b[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            j--;
        }
        if (carry != 0)
        {
            ans.push_back(carry);
        }

        return reverse(ans);
    }
};
int main()
{
    Solution obj;
    vector<int> a = {5, 6, 3};
    vector<int> b = {8, 4, 2};
    vector<int> ans = obj.findArraySum(a, 3, b, 3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}