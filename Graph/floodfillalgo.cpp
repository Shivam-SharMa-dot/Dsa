//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, int inicolor,
             int newColor,int delrow[], int delcol[])
    {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        // move exactly in 4 direction
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, inicolor, newColor, delrow, delcol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        int inicolor = image[sr][sc];
        // copy to flood fill it and return it
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, inicolor, newColor, delrow, delcol);
        return ans;
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends