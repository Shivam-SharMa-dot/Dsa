/* #include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Node
{
public:
    int data;
    Node *next;
};
Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *skipA = headA;
    Node *skipB = headB;
    while (skipA != NULL && skipB != NULL)
    {
        if (skipA == skipB)
        {
            return skipA;
            skipA = skipA->next;
            skipB = skipB->next;
        }
        else if (skipA < skipB)
        {
            skipA = skipA->next;
        }
        else
        {
            skipB = skipB->next;
        }
    }
    return NULL;
}

int main()
{

    return 0;
} */

