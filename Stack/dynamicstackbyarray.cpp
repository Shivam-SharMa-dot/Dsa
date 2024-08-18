#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int size;
    int *arr;
    int top;
    Stack()
    {
        // IF inserted more than 4 element then it will create a new array
        size = 4;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        //if arr stacks full it will automatically doubles and copied in new arr 
        if (top == size-1)
        {
            int *newarr = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }
            size *= 2;
            delete[] arr;
            arr = newarr;
            // cout << "stack overflow" << endl;
        }
        top++;
        arr[top] = element;
        
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack undreflow " << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << " stack is empty" << endl;
            return -1;
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
    Stack st;
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(26);
    st.push(43);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(16);
    //  st.push(11);

    cout << st.peek() << endl;
    return 0;
}