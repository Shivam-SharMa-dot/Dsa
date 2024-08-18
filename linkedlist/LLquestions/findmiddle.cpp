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
int getlength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    Node *findMiddle(Node * head)
    {
        // Write your code hereint len=getlength(head);
        int len =getlength(head);
        int ans = len / 2;
        int cnt = 0;
        Node *temp = head;
        while (cnt < ans)
        {
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    return 0;
}