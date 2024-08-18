#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        // intitail rank will be zero for all
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    //   find operation with path compression 
    // if directly called without storing then that will be without compression
    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    //   union operation
    void UnionByRank(int x, int y)
    {
        int xparent = findUpar(x);
        int yparent = findUpar(y);
        if (xparent == yparent)
        {
            return;
        }
        if (rank[xparent] > rank[yparent])
        {
            parent[yparent] = xparent;
        }
        else if (rank[yparent] > rank[xparent])
        {
            parent[xparent] = yparent;
        }
        else
        {
            // then make anyone parent onyour choice and increase his rank
            parent[xparent] = yparent;
            rank[yparent] += 1;
        }
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);
    // #endif
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);

    if (ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "Same";
    }
    else
    {
        cout << "not same";
    }
    ds.UnionByRank(3, 7);
    if (ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "Same";
    }
    else
    {
        cout << "not same";
    }
    return 0;
}