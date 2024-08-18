#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool issafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
    {
        // means you have reached to x,y
        // base case
        if (x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return ;
        }
        visited[x][y] = 1;
        // down choice
        int newx = x + 1;
        int newy = y;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // left choice
         newx = x;
         newy = y - 1;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // right choice
         newx = x;
         newy = y + 1;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // up choice
         newx = x - 1;
         newy = y;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        // Your code goes here
        if (m[0][0] == 0)
        {
            return ans;
        }

        

        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        int srcx = 0;
        int srcy = 0;
        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}
