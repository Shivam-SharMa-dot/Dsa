class Solution {
    bool detectcycle(int src,int vis[],vector<int> adj[]){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node =q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adjacent :adj[node]){
                if(!vis[adjacent]){
                    vis[adjacent]=1;
                    q.push({adjacent,node});
                }
                // if someone has visited but not coming from parent means contain cycle
                else if(parent != adjacent){ 
                    return true;
                }
            }
        }
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        
        // if graph have component 
        for (int i =0;i<V;i++){
            if(!vis[i]){
                if(detectcycle(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};