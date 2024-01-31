#include<bits/stdc++.h>
using namespace std;

// BFS // T.C O(n+m) S.C O(n)
// vector<int> breathFirstSearch(int n,vector<int> adj[]){
//     queue<int> q;
//     q.push(0);
//     vector<int> vis(n,0);
//     vector<int> ans;
//     vis[0]=1;
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();

//         ans.push_back(node);
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 vis[it]=1;
//                 q.push(it);
//             }
//         }   
//     }
//     return ans;
// }

// DFS T.C O(n+m)+O(n) recursive S.C O(n) 
// void dfs(int node,int n,vector<int> adj[],vector<int> &ans,int vis[]){
//     vis[node]=1;

//     ans.push_back(node);
//     for(auto it:adj[node]){
//         if(!vis[it]){
//             dfs(it,n,adj,ans,vis);
//         }
//     }
// }
// vector<int> depthFirstSearch(int n,vector<int> adj[]){
//     vector<int> ans;
//     int vis[n]={0};
//     vis[0]=1;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             dfs(i,n,adj,ans,vis);
//         }
//     }
//     return ans;
// }

// Number of proviences // T.C O(n+m)+O(n) S.C O(n)
// void provience(int node,vector<int> adj[],int vis[]){
//     vis[node]=1;

//     for(auto it:adj[node]){
//         if(!vis[it]){
//             provience(it,adj,vis);
//         }
//     }
// }
// int numOfProviences(int n , vector<int> adj[]){
//     int cnt=0;
//     int vis[n]={0};
//     vis[0]=1;
    
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             cnt++;
//             provience(i,adj,vis);
//         }
//     }
// }


// BFS // T.C O(n*m) S.C O(n*m)
// void countIsland(int row,int col,vector<vector<char>> &adj,vector<vector<int>> &vis){
//     int n = adj.size() , m = adj[0].size();
//     queue<pair<int,int>> q;
//     q.push({row,col});
//     vis[row][col]=1;

//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};

//     while(!q.empty()){
//         int x = q.front().first; int y = q.front().second;
//         q.pop();

//         for(int i=0;i<4;i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
//                 vis[nrow][ncol]=1;
//                 q.push({nrow,ncol});
//             }
//         }
//     }
// }
// DFS // T.C O(n*m) S.C O(n*m)
// void islands(int row,int col,vector<vector<char>> &adj,vector<vector<int>> &vis,int delrow[],int delcol[]){
//     int n = adj.size() , m = adj[0].size();
//     vis[row][col]=1;

//     for(int i=0;i<4;i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];

//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
//             islands(nrow,ncol,adj,vis,delrow,delcol);
//         }
//     }
// }
// int numIsland(vector<vector<char>> &adj){
//     int n = adj.size() , m = adj[0].size();
//     int cnt=0;
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(!vis[i][j] && adj[i][j]=='1'){
//                 cnt++;
//                 // islands(i,j,adj,vis,delrow,delcol);
//                 countIsland(i,j,adj,vis);
//             }
//         }
//     }
//     return cnt;
// }


// Flood Fill Algorithm // BFS // t.c o(n*m) S.C O(n*m)
// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
//     int n = image.size() , m = image[0].size();
//     int ini = image[sr][sc];
//     queue<pair<int,int>> q;
//     q.push({sr,sc});
//     image[sr][sc]=color;
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     vis[sr][sc]=1;    
//     while(!q.empty()){
//         auto it = q.front();q.pop();
//         int row = it.first , col = it.second;

//         for(int i=0;i<4;i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && !vis[nrow][ncol]){
//                 image[nrow][ncol]=color;
//                 vis[nrow][ncol]=1;
//                 q.push({nrow,ncol});
//             }
//         }
//     }
//     return image;
// }

// Rotten Oranges
// int rottenOranges(vector<vector<int>> adj){
//     int n = adj.size() , m = adj[0].size();
//     vector<vector<int>> vis(n,vector<int>(m,0));

//     queue<pair<pair<int,int>,int>> q;
//     int cntRotten = 0,cntFresh=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(adj[i][j]==2){
//                 q.push({{i,j},0});
//                 vis[i][j]=2;
//             }else if(adj[i][j]==1){
//                 cntFresh++;
//             }
//         }
//     }
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};

//     int tm = 0;
//     while(!q.empty()){
//         auto it = q.front();q.pop();
//         int x = it.first.first;
//         int y = it.first.second;
//         int time = it.second;
//         tm = max(tm,time);

//         for(int i=0;i<4;i++){
//             int row = x + delrow[i];
//             int col = y + delcol[i];

//             if(row>=0 && row<n && col>=0 && col<m && adj[row][col]==1 && !vis[row][col]){
//                 vis[row][col]=1;
//                 q.push({{row,col},time+1});
//                 cntRotten++;
//             }
//         }
//     }
//     if(cntFresh!=cntRotten) return -1;
//     return tm;
// }

// Cycle Detection using bfs
// T.C O(v+2*e) S.C O(v)
// bool detectCycle(vector<int> adj[],int src,int n,vector<int> &vis){
//     queue<pair<int,int>> q;
//     q.push({src,-1});
//     vis[src]=1;
//     while(!q.empty()){
//         auto it = q.front();q.pop();
//         int node = it.first;
//         int parent = it.second;

//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 q.push({it,node});
//             }else if(parent!=it){
//                 // visited but not parent
//                 return true;
//             }
//         }
//     }
//     return false;    
// }
// bool cycle(vector<int> adj[],int n){
//     vector<int> vis(n,0);
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(detectCycle(adj,i,n,vis)==true) return true;
//         }
//     }
//     return false;
// }

// Cycle detection using DFS
// T.C O(v+2e)+ O(v) S.C O(v)
// bool detect(int node,vector<int> adj[],int n,vector<int> &vis,int parent){
//     vis[node]=1;
//     for(auto it:adj[node]){
//         if(!vis[it]){
//             if(detect(it,adj,n,vis,node)==true) return true;
//         }
//         else if(parent!=it){
//             return true;
//         }
//     }
//     return false;
// }
// bool cycle(vector<int> adj[],int n){
//     vector<int> vis(n,0);
//     int parent = -1;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(detect(i,adj,n,vis,parent)==true) return true;
//         }
//     }
//     return false;
// }


// Distance of Nearest cell having 1
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
//     int n = mat.size(),m=mat[0].size();
//     vector<vector<int>> ans;
//     queue<pair<pair<int,int>,int>> q;
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(mat[i][j]==1) {
//                 ans[i][j] = 0;
//                 vis[i][j] = 1;
//                 q.push({{i,j},0});
//             }
//         }
//     }
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};
//     while(!q.empty()){
//         auto it = q.front();q.pop();
//         int x = it.first.first , y = it.first.second;
//         int t = it.second;
        
//         ans[x][y]=t;

//         for(int i=0;i<4;i++){
//             int nrow = x + delrow[i];
//             int ncol = y + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
//                 vis[nrow][ncol]=1;
//                 q.push({{nrow,ncol},t+1});
//             }
//         }
//     }
//     return ans;
// }

// surrounded regions
// void fill(int row,int col,vector<vector<char>> adj,vector<vector<int>> vis,int delrow[],int delcol[]){
//     int n = adj.size() , m = adj[0].size();
//     vis[row][col]=1;

//     for(int i=0;i<4;i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];

//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='O' && !vis[nrow][ncol]){
//             fill(nrow,ncol,adj,vis,delrow,delcol);
//         }
//     }

// }
// vector<vector<char>> surround(vector<vector<char>> adj){
//     int n = adj.size() ; int m = adj[0].size();
//     vector<vector<int>> vis(n,vector<int>(m,0));
    
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};

//     for(int j=0;j<m;j++){
//         if(adj[0][j]=='O' && !vis[0][j]){
//             fill(0,j,adj,vis,delrow,delcol);
//         }
//         if(adj[n-1][j]=='O' && !vis[n-1][j]){
//             fill(n-1,j,adj,vis,delrow,delcol);
//         }
//     }

//     for(int i=0;i<n;i++){
//         if(adj[i][0]=='O' && !vis[i][0]){
//             fill(i,0,adj,vis,delrow,delcol);
//         }
//         if(adj[i][m-1]=='O' && !vis[i][m-1]){
//             fill(i,m-1,adj,vis,delrow,delcol);
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(vis[i][j]!=1 && adj[i][j]=='O'){
//                 adj[i][j]=='X';
//             }
//         }
//     }
//     return adj;
// }

// No of enclaves
// void fill(int row,int col,vector<vector<char>> adj,vector<vector<int>> vis,int delrow[],int delcol[]){
//     int n = adj.size() , m = adj[0].size();
//     vis[row][col]=1;

//     for(int i=0;i<4;i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];

//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='O' && !vis[nrow][ncol]){
//             vis[nrow][ncol]=1;
//             fill(nrow,ncol,adj,vis,delrow,delcol);
//         }
//     }

// }
// int surround(vector<vector<char>> adj){
//     int n = adj.size() ; int m = adj[0].size();
//     vector<vector<int>> vis(n,vector<int>(m,0));
    
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};

//     for(int j=0;j<m;j++){
//         if(adj[0][j]=='O' && !vis[0][j]){
//             fill(0,j,adj,vis,delrow,delcol);
//         }
//         if(adj[n-1][j]=='O' && !vis[n-1][j]){
//             fill(n-1,j,adj,vis,delrow,delcol);
//         }
//     }

//     for(int i=0;i<n;i++){
//         if(adj[i][0]=='O' && !vis[i][0]){
//             fill(i,0,adj,vis,delrow,delcol);
//         }
//         if(adj[i][m-1]=='O' && !vis[i][m-1]){
//             fill(i,m-1,adj,vis,delrow,delcol);
//         }
//     }
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(vis[i][j]!=1 && adj[i][j]=='O'){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }


// No of Distinct islands
// void check(int row,int col,vector<vector<int>> &adj,vector<vector<int>> &vis,int delrow[],int delcol[],set<vector<pair<int,int>>> &st){
//     int n = adj.size() ; int m = adj[0].size();
//     vis[row][col]=1;
//     queue<pair<int,int>> q;
//     q.push({row,col});
//     vector<pair<int,int>> vec;
//     while(!q.empty()){
//         int x = q.front().first; int y = q.front().second;
//         q.pop();
//         vec.push_back({x-row,y-col});

//         for(int i=0;i<4;i++){
//             int nrow = x + delrow[i];
//             int ncol = y + delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && adj[nrow][ncol]==1){
//                 vis[nrow][ncol]=1;
//                 q.push({nrow,ncol});
//             }
//         }
//     }
// }
// int distinctIslands(vector<vector<int>> adj){
//     int n = adj.size() , m = adj[0].size();
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     int delrow[4]={-1,1,0,0};
//     int delcol[4]={0,0,-1,1};
//     set<vector<pair<int,int>>> st;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(!vis[i][j] && adj[i][j]==1){
//                 check(i,j,adj,vis,delrow,delcol,st);
//             }
//         }
//     }
//     return st.size();
// }


// Bipartite Graph
// T.C O(+2E) S.C O(V)
// bool dfs(int node,vector<int> adj[],vector<int> color){
//     for(auto it:adj[node]){
//         if(color[it]==-1){
//             color[it] = !color[node];
//             if(dfs(it,adj,color)==false) return false;
//         }else if(color[it]!=-1){
//             if(color[it]==color[node]) return false;
//         }
//     }
//     return true;
// }
// bool bfs(int start,vector<int> adj[],vector<int> &color){
//     queue<int>  q;
//     q.push(start);
//     color[start]=0;

//     while(!q.empty()){
//         int node =q.front();q.pop();
        
//         for(auto it:adj[node]){
//             if(color[it]==-1){
//                 color[it] = !color[node];
//                 q.push(it);
//             }else if(color[it]==color[node]){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool checkBipartite(vector<int> adj[],int n){
//     vector<int> color(n,-1);

//     for(int i=0;i<n;i++){
//         if(color[i]==-1){
//             color[i]=0;
//             if(dfs(i,adj,color)==false) return false;
//         }
//     }
//     return true;
// }

// Directed Graph Cycle detech
bool detect(int node,vector<int> adj[],int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            if(detect(it,adj,vis,pathVis)==true) return true;
        }else if(pathVis[it]==1){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}
bool detectCycle(vector<int> adj[],int n){
    int vis[n]={0};
    int pathVis[n]={0};

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(detect(i,adj,vis,pathVis)==true) return true;
        }
    }
    return false;
}

// Eventual safe State
bool detectSafe(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;

    for(auto it:adj[node]){
        if(!vis[it]){
            
            if(detectSafe(it,adj,vis,pathVis,check)==true){check[node]=0; return true;}
        }else if(pathVis[it]==1){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}
vector<int> Eventualsafe(vector<int> adj[],int n){
    int vis[n]={0};
    int pathVis[n]={0};
    int check[n]={0};

    for(int i=0;i<n;i++){
        if(!vis[i]){
            detectSafe(i,adj,vis,pathVis,check);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(check[i]==1) ans.push_back(i);
    }
    return ans;
}

// Topo
vector<int> Eventualsafe(vector<int> adjR[],int n){
    vector<int> adj[n];
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adjR[i]){
            adj[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();q.pop();

        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    sort(topo.begin(),topo.end());
    return topo;
}

// topo sort dfs
void topo(int node,int vis[],vector<int> adj[],stack<int> &st){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]) topo(it,vis,adj,st);
    }
    st.push(node);
}
vector<int> topoSort(vector<int> adj[],int n){
    stack<int> st;
    int vis[n]={0};
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,vis,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// Topological Sort BFS
vector<int> topoSort(vector<int> adj[],int n){
    int indegree[n]={0};

    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}

// course Schedule 1 
// Cycle Detection in Directed Graph using BFS
bool cycleDetect(vector<int> adj[],int n){
    int indegree[n]={0};

    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cnt++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(cnt!=n) return true;
    return false;
}

string alienDict(string dict[],int n,int k){
    vector<int> adj[k];
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j=0;j<min(s1.length(),s2.length());j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

    int indegree[k]={0};
    for(int i=0;i<k;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<k;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> temp;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        temp.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    string ans = "";
    for(int i=0;i<temp.size();i++) ans += (char)(temp[i]+'a');
    return ans;
}

// Shortest Path DAG
void topoSort1(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it.first]){
            topoSort1(it.first,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int n,int m,vector<vector<int>> &edges){
    vector<pair<int,int>> adj[n];

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
    }

    // step 1 topoSort // T.C O(n+n)
    int vis[n]={0};
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort1(i,adj,vis,st);
        }
    }

    // step 2 // T.C O(n+m)
    vector<int> dist(n);
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it:adj[node]){
            int v = it.first;
            int w = it.second;

            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
            }
        }
    }
    return dist;
}

// shortest path in DAG
vector<int> shortestDist(vector<int> adj[],int n,int src){
    int dist[n];
    for(int i=0;i<n;i++) dist[i]=INT_MAX;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int sr = q.front();
        q.pop();

        for(auto it:adj[sr]){
            if(dist[sr] + 1 < dist[it]){
                dist[it] = 1 + dist[sr];
                q.push(it);
            }
        }
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if(dist[i]!=INT_MAX){
            ans[i]=dist[i];
        }
    }
    return ans;
}

// word Ladder 1
int wordLader1(vector<string> &wordList,string startWord,string targetWord){
    queue<pair<string,int>> q;
    unordered_set<string> st;
    for(int i=0;i<wordList.size();i++){
        st.insert(wordList[i]);
    }
    q.push({startWord,1});
    st.erase(startWord);

    while(!q.empty()){
        auto it = q.front();q.pop();
        string word = it.first;
        int step = it.second;
        
        if(word==targetWord) return step;
        for(int i=0;i<word.size();i++){
            char orig = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,step+1});
                    st.erase(word);
                    break;
                }    
            }
            word[i]=orig;
        }
    }
    return 0;
}

// Dijkstra's Algorithm
// T.c O(e*log(v)) // S.C O(V) Priority queue
vector<int> dijkstraPQ(vector<vector<int>> adj[],int n,int sr){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,sr});
    vector<int> dist(n);
    dist[sr]=0;

    while(!pq.empty()){
        auto it1 = pq.top(); pq.pop();
        int node = it1.second;
        int dis = it1.first;

        for(auto it:adj[node]){
            int adjNode = it[0];
            int weight = it[1];

            if(dis + weight < dist[adjNode]){
                dist[adjNode]=dis+weight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

// T.C O(E*log(v)) S.C O(V) Set
vector<int> dijkstraSet(vector<vector<int>> adj[],int n,int sr){
    set<pair<int,int>> st;
    st.insert({0,sr});
    vector<int> dist(n,INT_MAX);
    dist[sr]=0;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it:adj[node]){
            int adjN = it[0];
            int wgh = it[1];

            if(dis + wgh < dist[adjN]){

                if(dist[adjN]!=INT_MAX){
                    st.erase({dist[adjN],adjN});
                }
                dist[adjN] = dis + wgh;
                st.insert({dist[adjN],adjN});
            }
        }
    }
    return dist;
}

// Print shortest Path
vector<int> shortestPath(vector<vector<int>> adj[],int n,int dest){
    vector<int> dist(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dist(n+1,INT_MAX),parent(n+1);

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    dist[1]=0;
    while(!pq.empty()){
        int node = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjN = it[0];
            int wgh = it[1];

            if(wgh + val < dist[adjN]){
                dist[adjN] = wgh + val;
                pq.push({dist[adjN],adjN});
                parent[adjN] = node;
            }
        }
    }

    if(dist[n]==INT_MAX) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
};

// Shortest Distnace in a Binary Maze
int shortestPathMaze(vector<vector<int>> &grid, pair<int,int> sr, pair<int,int> dest){
    int n = grid.size() , m = grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    q.push({0,sr});
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[sr.first][sr.second]=1;

    int delrow[4]={-1,1,0,0} , delcol[4]={0,0,-1,1};
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int dis = it.first; int x = it.second.first;int y = it.second.second;

        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dis + 1 < dist[nrow][ncol]){
                dist[nrow][ncol]= dis + 1;
                q.push({dist[nrow][ncol],{nrow,ncol}});
                if(x==n-1 && y==n-1){
                    return dis + 1;
                }
            }
        }
    }
    return -1;
}

// Path with Minimum Efforts
int MinimumEfforts(vector<vector<int>> &adj){
    int n = adj.size(), m = adj[0].size();
    int miniEfforts = INT_MAX;
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    dist[0][0]=1;

    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};

    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        int dis = it.first;
        int x = it.second.first;
        int y = it.second.second;

        if(x==n-1 && y==m-1) return dis;

        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int val = max(abs(adj[nrow][ncol]-adj[x][y]),val);
                if(val < dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}

// Cheapest Flights with k stops
int CheapestFlight(int n,vector<vector<int>> &flights,int src,int dst,int k){
    vector<vector<int>> adj[n];
    for(int i=0;i<flights.size();i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        adj[u].push_back({v,w});
    }
    vector<int> dist(n,INT_MAX);
    queue<pair<int,pair<int,int>>> pq;
    // k , node , dis
    pq.push({0,{0,0}});

    while(!pq.empty()){
        auto it = pq.front();pq.pop();
        int stop = it.first;
        int node = it.second.first;
        int dis = it.second.second;

        if(stop>k) continue;
        for(auto it:adj[node]){
            int adjN = it[0];
            int wegh = it[1];

            if(dis + wegh < dist[adjN] && stop<=k){
                dist[adjN]=dis + wegh;
                pq.push({stop+1,{adjN,dist[adjN]}});
            }
        }
    }

    if(dist[dst]==INT_MAX) return -1;
    return dist[dst];
}

int countWays(int n,vector<vector<int>> &roads){
    vector<pair<int,int>> adj[n];
    for(int i=0;i<roads.size();i++){
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int dist[n]={INT_MAX};
    int ways[n]={0};
    pq.push({0,0});
    int mod = 1e9;

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int adjN = it.first;
            int wgh = it.second;

            if(dis + wgh < dist[adjN]){
                dist[adjN]=dis+wgh;
                pq.push({dist[adjN],adjN});
                ways[adjN] = ways[node];
            }else if(dis + wgh == dist[adjN]){
                ways[adjN] = (ways[adjN]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}

// Minimum Multiplication to reach the end
int minimumMulti(vector<int> &adj,int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dist(1e5,INT_MAX);
    int mod = 1e8;

    while(!q.empty()){
        int node = q.front().first;
        int step = q.front().second;
        q.pop();

        for(int i=0;i<adj.size();i++){
            int num = (node*adj[i]) %mod;
            if(step+1 < dist[num]){
                dist[num] = step+1;
                if(num==end) return step+1;
                q.push({num,dist[num]});
            }
        }
    }
    return -1;
}

// Bellman Ford Algorithm
vector<int> bellmenFord(int V,vector<vector<int>> &edges,int sr){
    vector<int> dist(V,1e8);
    for(int i=0;i<V-1;i++){
        dist[i]=0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] !=1e8 && dist[u]+w<dist[v]){
                dist[v]= dist[u] + w;
            }
        }
    }

    for(auto it:edges){
        int u = it[0],v=it[1],w=it[2];
        if(dist[u]!=1e8 && dist[u]+w<dist[v]) return {-1};
    }
    return dist;
}

// Floyd Warshell Algorithm
void shortestPath(vector<vector<int>> &matrix){
    int n = matrix.size() , m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=1e9;
            }
            if(i==j) matrix[i][j]=0;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        if(matrix[i][i]<0) return ;// negative cycle
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1e9) matrix[i][j]=-1;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    // Undirected Graph

    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    return 0;
}