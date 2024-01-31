#include<bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm
// NOT APPLICABLE FOR NEGATIVE WEIGHT & CYCLE
// 1.->  because it give circular loop and in pq negative degree come first and always loop give wrong ans.
// 2.-> from given source node find shortest path distance of all other nodes.
// 3.-> 2 Method :- priority Queue  , Set
// optimal :- Set > PQ > Q

// WHY PQ -> minimal first as their are to many unneccesary paths.
// T.c O(e*log(v)) -> heap size and loops
// intution behind dijkstra algorithm 
// ------------------------------
// Case 1 :- Priority Queue
// 1. min heap(shortest dist at top) and dist array(store shortest distance),source node 
// T.C O(E* log(V))
vector<int> dijkstraPQ(vector<vector<int>> adj[],int n,int sr){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[sr]=0;
    pq.push({0,sr});

    while(!pq.empty()){
        int node = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(val + edgeWeight < dist[adjNode]){
                    dist[adjNode] = val + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

// Case 2 :- Set (unique and smallest at top,ascending order)
// If we get short distance for that node we delete already exsiting part. (erase)->(log operation) but pq iterate all cases.
vector<int> dijkstraSet(vector<vector<int>> adj[],int n,int sr){
    set<pair<int,int>> st;
    vector<int> dist(n);
    for(int i=0;i<n;i++) dist[i] = INT_MAX;
    st.insert({0,sr});
    dist[sr]=0;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it:adj[node]){
            int adjNode = it[0];
            int weight = it[1];

            if(dis + weight < dist[adjNode]){
                // erase if it exsited
                if(dist[adjNode] != INT_MAX){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis + weight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
    
}

// Print shortest Path
// print the nodes come in path to travel all the node with minimum value.
// if no path then return -1
// It is done by backtracting where i am comin from in dijkstra's
// T>C O(E*log(V)) + O(N) S.C O(N)
vector<int> shortestPath(vector<vector<int>> adj[],int n,int dest){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dist(n+1);
    for(int i=0;i<n+1;i++){
        dist[i]=INT_MAX;
    }
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;
    dist[1]=0;
    while(!pq.empty()){
        int node = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(val + edgeWeight < dist[adjNode]){
                dist[adjNode] = val + edgeWeight;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if(dist[n]==1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}

// Shortest Distancee in a Binary Maze
// In a matrix you have give src and dest points and you have to return tha minimum dist you can only traverse through 1's
// from i cell to other cell dist is 1 four directions
// In this we dont need the priority_queue because qi=ueue also store in increasing manner
int shortestPathMaze(vector<vector<int>> &grid, pair<int,int> sr, pair<int,int> dest){
    int n = grid.size(),m = grid[0].size();
    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    queue<pair<int,pair<int,int>>> pq;
    pq.push({0,sr});
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[sr.first][sr.second] = 0;

    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};
    int ans = 0;
    while(!pq.empty()){
        auto it = pq.front();
        int val = it.first;
        int x = it.second.first;
        int y = it.second.second;
        pq.pop();
        
        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && val + 1 < dist[nrow][ncol]){
                dist[nrow][ncol] = val + 1;
                if(x==dest.first && y==dest.second){
                    return val + 1;
                }
                pq.push({dist[nrow][ncol],{nrow,ncol}});
            }
        }
    }
    return -1;
}

// Path with Minimum Efforts
// in 2-d arraay you have to go from 0,0 to bottom right
// you have to find route that requires minimum efforts,
// a route efforts is the maximum absolute difference in heights btw two consecutive cells of the route.
// T.C O(E*log(V)) -> (n*m*4*log(n*m))
int MinimumEfforts(vector<vector<int>> &adj){
    int n = adj.size(),m=adj[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    dist[0][0]=1;

    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};
    // int ans = INT_MAX;
    while(!pq.empty()){
        auto it = pq.top();
        int diff = it.first;
        int x = it.second.first;
        int y = it.second.second;
        pq.pop();

        if(x==n-1 && y==m-1) return diff;

        for(int i=0;i<4;i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int val = max(abs(adj[x][y] - adj[nrow][ncol]),diff);
                if( val < dist[nrow][ncol]){
                    dist[nrow][ncol] = val;
                    pq.push({val,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}

// Cheapest Flights Within K Stops
// flight stops are given and price you have to find minimum cost to reach source to destination
// atmost K stops if no root return -1, middle points consider as stops not sr and dest

// In this priority queue not work because as it choose minimum but in this we also want to see atmost k stops not more.

// so we have to do on the basis of stops. by simple queue, dont stop if we reach destination.
// T.C O(E)=flight.size()
int CheapestFlight(int n,vector<vector<int>> flight,int src,int dst,int k){
    vector<pair<int,int>> adj[n];
    for(auto it:flight){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    vector<int> dist(n);
    for(int i=0;i<n;i++) dist[i]=INT_MAX;
    dist[src]=0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops>k) continue;
        for(auto itr:adj[node]){
            int adjNode = itr.first;
            int edW = itr.second;
            
            if(cost + edW < dist[adjNode] && stops<=k){
                dist[adjNode] = cost + edW;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }
        }   
    }

    if(dist[dst]==INT_MAX) return -1;
    return dist[dst];
}

// Minimum Multiplications to Reach End
// you have give start number you can multiply any number from array and reach the end from it.find minimum 
// multiplication under modulo 1e5.
// Node nnumbers are 1e5-1
// T.C O(100000 * N) 
int minimumMultiplications(vector<int> adj,int start,int end){
    queue<pair<int,int>> pq;
    pq.push({0,start});
    vector<int> dist(1e5,INT_MAX);
    int mod = 1e5;
    while(!pq.empty()){     
        int steps = pq.front().first;
        int node = pq.front().second;
        pq.pop();

        for(auto it:adj){
            int num = (it*node) % mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if(num == end) return steps +1 ;
                pq.push({steps+1,num});
            }
        }
    }
    return -1;
}

// Number of Ways to Arrive to Destination
// Undirected Graph
// nodes and time to travel , how many way we can reach from source to destination int minimum time. 
// we can not say answer is all the path to dest it also depend on its parent dest 
// T.C O(n*log(v))
int countPaths(int n,vector<vector<int>> &roads){
    vector<pair<int,int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

 vector<int> ways(n,0),dist(n,INT_MAX);
 dist[0]=0;
 ways[0]=1;
 pq.push({0,0});
    int mod = 1e5;
 while(!pq.empty()){
    int dis = pq.top().first;
    int node = pq.top().second;

    for(auto it:adj[node]){
        int adjNode = it.first;
        int edgW = it.second; 

        // this is the first time i am coming
        // with this short dist
        if(dis + edgW < dist[adjNode]){
            dist[adjNode] = dis + edgW;
            pq.push({dis + edgW,adjNode});
            ways[adjNode] = ways[node];
        }
        else if(dis + edgW == dist[adjNode]){
            ways[adjNode] = ways[adjNode] + ways[node] % mod;
        }
    }
 }
 return ways[n-1] % mod;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    return 0;
}