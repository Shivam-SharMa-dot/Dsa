#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class Solution
{
    void solve(Node *root, vector<int> &ans, int targetSum, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        // left
        solve(root->left, ans, targetSum, count);

        solve(root->right, ans, targetSum, count);
        int size=ans.size();
        int sum=0;
        for (int i = size-1; i >= 0; i--)
        {
            sum+=ans[i];
            if(sum==targetSum){
                count++;
            }
        }
        ans.pop_back();
    }

    int pathSum(Node *root, int targetSum)
    {
        int count = 0;
        vector<int> path;

        solve(root, path, targetSum, count);
        return count;
    }
};