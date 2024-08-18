#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:    
    // helper function
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse the neighbours in all 8 direction
            for (int deltarow = -1; deltarow <= 1; deltarow++)
            {
                for (int deltacol = -1; deltacol <= 1; deltacol++)
                {
                    int nrow = row + deltarow;
                    int ncol = col + deltacol;
                    // now check it not goes out of grid and remain inside and is island
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                // make sure not visited and land also
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return cnt;
    }
};
//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends