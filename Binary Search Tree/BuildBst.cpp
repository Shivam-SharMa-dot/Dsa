#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// 1st way
Node *insertintoBst(Node *&root, int d)
{
    if (root == NULL)
    {
        // if you are inserting frist element 
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertintoBst(root->right, d);
    }
    else
    {
        root->left = insertintoBst(root->left, d);
    }
    return root;
}
void Takeinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintoBst(root, data);
        cin >> data;
    }
}
//2nd way
Node *Insert(Node *root, int value)
{
    if (!root)
    {
        return new Node(value);
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

void levelordertraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    // push null to enter or come into new line
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
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

void Inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    Node *root = NULL;
    cout << " enter the data to create bst " << endl;
    Takeinput(root);
    cout << "printing level order traversal " << endl;
    levelordertraversal(root);
   // cout << "inorder traversal of BST is " << endl;
    //Inorder(root);

    return 0;
}