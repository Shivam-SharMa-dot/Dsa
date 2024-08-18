#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    Node *clonehead = NULL;
    Node *clonetail = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        insertattail(clonehead, clonetail, temp->val);
        temp = temp->next;
    }

    // step2 create map and map

    unordered_map<Node *, Node *> mp;

    Node *originalnode = head;
    Node *clonenode = clonehead;

    while (originalnode != NULL && clonenode != NULL)
    {
        mp[originalnode] = clonenode;
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }
    //  step3 set random pointers
    originalnode = head;
    clonenode = clonehead;

    while (originalnode != NULL)
    {
        clonenode->random = mp[originalnode->random];
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }
    return clonehead;
}

int main()
{

    return 0;
}