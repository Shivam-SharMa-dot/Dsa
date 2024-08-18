#include <iostream>
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
TreeNode *maxValue(TreeNode *root)
{
    TreeNode *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
TreeNode *minValue(TreeNode *root)
{
    TreeNode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
