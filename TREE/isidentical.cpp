/* struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        // base cases
        if( r1== NULL && r2== NULL){
            return true;
        }
        if( r1== NULL && r2 != NULL){
            return false;
        }
        if( r1 != NULL && r2== NULL){
            return false;
        }
   bool left=isIdentical(r1->left ,r2->left);
   bool right=isIdentical(r1->right ,r2->right);

   bool value= r1->data == r2->data;
   if(left && right && value){
       return true;
   }
   else{
       return false;
   }

    }
}; */
#include<iostream>
using namespace std;

class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
        {
            // v.push_back(0);
            return;
        }
        v.push_back(root->val);
        if (root->left)
            preorder(root->left, v);
        if (!root->left)
            v.push_back(0);
        if (root->right)
            preorder(root->right, v);
        if (!root->right)
            v.push_back(0);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> res1;
        vector<int> res2;
        preorder(p, res1);
        preorder(q, res2);
        if (res1 != res2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main(){
    
}