
/*
// not containing any inner loop
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constrcutor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}


/* bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}


//map approch to check circular or not
bool isCircular(Node *head)
{

    // Base Cases
    if (head == NULL) // Empty list
        return true;
    if (head->next == NULL)
        return false;
    if (head->next == head)
        return true;

    Node *temp = head->next;
    map<Node *, int> mp;
    while (temp != NULL)
    {
        if (mp[temp] != 1)
            mp[temp] = 1;
        else if (mp[temp] == 1 && temp == head)
            return true;
        // else
        // return false;
        temp = temp->next;
    }
    return false;
}
void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
int main()
{

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    if (isCircular(tail))
    {
        cout << " Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}*/

// containing inner loop also
/* bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    if (head->next == NULL)
    {
        return false;
    }
    if (head->next == head)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == fast && slow == head)
    {
        return true;
    }
    return false;
} */