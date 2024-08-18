#include <iostream>
#include <stack>
using namespace std;
void insertarbottom(stack<int> st, int m)
{
    if (st.size() == 0)
    {
        st.push(m);
    }
    else
    {
        int a = st.top();
        st.pop();
        insertarbottom(st, m);
        st.push(a);
    }
}
void reverse(stack<int> &st)
{
    if (st.size() > 0)
    {
        int m = st.top();
        st.pop();
        reverse(st);
        insertarbottom(st, m);
    }
    return;
}

int main()
{
    stack<int> st, st2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    st2 = st;

    cout << "Original Stack" << endl;
    // printing the stack after reversal
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    // function to reverse
    // the stack
    reverse(st);
    cout << "Reversed Stack" << endl;
    // printing the stack after reversal
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}