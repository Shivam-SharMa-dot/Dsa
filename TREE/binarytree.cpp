#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// taking  run time input in an tree
node *buildTree(node *root)
{
    int data;
    cout << "enter the data " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data for inserting in left side of" << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for inserting in right side of" << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    // push null to enter or come into new line
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop(); // remove element from front
        if (temp == NULL)
        { // purana level complete traverse ho chuka hai next line me jao
            cout << endl;
            if (!q.empty()) // queue still have some child ndoes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void inordertraversal(node *root) //  L.N.R      left.print.right
{
    if (root == NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout << root->data << " ";  
    inordertraversal(root->right);
}
void postorder(node *root) // L.R.N    left.right.print
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorder(node *root) // N.L.R    print.left.right
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// creating a tree from level order traversal
void buildFromLevelOrder(node *&root)
{
    queue <node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
    levelordertraversal(root);
    /*
     root = buildTree(root);
     cout << "printing the level ordr traversal " << endl;
     levelordertraversal(root);
     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     cout << "printiing the inorder traversal " << endl;
     inordertraversal(root);
     cout << "printing the post order traversal " << endl;
     postorder(root);
     cout << "printing the pre order traversal " << endl;
     preorder(root);
     */
    return 0;
}