/* #include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *node1 = (struct node *)new node();
    node1->data = val;
    node1->left = NULL;
    node1->right = NULL;
    return (node1);
}
int sumoftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumoftree(root->left) + sumoftree(root->right);
}
bool isSumTree(node *root)
{
    if (root == NULL ||
        (root->left == NULL &&
         root->right == NULL))
        return true;
    int ls, rs;
    ls = sumoftree(root->left);
    rs = sumoftree(root->right);
    bool left = isSumTree(root->left);
    bool right = isSumTree(root->right);

    if (root->data == ls + rs && left && right)
    {
        return true;
    }
    return false;
}
int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    return 0;
} */
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
// using pair in O (n) timecomplexity and O(H) space complexity

class Solution
{
private:
    pair<bool, int> issumtreefast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        pair<bool, int> leftans = issumtreefast(root->left);
        pair<bool, int> rightans = issumtreefast(root->right);

        bool left = leftans.first; // checking if lefttree is sum tree or not
        bool right = rightans.first;

        bool cond = root->data == leftans.second + rightans.second;
        pair<bool, int> ans;

        if (left && right && cond)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return issumtreefast(root).first;
    }
};