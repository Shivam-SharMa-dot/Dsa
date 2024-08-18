#include <iostream>
#include <stack>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                if (ch == '}' && s.top() == '{' ||
                    ch == ']' && s.top() == '[' ||
                    ch == ')' && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    string s = "({}{)}";
    if (isValidParenthesis(s))
    {
        cout << "paranthesis  is valid " << endl;
    }
    else
    {
        cout << "Not valid paranthesis " << endl;
    }
    return 0;
}

// another approch without using any stack

// bool isValidParenthesis(string s)
// {
//     int cnt = -1;
//     for (int i = 0; i < s.size(); i++)
//     {
//       //  char ch = expression[i];
//         if (s[i]== '(' || s[i] == '{' || s[i] == '[')
//         {
//             cnt++;
//         }
//         else if(s[i]== ')' || s[i] == '}' || s[i] == ']'){
//             if(cnt<0){
//                   return false;
//             }
//           cnt--;
//         }
//     }
//     return cnt==-1;
// }