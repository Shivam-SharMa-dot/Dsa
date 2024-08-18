#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelordertraversal(Node *root)
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

Node *insertIntoBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBst(root->right, d);
    }
    else
    {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == key)
    {
        // 0 child of node to be deleted
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child only in left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 1 child only in right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        root->left = deleteNode(root->left, key);
    }
    return root;
}

int main()
{

    Node *root = NULL;
    cout << "Enter the data to create BSt" << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelordertraversal(root);

    int key;
    cout << "enter the data to be deleted" << endl;
    cin >> key;
   Node*del=deleteNode(root, key);

    cout << "printing the tree" << endl;
    levelordertraversal(del);
    return 0;
}