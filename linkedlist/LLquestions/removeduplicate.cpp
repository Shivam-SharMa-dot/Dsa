#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while (curr->val != val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        removeElements(prev, val);
        return prev;
    }
};
