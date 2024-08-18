#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,size;
    public:
  DisjointSet(int n){
    // intitail rank will be zero for all
    size.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
  }
//   find operation
  int findUpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node] = findUpar(parent[node]);
  }
//   union operation
void UnionBySize(int x,int y){
    int xparent=findUpar(x);
    int yparent=findUpar(y);
    if(xparent==yparent){
        return;
    }
    if(size[xparent] >size[yparent]){
        parent[yparent]=xparent;
        size[xparent]+=size[yparent];
    }
    else if(size[yparent] >size[xparent]){
        parent[xparent]=yparent;
        size[yparent]+=size[xparent];
    }
    else{
        // then make anyone parent onyour choice and increase his rank
        parent[xparent] =yparent;
        size[yparent]+=size[xparent];
    }
}
};

int main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("input.txt","w",stdout);
// #endif
DisjointSet ds(7);
ds.UnionBySize(1,2);
ds.UnionBySize(2,3);
ds.UnionBySize(4,5);
ds.UnionBySize(6,7);
ds.UnionBySize(5,6);

if(ds.findUpar(3)==ds.findUpar(7)){
    cout<<"Same\n";
}
else{
    cout<<"not same\n";
}
ds.UnionBySize(3,7);
if(ds.findUpar(3)== ds.findUpar(7)){
    cout<<"Same\n";
}
else{
    cout<<"not same\n";
}
return 0;
}