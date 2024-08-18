/* #include <bits/stdc++.h>
// staircase problem is saame as fibnocci sequence difference is that fib secq starts with 0 but staircae woth 1 so differnt base case
using namespace std;
class solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if(n==1 || n==2){
            return n;
        }
        return countWays(n-1)+countWays(n- 2);

    }
};
int main()
{

    return 0;
} */

// #include <bits/stdc++.h>
// #define v vector<int>
// using namespace std;
/* vector<int> remove(vector<int> nums)
{
    int n = nums.size();
    vector<int> temp;
    if (n == 0 || n == 1)
    {
        return nums;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            temp.push_back(nums[i]);

        }
    }
    return temp;
} */

