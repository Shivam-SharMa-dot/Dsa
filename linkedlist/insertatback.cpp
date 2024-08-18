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
};
void insertatback(Node *&tail, int d)
{
    Node *tmpnew = new Node(d);
    tail->next = tmpnew;
    tail = tail->next;
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
    insertatback(tail, 12);
    print(head);
    insertatback(tail, 13);
    print(head);


    return 0;
}