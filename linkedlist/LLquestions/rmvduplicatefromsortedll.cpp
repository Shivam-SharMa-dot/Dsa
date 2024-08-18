/* // from an unsorted linked list
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

Node *removeDuplicates(Node *head)
{
    // Hash to store seen values
    unordered_set<int> seen;

    struct Node *curr = head;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) // it will come into this section if data is already preesent in it
        {
            prev->next = curr->next;
            delete (curr);
        }
        else // comes in else part if data is coming first time in hashing
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}
int main()
{

    return 0;
} */


/* // from a sirted linked list
Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head==NULL){
        return NULL;
    }
    // non empty
    Node*curr=head;
    while(curr != NULL){
        if( curr->next != NULL &&curr->data == curr->next->data){
            delete(curr->next);
            curr->next=curr->next->next;
        }
      else{
         curr=curr->next;
      }
    }
    return head;
} */

