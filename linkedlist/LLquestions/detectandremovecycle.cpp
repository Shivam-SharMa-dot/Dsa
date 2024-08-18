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
void push(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
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
}
bool detectcycle(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        // checking if earlier it was vivited and marked true if it is return true
        if (visited[temp] == true)
        {
            cout << "present on the data " << temp->data<<endl;
            return true;
        }
        // else mark it true and move to next
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node *head1 = new Node(1);
    push(head1, 2);
    push(head1, 3);
    push(head1, 4);
    push(head1, 5);
    print(head1);
    // we have to add cycle like this
    head1->next->next= head1;
    
    if (detectcycle(head1))
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    return 0;
}