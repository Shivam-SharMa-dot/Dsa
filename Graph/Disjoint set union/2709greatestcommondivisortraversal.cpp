#include <bits/stdc++.h>
using namespace std;
// DSU implementaitioon by size
class DisjointSet
{
    vector<int> parent, size;
    int numofcomponents;

public:
    DisjointSet(int n)
    {
        // intitail rank will be zero for all
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        numofcomponents = n;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    //   find operation
    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    //   union operation
    void UnionBySize(int x, int y)
    {
        int xparent = findUpar(x);
        int yparent = findUpar(y);
        if (xparent == yparent)
        {
            return;
        }
        if (size[xparent] > size[yparent])
        {
            parent[yparent] = xparent;
            size[xparent] += size[yparent];
        }
        else if (size[yparent] > size[xparent])
        {
            parent[xparent] = yparent;
            size[yparent] += size[xparent];
        }
        else
        {
            // then make anyone parent onyour choice and increase his rank
            parent[xparent] = yparent;
            size[yparent] += size[xparent];
        }
        numofcomponents -= 1;
    }
    int countofcomponents()
    {
        return numofcomponents;
    }
};
class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        DisjointSet dsu(n);
        unordered_map<int, int> mp;

        for (int i = 0; i <= n; i++)
        {
            for (int factor = 2; factor * factor <= nums[i]; factor++)
            {
                if (nums[i] % factor != 0)
                {
                    continue;
                }
                // if alreday present in factor map then make DSU
                if (mp.find(factor) != mp.end())
                {
                    int idx = mp[factor];
                    dsu.UnionBySize(idx, i);
                }
                // means seeing first time
                else
                {
                    mp[factor] = i;
                }
                while (nums[i] % factor == 0)
                {
                    nums[i] = nums[i] / factor;
                }
            }
            if (nums[i] > 1)
            {
                if (mp.find(nums[i]) != mp.end())
                {
                    int idx = mp[nums[i]];
                    dsu.UnionBySize(idx, i);
                }
                else
                {
                    mp[nums[i]] = i;
                }
            }
        }
        return dsu.countofcomponents() == 1;
    }
};