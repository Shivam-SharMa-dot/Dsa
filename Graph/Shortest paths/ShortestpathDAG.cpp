

/* The issue you're facing is likely due to the way the code handles unreachable nodes in your graph.
 In this code, the initial distance values for all nodes are set to 1e9,
 which represents infinity. If a node is not reachable from the source node (node 0 in this case),
 its distance will remain at 1e9, and this is why you see values like 1000000000 in the output.
To handle unreachable nodes properly, you should update your code to detect and report them as such,
rather than setting their distance to a large number like 1e9.
Here's an updated version of your code that handles unreachable nodes: */


#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void toposort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                toposort(v, vis, adj, st);
            }
        }
        // while returning  push into stack concept of topological sort
        st.push(node);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        //   unordered_map<int,vector<pair<int,int>>> adj;
        vector<pair<int, int>> adj[N];
        // this loop run till number of edges
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        // dont use array as visited array in c++20 it is not good to use
        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                toposort(i, vis, adj, st);
            }
        }

        vector<int> dist(N);
        // inplace of 1e9 we can use INT_MAX also but here in question 1e9 is fixed
        for (int i = 0; i < N; i++)
            dist[i] = 1e9;
        // make sorce node distance as zero
        // if not given source node made anyone as zero
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
         // here if node is unrechaable from source node
            if (dist[node] == 1e9)
            {
                continue; // Skip unreachable nodes
            }

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                // this part is known as relaxation
                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
     // handle here which node are unrechable from soure node
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1; // Set distance to -1 for unreachable nodes
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends