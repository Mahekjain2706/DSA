#include<bits/stdc++.h>
using namespace std;

// Bredth First Search
vector<int> breadthfirstsearch(int n,vector<int> adj[]){
   int vis[n] = {0};   // S.C (3N)  T.C = O(N + 2M)
   vis[0]=1;
   queue<int> q;
   q.push(0);
   vector<int>bfs;

   while(!q.empty()){
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for(auto it:adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            q.push(it);
        }
    }
   }
   return bfs;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = breadthfirstsearch(n,adj);
    for(int i=0;i<n;i++){
        cout<< ans[i] << " ";
    }
     
    return 0;
}