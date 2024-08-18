#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int val)
    // {
    //     this->val = val;
    //
    // }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
    void createmapping(vector<int> &inorder, map<int, int> &nodetoindex, int size)
    {
        for (int i = 0; i < size; i++)
        {
            nodetoindex[inorder[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postorderindex, int inorderstart,
                    int inorderend, int size, map<int, int> &nodetoindex)
    {
        if (postorderindex < 0 || (inorderstart > inorderend))
        {
            return NULL;
        }
        int element = postorder[postorderindex--];
        TreeNode *root = new TreeNode(element);
        int position = nodetoindex[element];
        // recursive call
        root->right = solve(inorder, postorder, postorderindex, position + 1, inorderend, size, nodetoindex);
        root->left = solve(inorder, postorder, postorderindex, inorderstart, position - 1, size, nodetoindex);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        map<int, int> nodetoindex;
        // create node to index mapping once rather tah traversing again and again
        createmapping(inorder, nodetoindex, n);

        int postorderindex = n - 1;
        TreeNode *ans = solve(inorder, postorder, postorderindex, 0, n - 1, n, nodetoindex);
        return ans;
    }
};