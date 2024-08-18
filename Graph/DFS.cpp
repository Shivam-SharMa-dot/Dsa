// this code handles both graph component expected output also
// coding ninjas question
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, vector<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            dfs(i, adjlist, visited, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    // step1 prepare adj list
    unordered_map<int, vector<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    // this loop is given if graph have component
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adjlist, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    int V, E;
    cout << "enter number of vertices and edges";
    // V=number of vertices
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    cout << "enter values of edges ";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> ans = depthFirstSearch(V, E, edges);
    for (const auto &component : ans)
    {
        for (int num : component)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
