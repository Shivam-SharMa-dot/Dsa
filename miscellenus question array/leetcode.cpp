// CPP program to count frequencies of array items
// system function system("pause");
#include <bits/stdc++.h>
using namespace std;
/* class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int fo=i+1;
            if(nums[i]==nums[fo]){
               count++;
            }
            if(count==2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
}; */
bool checkPalindrome(string s)
{
    int st=0;
    int e=s.length()-1;
    while (st<e)
    {
      if(s[st]!=s[e]){
        return 0;
      }
      else{
        st++;
        e--;
      }
    }
    return 1; 
}
int main()
{
    
     
    return 0;
}
