#include<bits/stdc++.h>
using namespace std;

// Rotten Oranges
int rottenOranges(vector<vector<int>> &adj){
    int n=adj.size(),m=adj[0].size();

    int cntfresh=0,cntRotten=0;
    
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visit;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==2){
                q.push({{i,j},0});
                visit[i][j]=2;
            }
            else{
                visit[i][j]=0;
            }

            if(adj[i][j]==1) cntfresh++;
        }
    }
    int tm = 0;
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,-1,1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]==1 && visit[nrow][ncol]!=2){
                q.push({{nrow,ncol},t+1});
                visit[nrow][ncol]=2;
                cntRotten++;
            }
        }
    }

    if(cntfresh!=cntRotten) return -1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(visit[i][j]!=2 && adj[i][j]==1) return -1;
    //     }
    // }
    return tm;
}


// Detect Cycle in a Undirected Graph
// BFS 
// t.c O(v+2e)  s.c O(n) // queue + O(n) // visit = O(n)
bool bfs(vector<int> adj[],int sr,int visit[]){
    visit[sr]=1;
    queue<pair<int,int>> q;
    q.push({sr,-1});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.first;
        int parent = it.second;

        for(auto it1: adj[node]){
            if(!visit[it1]){
                q.push({it1,node});
                visit[node]=1;
            }
            else{
                if(it1!=parent)
                    return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<int> adj[],int n){
    int visit[n]={0};

    for(int i=0;i<n;i++){
        if(!visit[i]){
            if(bfs(adj,i,visit)==true) return true;
        }
    }
    return false;
}


// Detech Cycle in Graph
// DFS
// T.C O(n+2e)+O(n)    s.c O(n)// recusion space + O(n) // visited
bool dfs(vector<int> adj[],int visit[],int node,int parent){
    visit[node]=1;
    for(auto it:adj[node]){
        if(!visit[it]){
            if(dfs(adj,visit,it,node)==true) return true;
        }
        else if(it !=parent) return true;
    }
    return false;
}
bool isCycleP(vector<int> adj[],int n){
    int visit[n]={0};

    for(int i=0;i<n;i++){
       if(!visit[i]){
        if(dfs(adj,visit,i,-1)==true) return true;
       } 
    }
    return false;
}


// distance of nearest cell having 1
// Optimized
vector<vector<int>> nearest(vector<vector<int>> grid){
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> visit(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                visit[i][j] = 1;
            }
            else{
                visit[i][j] = 0;
            }
        }
    }

    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,1,-1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        ans[row][col] = step;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col +delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visit[nrow][ncol]==0){
                visit[nrow][ncol] = 1;
                q.push({{nrow,ncol},step+1});
            }
        }
    }
    return ans;
}

// Surrounded regions
// surrounded O's by X's convert into X's
// T.C O(n*m)+ O(n)+O(m) => O(n*m)   S.C O(n*m)
void fill(int sr,int sc,vector<vector<char>> adj,vector<vector<int>> vis,int delrow[],int delcol[]){
    vis[sr][sc]=1;
    int n = adj.size(),m=adj[0].size();

    // top right bottom left
    
    for(int i=0;i<4;i++){
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && adj[nrow][ncol]=='O'){
            fill(nrow,ncol,adj,vis,delrow,delcol);
        }
    }
}
vector<vector<char>> surround(vector<vector<char>> adj){
    int n = adj.size(),m=adj[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};
    
    for(int j=0;j<m;j++){
        if(adj[0][j]=='O' && !vis[0][j]){
            fill(0,j,adj,vis,delrow,delcol);
        }

        if(adj[n-1][j]=='O' && !vis[n-1][j]){
            fill(n-1,j,adj,vis,delrow,delcol);
        }
    }

    for(int i=0;i<m;i++){
        if(!vis[i][0] && adj[i][0]=='O'){
            fill(i,0,adj,vis,delrow,delcol);
        }
        if(!vis[i][m-1] && adj[i][m-1]=='O'){
            fill(i,m-1,adj,vis,delrow,delcol);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && adj[i][j]=='O'){
                adj[i][j]='X';
            }
        }
    }
    return adj;
}


// Number of  Enclaves

int noOfEnclaves(vector<vector<int>> adj){
    int n=adj.size(),m=adj[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        if(!vis[i][0] && adj[i][0]==1){
            vis[i][0]=1;
            q.push({i,0});
        }
        if(!vis[i][m-1] && adj[i][m-1]==1){
            vis[i][m-1]=1;
            q.push({i,m-1});
        }
    }
    for(int j=0;j<m;j++){
        if(!vis[0][j] && adj[0][j]==1){
            vis[0][j]=1;
            q.push({0,j});
        }
        if(!vis[n-1][j] && adj[n-1][j]==1){
            vis[n-1][j]=1;
            q.push({n-1,j});
        }
    }
    int delrow[4]={-1,1,0,0};
    int delcol[4] ={0,0,-1,1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && adj[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && adj[i][j]==1) cnt++;
        }
    }
    return cnt;
}


// Number of Distincts Islands
void goBfs(int sr,int sc,vector<vector<int>> adj,vector<vector<int>> &vis,int delrow[],int delcol[],set<vector<pair<int,int>>> &st){
    queue<pair<int,int>> q;
    int n = adj.size(),m=adj[0].size();
    q.push({sr,sc});
    vis[sr][sc]=1;
    vector<pair<int,int>> vec;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        vec.push_back({x-sr,y-sc});

        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && adj[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    st.insert(vec);
}
int distinctIslands(vector<vector<int>> adj){
    int n = adj.size(),m=adj[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[4]={-1,1,0,0};
    int delcol[4] ={0,0,-1,1};
    set<vector<pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && adj[i][j]==1){
                goBfs(i,j,adj,vis,delrow,delcol,st);
            }
        }
    }
    return st.size();
}


int main(){

    // adjacency Matrix
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        vector<int> use;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            use.push_back(a);
        }
        adj.push_back(use);
    }

    // adjacency List
    // int n,m;
    // cin>>n>>m;
    // vector<int> adj[n];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    
    cout<< endl;
    // vector<vector<int>> ans = nearDist(adj);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<< ans[i][j] << " ";
    //     }
    //     cout<< endl;
    // }

    return 0;
}