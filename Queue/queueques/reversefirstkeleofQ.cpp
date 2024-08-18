// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;
// queue<int> modifyQueue(queue<int> q, int k)
// {
//     // queue<int> ans;
//     // ans=q;
//     /// algo
//     //
//     int qsize = q.size();
//     int f = k;
//     stack<int> st;
//     // push first k element into stack
//     while (f--)
//     {
//         int n = q.front();
//         st.push(q.front());
//         q.pop();
//     }
//     // then again push into queue it will be like 4 5 3 2 1
//     while (!st.empty())
//     {
//         int n = st.top();
//         q.push(n);
//         st.pop();
//     }
//     // now fetch first n-k elemnt to back like 3 2 1 4 5
//     int s = qsize - k;
//     while (s--)
//     {

//         q.push(q.front());
//         q.pop();
//     }
//     return q;
// }
// class Solution
// {
// public:
//     string FirstNonRepeating(string A)
//     {

//     }
// };
// int main()
// {
// }

