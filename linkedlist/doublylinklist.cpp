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
// to get length
int getlength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
    // cout << "the currrent length of link list is " << getlength(head)<<endl;
    insertathead(head, 12);
    print(head);
    insertathead(head, 13);
    print(head);
    insertathead(head, 14);
    print(head);
    return 0;
}