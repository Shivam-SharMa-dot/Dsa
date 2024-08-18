#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
        int size;
        int top;
        int *arr;

        Stack(int size)
        {
                this->size = size;
                arr = new int[size];
                top = -1;
        }
        void push(int x)
        {
                if (top < size - 1)
                {
                        top++;
                        arr[top] = x;
                }
                else
                {
                        cout << "stack overflow " << endl;
                }
        }
        void pop()
        {
                if (top < 0)
                {
                        cout << "stack  underflow " << endl;
                }
                else
                {
                        top--;
                }
        }
        int peek()
        {
                if (top < 0)
                {
                        cout << "array is empty" << endl;
                        return -1;
                }
                else
                {
                        return arr[top];
                }
        }
        bool isempty()
        {
                if (top == -1)
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
        Stack st(5);
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);

        st.pop();
        st.pop();
        st.pop();
        st.pop();
        st.pop();
        st.pop(); // this will give underflow
        cout << st.peek();
        if (st.isempty())
        {
                cout << "isempty";
        }
        else
        {
                cout << "not empty";
        }
        return 0;
}