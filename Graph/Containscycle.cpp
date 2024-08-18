// using DFS can be done using Bfs also

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacent : adj[node])
        {
            if (!vis[adjacent])
            {
                if (dfs(adjacent, node, vis, adj) == true)
                {
                    return true;
                }
            }
            else if (adjacent != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here'
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(0);
    adj[0].push_back(4);

    bool hasCycle = sol.isCycle(V, adj);
    cout << "Graph has cycle: " << (hasCycle ? "Yes" : "No") << endl;

    return 0;
}