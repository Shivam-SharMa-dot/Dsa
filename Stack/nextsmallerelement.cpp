/* #include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> s;
    stack<int> st;
    st.push(arr[0]);
    for (int i = 1; i <= n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
        }
        while (!st.empty() && st.top() < arr[i])
        {
            s.push_back(st.top());
            st.pop();
        }
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
    }
    return s;
}

int main()
{
    vector<int> arr(5);
    arr = {5, 4, 3, 2, 1};
    int n = 5;
    nextSmallerElement(arr, n);
    return 0;
} */
#include <bits/stdc++.h>
class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int front;
    int rear;
    int size;
    Deque(int n)
    {
        // Write your code here.
        size = n;
        front = rear = -1;
        arr = new int[n];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    { // check full
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, //and false otherwise.
    bool pushRear(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, //otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if (front == -1)
        { // check empty or not
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element
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
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, //otherwise returns the popped element.
    int popRear()
    {
        if (front == -1)
        { // check empty or not
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        { // single element
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if ((front == 0 && rear == size - 1) || ( front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};