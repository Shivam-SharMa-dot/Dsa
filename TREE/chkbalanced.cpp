// this is best solution of O(n) time complexity and space complexity is O(H)
#include<iostream>
using namespace std;
class Solution{
    private:
    pair<bool,int> isBalancedfast(Node *root){
        if(root==NULL){
            pair<bool,int >p = make_pair(true,0);
            return p;
        }
        pair<int ,int> left=isBalancedfast(root->left);
        pair<int ,int> right=isBalancedfast(root->right);
        
        bool leftans=left.first;
        bool rightans=right.first;
    
       bool diff=abs(left.second-right.second)<=1;
       pair<bool,int> ans;
       ans.second=max(left.second,right.second)+1;
       if( leftans && rightans && diff){
              ans.first=true;
       }
       else{
           ans.first=false;
       }
       return ans;
    }
    public:
    bool isBalanced(Node *root)
    {
       return isBalancedfast(root).first;
    }
};
int main(){


}

// solution of time complexity O(n square)
// here we are using height function and calling for every node so time complexity isnsquare
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    private:
   int height(struct Node* node){
        // code here 
      if(node== NULL){
          return 0;
      }
      int left=height(node->left);
      int right=height(node->right);
      return max(left,right)+1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL ){
            return 1;
        }
        
        bool left=isBalanced(root->left);
         
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){

    return 0;
}