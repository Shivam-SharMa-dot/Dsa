// this graph have been created using adjancey list
// which takes O(2*edges)
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction 0 means undirected
        // direction 1 means directed
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
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
    // n and m should be given in question
    int n;
    cout << "enter the number of nodes";
    cin >> n;
    int m;
    cout << "enter the number of edges";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }
    g.printAdjlisst();

    return 0;
}
