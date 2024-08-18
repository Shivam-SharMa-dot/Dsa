#include<bits/stdc++.h>
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
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node*curr=head;
        Node*pre=NULL;
        while(curr!=NULL)
        {
            Node*nextnode=curr->next; // keep track of next so that we cant loose track
            curr->next=curr->prev;   
            curr->prev=nextnode;   
            pre=curr;
            curr=nextnode;
        }
        
        return pre;
        
    }
};