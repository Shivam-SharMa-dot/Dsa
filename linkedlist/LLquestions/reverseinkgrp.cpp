#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int cnt = 0;
    Node *cursor = head;
    for (int i = 0; i < k; i++)
    {
        if (cursor == nullptr)
            return head;
        cursor = cursor->next;
    }   
    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    return prev;
}
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;

    /* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "the given list is " << endl;
    printList(head);
    int k;
    cout << "enter the lenght in which you want to reverse " << endl;
    cin >> k;
    head = kReverse(head, k);
    printList(head);

    return 0;
}
