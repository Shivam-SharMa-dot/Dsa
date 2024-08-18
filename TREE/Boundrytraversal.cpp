#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
class Solution
{
public:
    void leftboundry(Node *root, vector<int> &sol)
    {

        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        sol.push_back(root->data);
        if (root->left)
        {
            leftboundry(root->left, sol);
        }
        else
        {
            leftboundry(root->right, sol);
        }
    }
    void leafboundrytraverse(Node *root, vector<int> &sol)
    {
        // USING inorder traversal
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            sol.push_back(root->data);
            return;
        }
        leafboundrytraverse(root->left, sol);
        leafboundrytraverse(root->right, sol);
    }
    void rightboundry(Node *root, vector<int> &sol)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->right)
            rightboundry(root->right, sol);
        else
            rightboundry(root->left, sol);

        sol.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        // leftboundry
        leftboundry(root->left, ans);

        // pushing leaf nodes
        // leeft sub tree
        leafboundrytraverse(root->left, ans);
        // right subtree
        leafboundrytraverse(root->right, ans);
        // traverse right part
        rightboundry(root->right, ans);

        return ans;
    }
};
int main()
{

    Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    Solution obj;
    vector<int> ans = obj.boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}