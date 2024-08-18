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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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
void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty check again" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "list is empty check again" << endl;
    }
    // assuming element exists which you want to delete
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    // here we are handling if you are deleting and tail node occurs so point it to another
    if (tail == curr)
    {
        tail = prev;
    }
    // here if only one node is present and want to delete case handled
    if (curr == prev)
    {
        tail = NULL;
    }

    // from here if node >= 2
    prev->next = curr->next; // here curr is node which to be deleted
    curr->next = NULL;
    delete curr;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    /*  insertNode(tail, 3, 5);
     print(tail);
     insertNode(tail, 5, 7);
     print(tail);
     insertNode(tail, 7, 9);
     print(tail);
     insertNode(tail, 5, 6);
     print(tail);
     // first node deleting
     deleteNode(tail, 3);
     print(tail); */

    // imagnie you have only one node and want to delete this should have to be handled
    deleteNode(tail, 3);
    print(tail);

    return 0;
}