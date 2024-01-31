#include<bits/stdc++.h>
using namespace std;

// bfs Traversal
vector<int> BFS(vector<int> arr[],int n){
    queue<int> q;
    int visit[n]={0};
    visit[0]=1;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:arr[node]){
            if(!visit[it]){
                visit[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// dfs Traversal
void dfs(int node,vector<int> arr[],int vis[],vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it:arr[node]){
        if(!vis[it]){
            dfs(it,arr,vis,ls);
        }
    }
}
vector<int> DFS(vector<int> arr[],int n){
    int vis[n] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start,arr,vis,ls);
    return ls;
}


// Number of Proviences // DFS

void dfs(int node,vector<int> adjLs[],int vis[]){
    vis[node]=1;
    for(auto it:adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}

int numProviences(vector<vector<int>> &arr,int n){
    vector<int> adjLs[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[n] = {0};
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }
    return cnt;
}


// Number of IsLands // BFS
void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>&arr){
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = arr.size();int m = arr[0].size();

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;int y = it.second;

        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow = x + delrow;
                int ncol = y + delcol;

                if(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<=m-1 && !vis[nrow][ncol] && arr[nrow][ncol]=='1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && arr[row][col]=='1'){
                cnt++;
                bfs(row,col,vis,arr);
            }
        }
    }
}

// Flood Fill Algorithm
void dfs(int sr,int sc,vector<vector<int>> &ans,int iniColor,int newColor,int delrow[],int delcol[]){
    ans[sr][sc] = newColor;
    int n = ans.size();int m = ans[0].size();
    for(int i=0;i<4;i++){
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol,ans,iniColor,newColor,delrow,delcol);
        }
    }
}
vector<vector<int>> floodfill(vector<vector<int>> &arr,int newColor,int sr,int sc){
    int iniColor = arr[sr][sc];
    vector<vector<int>> ans = arr;
    int delrow[4] = {-1,0,0,1};
    int delcol[4] = {0,-1,1,0};
    dfs(sr,sc,ans,iniColor,newColor,delrow,delcol);
    return ans;
}

// Rotten Oranges


int main(){

    // adjacency Array
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    // adjacency List
    // int n,m;
    // cin>>n>>m;
    // vector<int> arr[n+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;

    //     arr[u].push_back(v);
    //     arr[v].push_back(u);
    // }


    return 0;
}