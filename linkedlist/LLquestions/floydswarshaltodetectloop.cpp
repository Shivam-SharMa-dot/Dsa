// floyd's warshal algorithm gives node if ll contains loops and to return starting index of loop
// into this detect loop and get starting point of loop and remove loop all cases are handled
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
void pushattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void pushathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    head->next = temp;
    head = temp;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// it will return node which will be part of cycle it will not retrun starting node of loop
Node *floydwarsharldetectloop(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && slow != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            cout << "loop is present at element " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *getstartingindex(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydwarsharldetectloop(head);
    Node *slow = head;

    //imagine if you during moving intersection point it reaches to null 

    if (intersection == NULL)
        return NULL;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
Node *removeloop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *loopstartingpoint = getstartingindex(head);
    if (loopstartingpoint == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp->next != loopstartingpoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
int main()
{
    Node *head1 = new Node(1);
    Node *head = head1;
    Node *tail = head1;
    pushattail(tail, 2);
    pushattail(tail, 3);
    pushattail(tail, 4);
    pushattail(tail, 5);
    pushattail(tail, 6);
    pushattail(tail, 7);

    print(head);
    cout << endl;
    cout << "head is at " << head->data << endl;
    cout << "tail is at " << tail->data << endl;
    // we have to add cycle like this
    head1->next->next->next = head1->next;
    // if (floydwarsharldetectloop(head1) != NULL)
    // {
    //     cout << "cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "cycle is not present" << endl;
    // }

    Node *loop = getstartingindex(head1);
    cout << "Loop starts from element " << loop->data << endl;
    //  print(head);

    return 0;
}