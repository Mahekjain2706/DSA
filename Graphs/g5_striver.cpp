#include<bits/stdc++.h>
using nmaespace std;

// NUMBER OF PROVINES
// if we have path from one node to each of another nodes then it is province

void dfs(int start,vector<int> adj[],int vis[])
{
    vis[start]=1;
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
// S.C O(n+n)(recursion stackspace + visited array + not counting adj ls)
// T.C O(n + v+2E)
int NumProvinces(int n,vector<vector<int>> adj){
    vector<int> adjLs[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(j);
            }
        }
    }

    int vis[n]={0};
    int cnt=0;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    } 
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}