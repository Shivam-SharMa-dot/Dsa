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
        temp=temp->next;
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
    //  cout<<node1->data<<endl;
    //  cout<<node1->next<<endl;

    // insertion at head code
    // making head to node1
    // Node *head = node1;
    // insertAthead(head, 12);
    // print(head);
    // insertAthead(head, 13);
    // print(head);

    //  to tail insertion
    // making node1 as tail

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

    return 0;
}