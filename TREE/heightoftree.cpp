#include <iostream>
#include <queue>
using namespace std;
class Treenode
{
public:
    int data;
    Treenode *left;
    Treenode *right;
    Treenode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
Treenode *buildTree(Treenode *root)
{
    int data;
    cout << "enter the data " << endl;
    cin >> data;
    root = new Treenode(data);
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
void levelordertraversal(Treenode *root)
{
    queue<Treenode *> q;
    q.push(root);
    // push null to enter or come into new line
    q.push(NULL);
    while (!q.empty())
    {
        Treenode *temp = q.front();
        q.pop(); // remove element from front

        // seperator 
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
int heightfromlevelordertraversal(Treenode *root)
{
    int cnt = 0;
    queue<Treenode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Treenode *temp = q.front();
        q.pop();
        // seperator
        if (temp == NULL)
        {
            cnt++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return cnt;
}

int main()
{
    Treenode *root = NULL;
    root = buildTree(root);
    levelordertraversal(root);
    cout << "height of tree " << heightfromlevelordertraversal(root);
    return 0;
}