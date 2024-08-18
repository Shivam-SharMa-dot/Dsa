//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool dfs(int node, int vis[], int pathvis[], vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        // marking adjacent node
        for (auto it : adj[node])
        {
            if (!vis[it])
            {

                if (dfs(it, vis, pathvis, adj) == true)
                {
                    return true;
                }
            }

            // if path has been visited and have same path

            // either this or pathvis[it]==1 && vis[it]==1
            else if (pathvis[it] == 1)
            {
                return true;
            }
        }

        // path visited make 0 during returning only path visited
        pathvis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        int vis[V] = {0};
        int pathvis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (dfs(i, vis, pathvis, adj) == true)
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends