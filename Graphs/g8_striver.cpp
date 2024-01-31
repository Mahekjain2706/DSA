#include<bits/stdc++.h>
using namespace std;

// Bipartite Graph
// color the graph with 2 colors such that no adjacent nodes have same color.

// lInear graph with no cycle is always bipartite.
// Any graph with even cycle length is also bipartite
// Any graph with ODD Length cycle it is NOT Bipartite .

// BFS
// T.c (V+2E) S.c o(V)
bool check(int start,vector<int> adj[],int n,vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
            }
            else if(color[it]!=-1){
                if(color[it]==color[node]) return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[],int n){
    // colors are 0 and 1
    // bfs
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check(i,adj,n,color)==false) return false;
        }
    }
    return true;
}

// DFS
// T.C O(V+2E) S.C O(V)
bool dfsCheck(int start,vector<int> adj[],int color[],int n,int ini){
    color[start] = !ini;
    for(auto it:adj[start]){
        if(color[it]==-1){
            dfsCheck(it,adj,color,n,color[it]);
        }
        else if(color[it]==ini) return false;
    }
    return true;
}
bool bipartiteCheck(vector<int>adj[],int n){
    int color[n];
    for(int i=0;i<n;i++) color[i] = -1;

    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(dfsCheck(0,adj,color,n,0)==false) return false;
        }
    }
    return true;
}

// Directed Graph Cycle detech
// T.C O(V+E) S>C O(E)
bool dfsDirected(int node,vector<int> adj[],int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;

    // traverse for adjacent node
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsDirected(it,adj,vis,pathVis)==true) return true;
        }
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}
bool isCycle(vector<int> adj[],int n){
    int vis[n] = {0};
    int pathVis[n] = {0};

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfsDirected(i,adj,vis,pathVis)==true) return true;
        }
    }
    return false;
}

// Eventual safe states
// detech the node which make the cycle is not safe else it is safe node
// any one who is a part of cycle can not be safe node
// any one leads to a cycle can not be safe node
// S.C O(3*n)=>O(n)  
// DFS
bool dfsCheckN(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;
    // traverse for adjacent node
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsCheckN(it,adj,vis,pathVis,check)==true){ 
                check[node]=0;
                return true;}
        }
        else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}
vector<int> safeState(vector<int> adj[],int n){
    int vis[n] = {0};
    int pathVis[n] = {0};
    int check[n] = {0};

    vector<int> safeNode;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsCheckN(i,adj,vis,pathVis,check);
        }
    }
    for(int i=0;i<n;i++){
        if(check[i]==1) safeNode.push_back(i);
    }
    return safeNode;
}
// OR
// BFS
// All terminal nodes are safe nodes (indegree=0)
// 1. reverse all the edges direction 
// 2. topo sort , and do removal of edges on adjacent nodes
// T.C O(n*logn)*O(V+E)   S.C O(N)
vector<int> eventualSafe(vector<int> adj[],int n){
    vector<int> adjRev[n];
    int indegree[n] = {0};
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
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
        for(auto it:adjRev[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    sort(topo.begin(),topo.end());
    return topo;
}

// Topological Sorting (dfs)
// Directed Acyclic Graph (DAG)
// Linear ordering of vertices that if there is an edge between u & v,u appers before v in that ordering.
// T.C O(V+E) S.C O(n)
void dfsSort(int node,stack<int>&st,vector<int>adj[],int vis[]){
    vis[node]=1;
    
    for(auto it:adj[node]){
        if(!vis[it]) dfsSort(it,st,adj,vis);
    }
    st.push(node);
}
vector<int> topoSort(vector<int> adj[],int n){
    int vis[n]={0};
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsSort(i,st,adj,vis);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// Topological Sort (Bfs)
// Kahn's Algorithm & Directed Acyclic Graph (DAG)
// Linear ordering of vertices that if there is an edge between u & v,u appers before v in that ordering.
// T.C O(v+e) S.C O(n)
vector<int> topoSortB(vector<int> adj[],int n){
    int inDegree[n]={0}; // no of incoming edges
    queue<int> q;
    // 1. insert all node with indegree 0 in queue.
    // 2. continue check and push when indegree of node become 0
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }

    for(int i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<int> top;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        top.push_back(node);

        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0) q.push(it);
        }
    }
    return top;
}

// Cycle Detection in Directed Graph using BFS
// No backtracking so we use kahn's algorithm
bool cycleDirectedBfs(vector<int> adj[],int n){
    int inDegree[n]={0}; // no of incoming edges
    queue<int> q;
    // 1. insert all node with indegree 0 in queue.
    // 2. continue check and push when indegree of node become 0
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }

    for(int i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0) q.push(it);
        }
    }
    if(cnt==n) return false;
    return true;
}


// Course Schedule 1 and 2 
bool cycleDirectedBfs(vector<int> adj[],int n){
    int inDegree[n]={0}; // no of incoming edges
    queue<int> q;
    // 1. insert all node with indegree 0 in queue.
    // 2. continue check and push when indegree of node become 0
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }

    for(int i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0) q.push(it);
        }
    }
    if(topo.size()==n) return true;
    return false;
}

// Alien Dictionary
// wrong dictionary :- if largest string match small string ex:- abcd  abc  OR cycle present .
string alienDict(string dict[],int n,int k){
    vector<int> adj[k];
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());
        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
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
    
    vector<int> seq;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        seq.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    string ans = "";
    for(auto it:seq){
        ans = ans + char(it + 'a');
    }
    return ans; 
}


int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adj[n];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    
    return 0;
}