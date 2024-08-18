/* In a linked list implementation of a stack, there is no direct concept of an "overflow" condition
 in the same way it exists in array - based stack implementations.In an array - based stack,
 an overflow occurs when the stack is full, and you try to push an element onto it.
 This can happen if the array that holds the stack elements is of a fixed size and it gets filled up
 In a linked list implementation,the stack can, in theory, grow indefinitely(limited only by
  the available memory).Each new element pushed onto the stack is dynamically allocated on the heap,
   and the stack can continue to grow as long as there is available memory
 However, it's essential to consider that there could still be practical limitations
 and potential issues even in a linked list implementation:
 1. Memory Constraints : Although a linked list implementation can grow dynamically,
                         the available memory on the system is finite.If the system runs out of memory,
                         further stack operations,
                         including push,
                         will fail
  2. System Constraints : Some systems might have restrictions on memory allocationor impose certain limits,
                             so while the linked list itself can grow, the system could have its limitations
 3. Stack Overflow(Recursion) : In some cases,a linked list implementation
                                of a stack might be used to manage function calls(recursion)
                               in certain programming languages.If the recursion depth becomes too large,
                                it could lead to a stack overflow error, even in a linked list implementation
  4. Implementation Specifics : The linked list implementation itself might be designed with limitations,
                                like using a fixed - size pool of nodes, which could lead to an overflow -
                                 like situation when the pool is exhausted.
  So,while there isn 't a direct "overflow" condition as seen in array-based stacks,
   linked list implementations can still face limitations and issues depending on the factors
    mentioned above. It' s crucial to be aware of these constraints when
     using a linked list as a stack to avoid potential problems. */
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *link;
  Node(int data)
  {
    this->data = data;
    this->link = NULL;
  }
};
class Stack
{
public:
  Node *top;
  Stack()
  {
    top = NULL;
  }
  void push(int x)
  {
    Node *newNode = new Node(x);

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow

    //  The condition if (!newNode) checks if newNode is a null pointer,
    //  which would indicate that the memory allocation was not successful
    //(i.e., the heap is full, and there is no more memory available to allocate for the new node)
    // In such a situation, the function prints "Stack Overflow" and exits the program with an error code (exit(1)).
    if (!newNode)
    {
      cout << "\nStack Overflow";
      exit(1);
    }
    newNode->data = x;
    // keep newnode linke to top
    newNode->link = top;
    top = newNode;
  }
  bool isempty()
  {
    return top == NULL;
  }
  int peek()
  {
    if (!isempty())
    {
      return top->data;
    }
    else
    {
      exit(1);
    }
  }
  void pop()
  {

    if (top == NULL)
    {
      cout << "stack underflow " << endl;
      exit(1);
    }
    else
    {
      Node *temp = top;
      top = top->link;

      delete temp;
    }
  }
  void display()
  {
    Node *temp = top;
    if (temp == NULL)
    {
      cout << "stack is empty " << endl;
    }
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->link;
    }
  }
};

int main()
{
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  st.display();

  st.pop();
  cout << st.peek() << endl;

  // if (st.isempty())
  // {
  //   cout << "is empty " << endl;
  // }
  // else
  // {
  //   cout << "not empty" << endl;
  // }


   st.display();
  return 0;
}
