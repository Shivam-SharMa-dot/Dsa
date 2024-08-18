#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int size;
    int *arr;
    int rear;
    int front;

public:
    Queue(int size)
    {
        this->size = size;
        rear = front = 0;
        arr = new int[size];
    }
    // push ele in queue
    void Queueenque(int x)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            arr[rear] = x;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (front == rear)
        {
            front = 0;   // ensure making them again to zero so that if again 
            rear = 0;    //we push sart pushing from 0 index 
            cout << " queue is empty " << endl;
            return -1;
        }
        else
        {
            int ans = arr[front];
            front++;
            return ans;
        }
    }
    // O(n) for deque operation
    // void queuedeque()
    // {
    //     if (rear == front)
    //     {
    //         cout << "Queue is empty " << endl;
    //         return;
    //     }
    //     else
    //     {
    //         for (int i = 0; i < rear - 1; i++)
    //         {
    //             arr[i] = arr[i + 1];
    //         }
    //         rear--;
    //     }
    //     return;
    // }
    void Displayqueue()
    {
        if (front == rear)
        {
            cout << "queue is already empty " << endl;
            return;
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    void Queuefront()
    {class MinStack {
public:
stack<int> st;
int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        // check if overflow or pushing first elel
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val <mini){
                long long v=2*val-mini;
                st.push(v);
                mini = val;
            }
            else{
                // normal push
                st.push(val);
            }
        }
    }
    
    void pop() {
        //c heck if underflow
        if(st.empty()){
            return;
        }
        // you will have ele in stack  
       int curr=st.top();
       st.pop();
       if(curr > mini){  //mini which will be coming from above which is recognised while pushing
        // st.pop(); 
        return;  // void type if non void type return then curr will be returned 
       }
       else{
        // int prevmin=mini;
        long long data= 2*mini - curr;
        mini = data;
        // st.pop();
        return;
       }

    }
    
    int top() {
     if(st.empty()){
        return -1;
     }   
     int curr=st.top();
     if(curr < mini){
        return mini;
     }
     else{
        return curr;
     }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
        if (front == rear)
        {
            cout << "queue is empty " << endl;
            return;
        }
        else
        {
            cout << "front element is " << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(5);
    //  q.Displayqueue();
    q.Queueenque(1);
    q.Queueenque(2);
    q.Queueenque(3);
    // q.Queueenque(4);
    // q.Queueenque(5);

   // cout << q.dequeue() << endl;

    q.Displayqueue();

    return 0;
}

// #include <iostream >
// #include <string>
// using namespace std;
// int countsteps(string s1, string s2)
// {
//     int first = 0, second = 0, cnt = 0;
//     for (int i = 0; i < s1.size(); i++)
//     {
//         if (s1[first] != s2[i])
//         {
//             while (s1[++first] != s2[i])
//                 while (i < first)
//                 {
//                     swap(s1[first], s1[first + 1]);
//                     cnt += 1;
//                 }
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     string s1 = "abcd";
//     string s2 = "cdab";
//     cout << countsteps(s1, s2);

//     return 0;
// }