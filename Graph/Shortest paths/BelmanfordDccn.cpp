// 2) Bellman Ford

#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

void printShortestPath(vector<int> &parent, int v, queue<int> &path, vector<int> &weights)
{
    if (v == -1)
    {
        return;
    }
    printShortestPath(parent, parent[v], path, weights);
    path.push(v);
}

bool bellmanFord(vector<vector<pair<int, int>>> &adjacencyList, int numVertices, int source, int destination)
{
    vector<int> distance(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; ++i)
    {
        for (int u = 0; u < numVertices; ++u)
        {
            for (pair<int, int> edge : adjacencyList[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < numVertices; ++u)
    {
        for (pair<int, int> edge : adjacencyList[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                cout << "Graph contains a negative weight cycle" << endl;
                return false;
            }
        }
    }

    if (distance[destination] != INT_MAX)
    {
        queue<int> path;
        printShortestPath(parent, destination, path, distance);
        cout << "Shortest Path from " << source << " to " << destination << ": Distance = " << distance[destination] << ", Path = ";
        while (!path.empty())
        {
            cout << path.front();
            path.pop();
            if (!path.empty())
            {
                cout << " -> ";
            }
        }
        cout << endl;
        return true;
    }
    else
    {
        cout << "There is no path from " << source << " to " << destination << "." << endl;
        return false;
    }
}

int main()
{
    int v, e;
    cout << "Enter number of Vertices of your network topology: ";
    cin >> v;
    cout << "Enter number of Edges of your network topology: ";
    cin >> e;

    vector<vector<pair<int, int>>> adjacencyList(v);

    for (int i = 0; i < e; i++)
    {
        cout << "Enter first vertex, second vertex, and Weight between the two vertex: ";
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        adjacencyList[v1].push_back({v2, weight});
        adjacencyList[v2].push_back({v1, weight});
    }

    int src, dest;
    cout << "Enter source and destination of the network: ";
    cin >> src >> dest;
    bellmanFord(adjacencyList, v, src, dest);

    return 0;
}
