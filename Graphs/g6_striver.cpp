#include<bits/stdc++.h>
using namespace std;
// IMP

// Number of Connected Components/ iselands
// int n,m;
// void bfs(int row,int col,vector<int> &vis,vector<vector<int>> &grid){
//      vis[row][col]=1;
//      queue<pair<int,int>> q;
//      q.push({row,col});

//      while(!q.empty()){
//         int row = q.front().first;
//         int col = q.front().second;
//         q.pop();

//         // traverse at its neighbours
//         for(int delrow = -1;delrow<=1;delrow++){
//             for(int delcol=-1;delcol<=1;delcol++){
//                 int nrow = row+ delrow;
//                 int ncol = col+ delcol;

//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
//                   vis[nrow][ncol]=1;
//                   q.push({nrow,ncol});
//                 }
//             }
//         }

//      }
// }
// // s.c O(n*n)(visited) + O(n*n)(queue space) 
// // T.c O(n*n)(Traversal) * (element were 1 present so it is numerical value) 

// int numIslands(vector<vector<int>> &grid){
//      n = grid.size();
//      m = grid[0].size();

//     vector<vector<int>> vis(n,vector<int>(m,0));
//     int cnt=0;
//     for(int row=0;row<n;row++){
//         for(int col=0;col<m;col++){
//             if(!vis[row][col]){
//                 cnt++;
//                 bfs(row,col,vis,grid);
//             }
//         }
//     }
//     return cnt;
// }



// Flood fill Algorithm // BFS
// T.C O(n*m)->nodes*4(neighbours) = O(n*m)
// S.C O(n*m)->matrix + O(n*m)->stack space dfs = O(n*m)
// void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>> &image,int newColor,int delRow[], int delCol[],int iniColor){
//     ans[row][col] = newColor;

//     for(int i=0;i<4;i++){
//         int nRow = row + delRow[i];
//         int nCol = col + delCol[i];

//         if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
//         image[nRow][nCol] == iniColor  && ans[nRow][nCol] !=newColor){
//             dfs(nRow,nCol,ans,image,newColor,delRow,delCol,iniColor);
//         }
//     }
// }

// vector<vector<int>> floodfill(vector<vector<int>> &image,int sr,int sc,int newColor){
//     int iniColor=image[sr][sc];
//     vector<vector<int>> ans = image;
//     int delRow[] = {-1,0,+1,0};
//     int delCol[] = {0,+1,0,-1};
//     dfs(sr,sc,ans,image,newColor);
// }



//  0-> empty cell  1-> fresh  2-> rotten 
// bfs
// S.C O(n*m)   // T.C O(n*m) + (n*m*4) = O(n*m)
// int bfs(int row,int col,vector<vector<int>> &Orange,int delrow[],int delcol[]){
//     // n*m
//     vector<vector<int>> vis(row,vector<int>(col,0));
//     // n*m
//     queue<pair<pair<int,int>,int>> q;
    
//     int cntFresh=0,cntR=0;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if(Orange[i][j]==2){
//                 vis[i][j]=1;
//                 q.push({{i,j},0});
//             }
//             if(Orange[i][j]==1){
//                 cntFresh++;
//             }
//         }
//     }
//     int tm=0;
    
//     while(!q.empty()){
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int cnt = q.front().second;
//         tm = max(tm,cnt);
//         q.pop();
        
//         for(int i=0;i<4;i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && Orange[nrow][ncol]='1' && vis[nrow][ncol]!=1){
//                 vis[nrow][ncol]=1;
//                 q.push({{nrow,ncol},cnt++});
//                 cntR++;
//             }
//         }
//     }
//     if(cntR!=cntFresh) return -1;
//     return tm;
// }

// int rottenOranges(vector<vector<int>> &Orange){
//     int row = grid.size();
//     int col = grid[0].size();
//     int delrow[]={-1,0,+1,0};
//     int delcol[]={0,+1,0,-1};
//     int time = bfs(row,col,Orange,delrow,delcol);
    
//     return time;
// }


int main(){
    int n,m;
    cin>>n>>m;
    
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;
    }

    return 0;
}