#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free with data " << value << endl;
    }
};

void insertAthead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertatback(Node *&tail, int d)
{
    Node *tmpnew = new Node(d);
    tail->next = tmpnew;
    tail = tail->next;
}

void inseratpositiion(Node *&tail, Node *&head, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last condition
    if (temp->next == NULL)
    {
        insertatback(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}
void deletiionOfnode(int position, Node *&head)
{
    // deletion of starting node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free code
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting last node or middle node because both have same logic

        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertatback(tail, 3);
    print(head);
    insertatback(tail, 4);
    print(head);
    // we have link list of three node adding element at last
    inseratpositiion(tail, head, 4, 15); // inserted at n-1 positiion
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    deletiionOfnode(1, head);
    print(head);
    return 0;
}