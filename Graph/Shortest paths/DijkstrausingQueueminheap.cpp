//{ Driver Code Starts

// gfg 
// visit coding ninjas question it is awesome
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);

        for (int i = 0; i < V; i++)
            dist[i] = 1e9;

        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int dis = pq.top().first;

            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjacentnode = it[0];
                int adjacentweight = it[1];

                if (dis + adjacentweight < dist[adjacentnode])
                {
                    dist[adjacentnode] = dis + adjacentweight;

                    // here some part is trickey
                    pq.push({dist[adjacentnode], adjacentnode});
                }
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends


// coding ninjas 
/* 
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int e, int S) {
    // Write your code here.
    vector<pair<int,int>> adj[V];
    for(int i=0;i<e;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        // here 1e9 is not working
        //vector<int> dist(V,INT_MAX);
        for(int i=0;i<V;i++) dist[i]=INT_MAX;
        
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis= pq.top().first;
            
            int node=pq.top().second;
            pq.pop();
            
           for(auto it : adj[node]){
               int adjacentnode=it.first;
               int adjacentweight=it.second;
               
               if(dis+adjacentweight < dist[adjacentnode]){
                   dist[adjacentnode]=dis+adjacentweight;
                   pq.push({dist[adjacentnode],adjacentnode});
               }
           }    
            
        }
        return dist;
}


//mmost optimal solution can be said 
// T.c Elog(V);
//s.c=(E+V)






 */