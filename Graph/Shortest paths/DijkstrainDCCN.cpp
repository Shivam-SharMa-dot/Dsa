// 1) dijkstra

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDistance(const vector<int> &distance, const vector<bool> &visited, int V)
{
    int minDist = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; ++v)
    {
        if (!visited[v] && distance[v] < minDist)
        {
            minDist = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(const vector<int> &parent, int target)
{
    if (parent[target] == -1)
        return;

    printPath(parent, parent[target]);
    cout << " -> " << target;
}

void dijkstra(const vector<vector<int>> &graph, int src, int V)
{
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    distance[src] = 0;

    for (int count = 0; count < V - 1; ++count)
    {
        int u = minDistance(distance, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; ++v)
        {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest paths from source " << src << ":\n";
    for (int i = 0; i < V; ++i)
    {
        if (i != src)
        {
            cout << "From " << src << " to " << i << ": ";
            cout << src;
            printPath(parent, i);
            cout << " (Distance = " << distance[i] << ")\n";
        }
    }
}

int main()
{
    int V, src;
    cout << "Enter the number of vertices of the network topology: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source vertex of the network: ";
    cin >> src;

    dijkstra(graph, src, V);

    return 0;
}
