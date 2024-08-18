// into this solution graph commponent case is not being handled
// and here edges are not given direct adjlist is being taken as input
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Function to return a list containing the DFS traversal of the graph.
private:
    void dfsUtil(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfsUtil(it, adj, visited, ans);
            }
        }
    }
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, 0);
        int start = 0;
        dfsUtil(start, adj, visited, ans);
        return ans;
    }
};
int main()
{
    int V, e;
    cout << "enter number of vertices and edges";
    // V=number of vertices
    cin >> V >> e;
    vector<int> adj[V];
    cout << "enter values of edges";
    for (int i = 0; i < e; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}