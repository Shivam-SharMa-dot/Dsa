#include <iostream>
#include <queue>
using namespace std;
class MyCircularQueue
{
public:
    // implement using singly linked list

    // structure of linked list

    struct ListNode
    {
        int val;

        ListNode *next;

        ListNode(int x)
        {
            val = x;

            next = NULL;
        }
    };

    // front for deleting

    ListNode *front = NULL;

    // rear for inserting

    ListNode *rear = NULL;

    int max_size;

    int curr_size = 0;

    MyCircularQueue(int k)
    {

        max_size = k;
    }

    bool enQueue(int value)
    {

        // if queue is not full

        if (curr_size < max_size)
        {
            ListNode *new_node = new ListNode(value);

            // if list is empty

            if (front == NULL)
            {
                front = new_node;

                rear = new_node;
            }

            // if list is not empty

            else
            {
                rear->next = new_node;

                rear = new_node;
            }

            curr_size++;

            return true;
        }

        return false;
    }

    bool deQueue()
    {

        // if list is not empty

        if (curr_size > 0)
        {
            ListNode *temp = front;

            // move front pointer to next node

            front = front->next;

            // delete the front node

            temp->next = NULL;

            delete temp;

            curr_size--;

            return true;
        }

        return false;
    }

    int Front()
    {

        if (curr_size > 0)
            return front->val;

        return -1;
    }

    int Rear()
    {

        if (curr_size > 0)
            return rear->val;

        return -1;
    }

    bool isEmpty()
    {

        return curr_size == 0;
    }

    bool isFull()
    {

        return curr_size == max_size;
    }
};

int main()
{

    return 0;
}