// this is done using recursion
#include <bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertatbottom(s, n);
    s.push(num);
}
void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertatbottom(stack, num);
}
void printstack(stack<int> s)
{
    while (!s.empty())
    {
        int n = s.top();
        cout << n << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(7);
    s.push(6);
    printstack(s);

    reverseStack(s);
    printstack(s);
    // vector<int> res;
    // while (s.size())
    // {
    //     res.push_back(s.top());
    //     s.pop();
    // }
    // for (int i = res.size() - 1; i >= 0; i--)
    // {
    //     cout << res[i] << " ";
    // }

    return 0;
}