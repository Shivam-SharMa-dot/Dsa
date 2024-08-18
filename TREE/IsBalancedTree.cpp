#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
public:
    int sizeoftree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int l = sizeoftree(root->left);
            int r = sizeoftree(root->right);
            return 1 + l + r;
        }
    }
    bool iscbt(TreeNode *root, int i, int size)
    {
        if (root == NULL)
        {
            return true;
        }
        if (i >= size)
        {
            return false;
        }
       return(iscbt(root->left, 2 * i+1, size) && iscbt(root->right, 2 * i + 2, size));
    }
    bool isCompleteTree(TreeNode *root)
    {
        int i = 0;
        int num_of_nodes = sizeoftree(root);
        if (iscbt(root, i, num_of_nodes))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};