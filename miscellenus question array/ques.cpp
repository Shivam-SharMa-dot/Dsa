/* #include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countWords(string list[], int n)
    {
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[list[i]]++;
        }
        int count = 0;
        for (auto val : m)
        {
            if (val.second == 2)
                count++;
        }
        return count;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string list[n];
        for (int i = 0; i < n; i++)
            cin >> list[i];
        Solution ob;
        cout << ob.countWords(list, n) << endl;
    }
    return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    sort(nums.begin(), nums.end()); // nlogn
    for (int i = 0; i < nums.size(); i++)
    {
        int fo = i + 1;
        if (nums[i] == nums[fo])
        {
            ans.push_back(nums[i]);
        }
        else
        {
            fo++;
        }
    }
    return ans;
}
int main()
{
  //  vector<int >a={4,3,2,7,8,2,3,1};
   // vector<int >a={1,1,2};
    vector<int >a={1};
vector<int> ch=findDuplicates(a);
for(auto l:ch){
    cout<<l<<" ";
}
cout<<endl;
    return 0;
} */
