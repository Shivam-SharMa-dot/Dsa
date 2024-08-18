
// 1.We start scanning the histogram from left to right.
// 2.For each bar, we check if it is taller than the bar at the top of the stack.
// If it is taller, we push its index onto the stack.
//3.If the current bar is shorter than the bar at the top of the stack, 
//it means we have found the right boundary of a rectangle that includes the bar at the top of the stack.
// We pop the top of the stack and calculate the area of the rectangle using the height of the popped bar.
// The width of the rectangle is determined by the position of the previous bar in the stack (or the current 
//position if the stack is empty).
//4.We repeat step 3 until the current bar is not shorter than the bar at the top of the stack.
//Keep track of the maximum area encountered so far.
/* 
#include <iostream>
#include <vector>
#include <stack>

int largestRectangleArea(const std::vector<int> &heights)
{
    int n = heights.size();
    std::stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n;)
    {
        int h = (i == n) ? 0 : heights[i];

        if (st.empty() || h >= heights[st.top()])
        {
            st.push(i);
            i++;
        }
        else
        {
            int topIdx = st.top();
             st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = std::max(maxArea, heights[topIdx] * width);
        }
    }
    return maxArea;
}

int main()
{

    std::vector<int> heights = {5, 6, 4};
    int result = largestRectangleArea(heights);
    std::cout << "Largest Rectangular Area: " << result << std::endl; // Output: 10

    return 0;
}
 */
// another approch using the concept of next smaller element and prev smaller element
#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> nextsmallerelement(vector<int> &v, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = v[i];
        // if st.top()==-1 then it will be problem for v[-1] so hadle this case here
        while (st.top() != -1 && v[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        // we need indexes not element so push indexes
        st.push(i);
    }
    return ans;
}
vector<int> prevsmallerelement(vector<int> &v, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = v[i];
        while (st.top() != -1 && v[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{

    int n = heights.size();
    int area = INT_MIN;
    vector<int> next(n);
    next = nextsmallerelement(heights, n);
    vector<int> prev(n);
    prev = prevsmallerelement(heights, n);
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        // case handled if v=[2 2 2 2 2]
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}
int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << "the largest area in histogram is " << largestRectangleArea(v);
    return 0;
}
