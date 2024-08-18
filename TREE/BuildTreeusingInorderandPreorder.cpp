#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
// class TreeNode
// {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     // TreeNode(int val)
//     // {
//     //     this->val = val;
//     //
//     // }
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// class Solution
// {
//     int findposition(vector<int> &inorder, int element, int size)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (inorder[i] == element)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
//     TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preorderindex, int inorderstart, int inorderend, int size)
//     {
//         if (preorderindex >= size || (inorderstart > inorderend))
//         {
//             return NULL;
//         }
//         int element = preorder[preorderindex++];
//         TreeNode *root = new TreeNode(element);

//         int position = findposition(inorder, element, size);
//         // recursive call
//         root->left = solve(preorder, inorder, preorderindex, inorderstart, position - 1, size);
//         root->right = solve(preorder, inorder, preorderindex, position + 1, inorderend, size);
//         return root;
//     }
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         int n = inorder.size();
//         int preorderindex = 0;
//         TreeNode *ans = solve(preorder, inorder, preorderindex, 0, n - 1, n);
//         return ans;
//     }
// };

// optimization of above code using mapping
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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preorderindex, int inorderstart,
                    int inorderend, int size, map<int, int> &nodetoindex)
    {
        if (preorderindex >= size || (inorderstart > inorderend))
        {
            return NULL;
        }
        int element = preorder[preorderindex++];
        TreeNode *root = new TreeNode(element);
        int position = nodetoindex[element];
        // recursive call
        root->left = solve(preorder, inorder, preorderindex, inorderstart, position - 1, size, nodetoindex);
        root->right = solve(preorder, inorder, preorderindex, position + 1, inorderend, size, nodetoindex);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        map<int, int> nodetoindex;
        // create node to index mapping once rather tah traversing again and again
        createmapping(inorder, nodetoindex, n);

        int preorderindex = 0;
        TreeNode *ans = solve(preorder, inorder, preorderindex, 0, n - 1, n, nodetoindex);
        return ans;
    }
};