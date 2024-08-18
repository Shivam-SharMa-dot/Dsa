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
// void insertatend(Node *head, int data)
// {
//     Node *nodetoinsert = new Node(data);
//     Node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = nodetoinsert;
//     nodetoinsert->prev = temp;
// }

// void addNode(Node *head, int pos, int data)
// {
//     // Your code here
//     Node *temphead = head;

//     Node *nodetoinsert = new Node(data);

//     if (head == NULL && pos == 0)
//     {
//         head = nodetoinsert;
//         return;
//     }

//     int cnt = 0;
//     while (cnt < pos && temphead != NULL)
//     {
//         cnt++;
//         temphead = temphead->next;
//     }

//     if (temphead == NULL || temphead->next == NULL)
//     {
//         insertatend(head, data);
//         return;
//     }
//     nodetoinsert->next = temphead->next;
//     if (temphead->next != NULL)
//     {
//         temphead->next->prev = nodetoinsert;
//     }
//     temphead->next = nodetoinsert;
//     nodetoinsert->prev = temphead;
// }

Node *converarrtoDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}
void printans(Node *&head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head=head->next;
    }
}

int main()
{

    vector<int> arr = {2, 4, 7, 8, 9};
    Node *ans = converarrtoDLL(arr);
    printans(ans);

    return 0;
}