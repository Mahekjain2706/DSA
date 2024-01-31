#include<bits/stdc++.h>
using namespace std;


int main(){

    // UNDIRECTED

    // int n,m;
    // cin>>n>>m;

    // // adjancy matrix
    // int adj[n+1][m+1];

    // for(int i=0,i<m;i++){ T.C O(n*n)
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // adjacency list
    // array of size n+1
    // we make array of vectors
    // int n,m;
    // cin>>n>>m;  // T.C O(2*m)
    // vector<int>adj[n+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    // DIRECTED // T>C O(n)
    int n,m;
    cin>>n>>m;
    int vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>> u>>v;
        adj[u].push_back(v);
    }

    // Weighted Graph
    // matrix
    // in adjaceny matrix instead of  1 we write were matrix present we right weight of edge.

    // list
    // vector<pair<int,int>> adjc[n+1];
   
    
    // connected components
    // if each nodes are connected to  each other or two or more than two graphs connected 
    // so these are connected components oof graphs
    
    // we use visited array always
    // if graph have multiple components then we have to make visited array to traverse each components not by single node we traverse the whole.

    return 0;
}