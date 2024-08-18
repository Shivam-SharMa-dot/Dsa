#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    // here bfs is being used
    bool checker(int start,int V,int color[],vector<int> adj[]){
      queue <int> q;
	    q.push(start);
      color[start]=1;
	    while(!q.empty ()){
	        int node=q.front();
	        q.pop();
	        for(auto it :adj[node]){
	            if(color[it]==-1){
	                // if the adjaacent is not colored give the opposite color
	                color[it]=!color[node];
	                q.push(it);
	            }
	 //means someone have already colored so return false not bipartite
	            else if(color[it] == color[node]){
	                return false;
	            }  
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here 
	    int color[V] ;
	    for(int i = 0;i< V ;i++ ){
	        color[i] = -1;
	    }
	  
	 // if graph have component 
	  for(int i=0;i<V;i++){
	      if(color[i]==-1){
	          if(checker(i,V,color,adj)==false){
	              return false;
	          }
	      }
	  }
	    return true;
	}

};