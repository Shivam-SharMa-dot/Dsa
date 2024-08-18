#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> Inorder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        Inorder(root->left);
        ans.push_back(root->val);
        Inorder(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> res = Inorder(root);
        if (is_sorted(begin(res), end(res)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

