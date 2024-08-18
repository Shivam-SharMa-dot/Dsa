#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // creation of node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *nodepointingtohead = head;
    while (nodepointingtohead != NULL)
    {
        cout << nodepointingtohead->data << " ";
        nodepointingtohead = nodepointingtohead->next;
    }
    cout << endl;
}
int main()
{
    // Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl; // next should be NULL
    Node *node1 = new Node(20);
    print(node1);
    Node *head = node1;
    insertathead(head, 10);
    print(head);
    insertathead(head, 5);
    print(head);
    insertathead(head, 2);
    print(head);

    return 0;
}