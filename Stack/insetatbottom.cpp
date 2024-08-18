#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int>& s,int x){
  // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    insertatbottom(myStack,x);
    return myStack;
    
}
int main()
{



    return 0;
}