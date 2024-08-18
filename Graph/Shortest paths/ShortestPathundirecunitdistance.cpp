// striver video number G-31
// shortest path in undirectd graph having unit distance

#include <bits/stdc++.h>
using namespace std;

// strivers video
// T.C=(v+2E)  same as BFS
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int dist[N];
        for (int i = 0; i < N; i++)
        {
            dist[i] = 1e9;
        }
        dist[src] = 0;
        // in q we are just storing node because distance we can get from distance array

        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
        {
            // agar wha pe 1e9 nhi hoga mtalb humlog wha visit kiye h so assign visited value
            // or if we have not reached means ==1e9 so return -1 which has been already filled in vector
            if (dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }
        return ans;
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
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends