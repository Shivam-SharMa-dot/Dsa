// if adjency list is not given edge is given
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// step1 find adjlist
void prepareadjList(int n, unordered_map<int, set<int>> &adjlist, vector<vector<int>> &adj)
{
    for (int i = 0; i < n; i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        // store the answer
        ans.push_back(frontnode);
        // traverse all the nodes of front node
        for (auto i : adjlist[frontnode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// main function given is question
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    unordered_map<int, set<int>> adjlist;
    vector<int> ans;

    unordered_map<int, bool> visited;
    
    prepareadjList(n, adjlist, adj);
    // if graph contains connected components then we have to do in loop  see striver 2nd video
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(adjlist, visited, ans, i);
        }
    }
    return ans;
}
// graph creation and printing
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v)
    {
        // direction 0 means undirected
        // direction 1 means directed
        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    void printAdjlisst()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    cout << "enter the nunmber of vertex and edges";
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printAdjlisst();
    // vector<int> traversal = bfsTraversal(n,)
}

// if direct adjency list is given
// vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
//     // Write your code here.
//   int visited[n]={0};
//         queue<int> q;
//         q.push(0);
//         visited[0]=1;
//         vector<int> ans;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             ans.push_back(node);
//             for(auto it : adj[node]){
//                 if(!visited[it]){
//                     q.push(it);
//                     visited[it]=1;
//                 }
//             }
//         }
//        return ans;   
// }