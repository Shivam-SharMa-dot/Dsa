#include <iostream>
#include <queue>
using namespace std;
/* class CircualrQueue
{
    int size;
    int front;
    int rear;
    int *arr;

public:
    CircualrQueue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    void Enqueue(int data)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size-1))
        {
            cout << " circular queue is full " << endl;
        }
        else if (front == -1) // inserting first element
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    int Dequeue()
    {
        if (front == -1) // checking if queue is already empty
        {
            cout << "Queue is empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;  // making -1 so that as we not know taht ele
        if (front == rear) // if only one element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1) // to maintain cyclic nature
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
    void displayQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty " << endl;
            return;
        }
        cout << "the elements of queue are ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
}; */
class MyCircularQueue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    MyCircularQueue(int k)
    {
        this->size = k;
        front = rear = -1;
        arr = new int[size];
    }
    bool enQueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
        {
            return false;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return true;
    }

    int Front()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int Rear()
    {
        if (rear == -1)
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if (front == rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || front == (rear + 1) % (size - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    MyCircularQueue q(3);
    // q.enQueue(1);
    // q.enQueue(2);
    // q.enQueue(3);
    return 0;
}