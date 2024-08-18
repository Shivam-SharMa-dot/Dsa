#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd,
                          vector<int> &postorder, int postStart, int postEnd,
                          unordered_map<int, int> &inorderIndexMap)
{
    if (inStart > inEnd || postStart > postEnd)
        return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode *root = new TreeNode(rootVal);

    int inorderRootIndex = inorderIndexMap[rootVal];
    int numsLeft = inorderRootIndex - inStart;

    root->left = buildTreeHelper(inorder, inStart, inorderRootIndex - 1,
                                 postorder, postStart, postStart + numsLeft - 1, inorderIndexMap);
    root->right = buildTreeHelper(inorder, inorderRootIndex + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1, inorderIndexMap);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < inorder.size(); ++i)
    {
        inorderIndexMap[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderIndexMap);
}

int diameterOfBinaryTree(TreeNode *root, int &diameter)
{
    if (!root)
        return 0;

    int leftHeight = diameterOfBinaryTree(root->left, diameter);
    int rightHeight = diameterOfBinaryTree(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    diameterOfBinaryTree(root, diameter);
    return diameter;
}

int main()
{
    vector<int> inorder = {10, 3, 7, 1, 8, 4, 5, 9, 2, 6};
    vector<int> postorder = {10, 7, 1, 3, 9, 5, 4, 8, 6, 2};

    TreeNode *root = buildTree(inorder, postorder);
    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the tree: " << diameter << endl;

    return 0;
}