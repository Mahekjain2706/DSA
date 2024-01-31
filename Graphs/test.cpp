#include<bits/stdc++.h>
using namespace std;

// vector<int> BFS(vector<int> adj[],int n){
//     // s.c O(3*n)=O(n)   t.c O(all degree) O(n)+O(2*m)
//     queue<int> q;
//     int visted[n]={0};
//     visted[0]=1;
//     q.push(0);
//     vector<int>bfs;
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         bfs.push_back(node);
        
//         for(auto it:adj[node]){
//             if(!visted[it]){
//                 visted[it]=1;
//                 q.push(it);
//             }
//         }
//     }
//     return bfs;
// }




void Dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                Dfs(it,adj,vis,ls);
            }
        }
}
vector<int> DFS(vector<int> adj[],int n){
    // S.c O(n)+O(n) = o(n)(not include adj)
    // T.c O(n)+O(2*m)
    int vis[n]={0};
    int start = 0;
    vector<int> ls;
    Dfs(start,adj,vis,ls);
    return ls;
}



// void dfs(int node,vector<int> adjLs[],int vis[]){
//       vis[node] = 1;
//       for(auto it:adjLs[node]){
//         if(!vis[it]){
//             dfs(it,adjLs,vis);
//         }
//       }
// }
// int numProviences(vector<vector<int>> adj,int n){
//     s.c = O(n)(visted array)+O(n) recursion call
//     t.c = O(n) + o(v+2*e)
//     vector<int> adjLs[n];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//              if(adj[i][j]==1 && i!=j){
//                  adjLs[i].push_back(j);
//                  adjLs[j].push_back(i);
//              }
//         }
//     }
//     int vis[n] = {0};
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             cnt++;
//             dfs(i,adjLs,vis);
//         }
//     }
//     return cnt;
// }


// Number of Islands
// void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &adj){
//     // s.c = o(n*n)visted + o(n*n)  queue space 
//     // t.c = O(n*n) traverse + O(n*n) island present 
//     vis[row][col] = 1;
//     queue<pair<int,int>>q;
//     q.push({row,col});
//     int n = adj.size();
//     int m = adj[0].size();

//     while(!q.empty()){
//         int row = q.front().first;
//         int col = q.front().second;
//         q.pop();

//         for(int delrow=-1;delrow<=1;delrow++){
//             for(int delcol=-1;delcol<=1;delcol++){
//                 int nrow = row + delrow;
//                 int ncol = col +  delcol;

//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='1' && !vis[nrow][ncol]){
//                     vis[nrow][ncol]=1;
//                     q.push({nrow,ncol});
//                 }
//             }
//         }
        
//     }

// }
// int numIsland(vector<vector<char>> &adj){
//     int n = adj.size();
//     int m = adj[0].size();
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     int cnt=0;
//     for(int row = 0;row<n;row++){
//         for(int col=0;col<n;col++){
//              if(!vis[row][col] && adj[row][col]=='1'){
//                 cnt++;
//                 bfs(row,col,vis,adj);
//              }
//         }
//     }
//     return cnt;
// }


// Flood Fill Algorithm 
//   void dfs(int row,int col,vector<vector<int>> ans,int iniColor,int delrow[],int delcol,int newColor){
//        ans[row][col] = newColor;
//        int n = ans.size();int m = ans[0].size();
//        for(int i=0;i<4;i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];
//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
//             dfs(nrow,ncol,ans,iniColor,delrow,delcol, newColor);
//         }
//        }
//   }
//   vector<vector<int>> floodFill(vector<vector<int>> &adj,int sr,int sc,int newColor){
//     //  t.c O(n*m)  s.c O(n*m)(matrix)+ O(n*m)(recursive space)
//     int iniColor = adj[sr][sc];
//     vector<vector<int>> ans = adj;
//     int delrow[4]={-1,0,1,0};
//     int delcol[4]={0,1,0,-1};
//     dfs(sr,sc,ans,iniColor,delcol,delrow,newColor);
    
//   }


// Rotten Oranges
// int orangesRotting(vector<vector<int>> adj){
    //  s.c O(n*m)   t.c O(n*m)+ O(n*m)*4
//     int n =  adj.size();
//     int m  = adj[0].size();

//     queue<pair<pair<int,int>,int>> q;
//     vector<vector<int>> vis(n,vector<int>(m,0));
    
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(adj[i][j]==2){
//                 q.push({i,j},0);
//                 vis[i][j]=2; 
//             }
//             else{
//                 vis[i][j]=0;
//             }
//         }
//     }
//     int delrow[4] = {-1,0,1,0};
//     int delcol[4] = {0,1,0,-1};

//     int tm = 0;
//     while(!q.empty()){
//         auto it = q.front();
//         int x = it.first.first;
//         int y =it.first.second;
//         int t = it.second;
//         q.pop();

//         for(int i=0;i<4;i++){
//             int nrow = x + delrow[i];
//             int ncol = y + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 &&ncol>m && adj[nrow][ncol]==1 && !vis[nrow][ncol]){
//                 q.push({{nrow,ncol},t+1});
//                 vis[nrow][ncol] = 1;
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j]!=2 && adj[i][j]==1) return -1;
//             }
//         }
//         return tm;
//     }
// }


// Cycle detection using bfs

// bool detect(int src,vector<int> adj[],int vis[]){
//     // t.c = O(n+2*e)  s.c = O(n)+O(n) 
//     vis[src]=1;
//     queue<pair<int,int>> q;
//     q.push({src,-1});
//     while(!q.empty()){
//         int node = q.front().first;
//         int parent = q.front().second;

//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 q.push({it,node});
//                 vis[it]=1;
//             }
//             else if(parent!=it){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool isCycle(int n,vector<int> adj[]){
//     int vis[n] = {0};
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(detect(i,adj,vis)) return true;
//         }
//     }
//     return false;
// }

// cycle detection using dfs

// bool detected(int node,int parent,vector<int> adj[],vis[]){
    //  s.c O(n)recursion + O(n)visted array
    // t.c  O(n+2*e)+O(n)
//     vis[node]=1;
    
//     for(auto it:adj[node]){
//         if(!vis[it]){
//             if(detected(it,node,adj,vis)==true){
//                 return true;
//             }
//         }
//         else if(parent!=it){
//             return true;  
//         } 
//     }
//     return false;
// }

// bool isCycle(int n,vector<int> adj[]){
//     int vis[n]={0};
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(detected(i,-1,adj,vis)) return true;
//         }
//     }
//     return false;
// }




int main(){
    
    int n,m;
    cin>>n>>m;
    // int adj[n][m]={0};

    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;

    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<< adj[i][j]<<" ";
    //     }
    //     cout<< endl;
    // }

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=adj[i].size();i++){
    //         cout<< adj[i][j] << " ";
    //     }
    //     cout<< endl;
    // }
    // vector<int>bfs = BFS(adj,n);
    // for(int i=0;i<bfs.size();i++){
    //     cout<< bfs[i] << " ";
    // }
    // cout<< endl;
    vector<int>dfs = DFS(adj,n);
    for(int i=0;i<dfs.size();i++){
        cout<< dfs[i] << " ";
    }

    // int cnt = numProviences(adj,n);
    // cout<< cnt << endl;

    return 0;
}
