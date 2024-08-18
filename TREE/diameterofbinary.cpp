//  O(nsquare ) solution by using two different function recursioon
// class Solution {
//  public:
//     int height(TreeNode* root)
// {
//     if(root==NULL){
//             return 0;
//         }
//         int left=height(root->left);
//         int right=height(root->right);

//         return max(left,right)+1;
// }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int op1=diameterOfBinaryTree(root->left);
//         int op2=diameterOfBinaryTree(root->right);
//         int op3=height(root->left)+height(root->right);
//         int ans =max(op1,max(op2,op3));
//         return ans;
//     }
// };



// derived from reursive approch
// O(n) solution and important question
// into this approch we are making pair of daimeter and height
// first is diameter and second is height

// think from recursive solution 

// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int x)
//     {
//         data = x;
//         left = right = NULL;
//     }
// };
// class Solution
// {
// private:
//     pair<int, int> diameterfast(Node *root)
//     {
//         // base case
//         if (root == NULL)
//         {
//             pair<int, int> p = make_pair(0, 0);
//             return p;
//         }
//         // calling for left part
//         pair<int, int> left = diameterfast(root->left);
//         // calling for right part
//         pair<int, int> right = diameterfast(root->right);

//         int op1 = left.first;
//         int op2 = right.first;
//         int op3 = left.second + right.second + 1; // needs height
//         pair<int, int> ans;

//         ans.first = max(op1, max(op2, op3));
//         ans.second = max(left.second, right.second) + 1;
//         return ans;
//     }

// public:
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node *root)
//     {
//         return diameterfast(root).first;
//     }
// };

// another method 
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left, *right;
};

int height(Node* root, int& ans)
{
	if (root == NULL)
		return 0;

	int left_height = height(root->left, ans);

	int right_height = height(root->right, ans);

	// update the answer, because diameter of a
	// tree is nothing but maximum value of
	// (left_height + right_height + 1) for each node
	ans = max(ans, 1 + left_height + right_height);

	return 1 + max(left_height, right_height);
}

/* Computes the diameter of binary tree with given root. */
int diameter(Node* root)
{
	if (root == NULL)
		return 0;
	int ans = INT_MIN; // This will store the final answer
	height(root, ans);
	return ans;
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;

	return (node);
}

// Driver code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Diameter is %d\n", diameter(root));

	return 0;
}


