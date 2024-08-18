// considering 2nd case where starting is null
// if starting of linked list will be null then

// we have two type of insertion probelm if head is not equal to null and another is if head equal to null
// both are handled differently or in 2nd type we can handle both so better 
// this is 2nd type implementation


#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for data->" << val << endl;
    }
};
// traverse in link list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertathead(Node *&tail, Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertattail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertatposition(Node *&tail, Node *&head, int position, int d)
{
    // inserting at position 1 case
    if (position == 1)
    {
        insertathead(tail, head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }
    // creating a node for d
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
void deletion(int position, Node *&head)
{
    // deletion of starting node
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting last node or middle node because both have same condition
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = NULL;
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout << "the currrent length of link list is " << getlength(head)<<endl;
    insertathead(tail, head, 12);
    print(head);
    insertathead(tail, head, 13);
    print(head);
    insertathead(tail, head, 14);
    print(head);

    insertattail(head, tail, 15);
    print(head);
    insertatposition(tail, head, 2, 100);
    print(head);
    insertatposition(tail, head, 1, 100);
    print(head);
    insertatposition(tail, head, 7, 100);
    print(head);
    deletion(1,head);// deleting first node
    print(head);
    deletion(6,head);// deleting last node
    print(head);
    return 0;
}
