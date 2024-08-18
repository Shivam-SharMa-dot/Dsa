#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
void inorderteversal(BinaryTreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorderteversal(root->left, v);
    v.push_back(root->data);
    inorderteversal(root->right, v);
}
void fillpreorder(BinaryTreeNode *root, vector<int> &v, int &index)
{
    if (root == NULL)
    {
        return;
    }
    if (index == v.size())
    {
        return;
    }
    root->data = v[index++];
    fillpreorder(root->left, v, index);
    fillpreorder(root->right, v, index);
}
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    // Write your code here
    vector<int> inorder;
    inorderteversal(root, inorder);
    int i = 0;
    fillpreorder(root, inorder, i);
    return root;
}
int main()
{

    return 0;
}