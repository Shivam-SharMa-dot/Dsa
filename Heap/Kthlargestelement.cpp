class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        for(int j=k;j<nums.size();j++){
            int x = q.top();
            if( nums[j]>x){
                q.pop();
                q.push(nums[j]);
            }
            else{
                continue;
            }
        }
        return q.top();
    }
};

// using min heap see the logic in copy