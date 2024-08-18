#include<bits/stdc++.h>
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
    //   find operation
    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // we are not stroring into something 
        return parent[node]=findUpar(parent[node]);
    }
};