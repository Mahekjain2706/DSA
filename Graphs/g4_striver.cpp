#include<bits/stdc++.h>
using namespace std;

 // S.C o(recursion: n + n + n)=O(n)
   void dfs(int node,vector<int>adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    // traverse all neighbours
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
   }
        // undirected  // T.C O(sum of degrees= 2E + N)
        // directed    // T.c (2E)
vector<int> DepthFirstSearch(int n,vector<int> adj[]){
    int vis[n]={0};
    int start=0;
    vis[0]=1;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

int main(){
    
    int n,n=m;
    cin>>n>>m;

    vector<int> adj[n=1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}