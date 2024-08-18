// coding ninjas see in using vector as boool or array as bool it is giving TLE and error
// see carefully as passing by reference of stack and vis and adj 
// in gfg passing adj as pass by refernece is giving error

#include <bits/stdc++.h> 
using namespace std;
 void dfs(int node, vector<bool> &vis,stack<int>&st, unordered_map<int,list<int>> &adj){
        vis[node]=1;
      
        for(auto it:adj[node]){
            if(!vis[it]){
             dfs(it,vis,st,adj);   
            }
        }
          st.push(node);
    }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // adjacent list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        adj[x].push_back(y);
    }
  vector<bool> vis(v);
	    stack<int> st;
	    for(int i=0;i<v;i++){
            if(!vis[i]){
	        dfs(i,vis,st,adj);
            }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
 return ans;

}

int main(){
    return 0;
}


