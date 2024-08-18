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
void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertatposition(Node *&tail, Node *&head, int position, int d)
{
    // inserting at position 1 case
    if (position == 1)
    {
        insertathead(head, d);
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
        insertattail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
    // cout << "the currrent length of link list is " << getlength(head)<<endl;
    // what if have to take input from an array
    vector<int> arr={4,2,3,5};

    insertathead(head, 12);
    print(head);
    insertathead(head, 13);
    print(head);
    insertathead(head, 14);
    print(head);
    Node *tail = node1;
    insertattail(tail, 15);
    print(head);
    insertatposition(tail, head, 6, 100);
    print(head);
    return 0;
}

// if starting of linked list is null null then it can be for singly linked list also
// #include <bits/stdc++.h>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;
//     Node(int d)
//     {
//         this->data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };
// // traverse in link list
// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void insertathead(Node *&tail, Node *&head, int d)
// {
//     //  handling part in which starting is null
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     // for rest of part
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }
// void insertattail(Node *&head, Node *&tail, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         temp->prev = tail;
//         tail = temp;
//     }
// }
// void insertatposition(Node *&tail, Node *&head, int position, int d)
// {
//     // inserting at position 1 case
//     if (position == 1)
//     {
//         insertathead(tail, head, d);
//         return;
//     }
//     Node *temp = head;
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }
//     // inserting at Last Position
//     if (temp->next == NULL)
//     {
//         insertattail(head, tail, d);
//         return;
//     }
//     // creating a node for d
//     Node *nodetoinsert = new Node(d);
//     nodetoinsert->next = temp->next;
//     temp->next->prev = nodetoinsert;
//     temp->next = nodetoinsert;
//     nodetoinsert->prev = temp;
// }
// int main()
// {
//     Node *node1 = NULL;
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);
//     // cout << "the currrent length of link list is " << getlength(head)<<endl;
//     insertathead(tail, head, 12);
//     print(head);
//     insertathead(tail, head, 13);
//     print(head);
//     insertathead(tail, head, 14);
//     print(head);

//     insertattail(head, tail, 15);
//     print(head);
//     insertatposition(tail, head, 2, 100);
//     print(head);
//     insertatposition(tail, head, 1, 100);
//     print(head);
//     insertatposition(tail, head, 7, 100);
//     print(head);
//     return 0;
// }
