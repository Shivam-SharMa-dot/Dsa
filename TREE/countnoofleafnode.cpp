#include <iostream>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// using recursion
// we can find using queue also logic of level order traversal
// check in copy
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;   
    }
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

// using iterative level order traversal
// int numberofleafnode(node *root)
// {
//     queue<node *> q;
//     q.push(root);
//     int cnt = 0;
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         q.pop(); // remove element from front
//         if (temp->left != NULL)
//         {
//             q.push(temp->left);
//         }
//         if (temp->right != NULL)
//         {
//             q.push(temp->right);
//         }
//         if (temp->left == NULL && temp->right == NULL)
//         {
//             cnt++;
//         }
//     }
//     return cnt;
// }