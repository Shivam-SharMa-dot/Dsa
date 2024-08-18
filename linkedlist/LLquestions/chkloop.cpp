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
        temp = temp->next;
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
bool detectloop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node* , int> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true; // mark visited element to true but before
        temp = temp->next;    // that print/check that any one has marked earlier so if statment is referncing that
    }
    return false;
}
Node *floydalgodetectloop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "loop is present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *getstartingnode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydalgodetectloop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeloop(Node *head)
{
    if(head==NULL)
    return;
    Node *startofloop=getstartingnode(head);
    Node *temp=startofloop;
    while(temp->next !=startofloop ){
        temp =temp->next;
    } 
    temp->next=NULL;
}
int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    // insertatback(tail, 3);

    // insertatback(tail, 4);

    inseratpositiion(tail, head, 2, 15);
    inseratpositiion(tail, head, 3, 16);
    inseratpositiion(tail, head, 4, 17);
    inseratpositiion(tail, head, 5, 18);
    print(head);
    tail->next = head->next->next;
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    /* if (detectloop(head))
     {
         cout << "loop is present" << endl;
     }
     else
     {
         cout << "loop is not present " << endl;
     }
     */
    if (floydalgodetectloop(head) != NULL)
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "loop is not present " << endl;
    }
    Node *loop = getstartingnode(head);
    cout << " the loop is starting at " << loop->data << endl;
    removeloop(head);
    print(head);
   
     return 0;
}
// in this the space complexity is O(n) and T.c= O(n)
// so reduce it we use floyd algorithm
