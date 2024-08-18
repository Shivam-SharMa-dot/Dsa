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
    TreeNode *minValue(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->val == key)
        {
            // 0 child of node to be deleted
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 1 child only in left
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // 1 child only in right
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // 2 child
            // we are finding max value from right sub tree and swaping it with node to be deleted and
            // then deleting that node from which max value has been found
            // we have option 2nd also in which we retrieve max value from left subtree from that root and then do the same as done above
            if (root->left != NULL && root->right != NULL)
            {
                int mini = minValue(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
TreeNode *insertintoBst(TreeNode *&root, int d)
{
    if (root == NULL)
    {
        // if you are inserting frist element
        root = new TreeNode(d);
        return root;
    }
    if (d > root->val)
    {
        root->right = insertintoBst(root->right, d);
    }
    else
    {
        root->left = insertintoBst(root->left, d);
    }
    return root;
}
void Takeinput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintoBst(root, data);
        cin >> data;
    }
}
void Inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}
int main()
{
    TreeNode *root = NULL;
    cout << " enter the data to create bst " << endl;
    Takeinput(root);
    cout << "printing level order traversal " << endl;
    Inorder(root);
    // 50 20 70 10 30 90 110  -1 data
    Solution obj;
    obj.deleteNode(root, 20);
    cout << "printing level order traversal after deletion " << endl;
    Inorder(root);
    return 0;
}