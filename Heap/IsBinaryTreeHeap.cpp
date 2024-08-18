/*#include <iostream>
#include <queue>
using namespace std;
 class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        // max heap of size 100 can be created
        // arr[100];
        size = 0;
    }
};
class Solution
{
public:
    int sizeoftree(Node *root)
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
    bool iscbt(Node *root, int i, int size)
    {
        if (root == NULL)
        {
            return true;
        }
        if (i >= size)
        {
            return false;
        }
        return (iscbt(root->left, 2 * i + 1, size) && iscbt(root->right, 2 * i + 2, size));
    }
    bool ismaxHeap(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = ismaxHeap(root->left);
            bool right = ismaxHeap(root->right);
            return (right && left && root->data > root->left->data && root->data > root->right->data);
        }
    }
    bool isHeap(struct Node *tree)
    {
        // code here
        int num_of_nodes = sizeoftree(tree);
        int i = 0;
        if (iscbt(tree, i, num_of_nodes) && ismaxHeap(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}; */