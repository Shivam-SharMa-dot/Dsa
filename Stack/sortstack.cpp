#include <iostream>
#include <stack>
using namespace std;
#include <bits/stdc++.h>
void sortorderinsert(stack<int> &s, int num)
{
    // base case
    if (s.empty() || ( !s.empty()  && s.top() < num))
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();
    // recursive call
    sortorderinsert(s, num);
    s.push(n);
}
// main function
void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return ;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortorderinsert(stack, num); // here we are passing num not n
}

int main()
{

    return 0;
}