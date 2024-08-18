#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }
    // storing poped num in some variable
    int num = inputStack.top();
    inputStack.pop();
    // recursive call
    solve(inputStack, count + 1, size);
    // again pusing back popped numbers
    inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}