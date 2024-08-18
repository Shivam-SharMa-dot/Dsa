// O(n^2) solution which will give tle on submission
/* #include <bits/stdc++.h>
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
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        Node *prev = curr;
        Node *runner = curr->next;
        while (runner != NULL)
        {
            if (runner->data == curr->data)
            {
                Node *duplicate = runner;
                prev->next = runner->next;
                runner = runner->next;
                delete duplicate;
            }
            else
            {
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{

    return 0;
} */
// O(n) time and O (n) space complexity using concept of hashing
#include <bits/stdc++.h>
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
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}