//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool checkbipartite(int start, int col, int color[], vector<int> adj[])
    {
        color[start] = col;
        for (auto it : adj[start])
        {
            if (color[it] == -1)
            {
                if (checkbipartite(it, !col, color, adj) == false)
                {
                    return false;
                }
            }
            else if (color[it] == start)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int color[V];

        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        int col = 0;
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (checkbipartite(i, col, color, adj) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends