// there is  another method using recursion

#include <iostream>
#include <stack>
using namespace std;

// Function to sort a stack in ascending order
void sortStack(stack<int> &inputStack)
{
    stack<int> tempStack;

    while (!inputStack.empty())
    {
        // Pop the top element from the original stack
        int temp = inputStack.top();
        inputStack.pop();

        // Move elements from the temporary stack to the original stack
        // until the correct position for the current element is found
        while (!tempStack.empty() && tempStack.top() < temp)
        {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        // Place the current element in the correct position in the temporary stack
        tempStack.push(temp);
    }

    // Transfer elements back to the original stack
    while (!tempStack.empty())
    {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}

// Helper function to print the elements of the stack
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> myStack;
    myStack.push(4);
    myStack.push(2);
    myStack.push(6);
    myStack.push(3);
    myStack.push(8);

    cout << "Original stack: ";
    printStack(myStack);

    sortStack(myStack);

    cout << "Sorted stack: ";
    printStack(myStack);

    return 0;
}
