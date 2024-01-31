#include<bits/stdc++.h>
using namespace std;

// -----------------------
// MINIMUM SPANNING TREE
// A tree in which we have n nodes and n-1 edges and all nodes are reachable from each other.
// any tree with minimum sum is mst
// 2 Algorithm :- Prims Algorithm and Krushkal Algorithm


// 1. Prim's Algorithm 
// put any node as intiallization in pq as (weight,node,parent) , make vis array, sum variable and list of apir to store node in mst.
// check element in mst and see it is present se its adj if not visit put into prioirity queue minimum con=me mark vis and put into list and add weight as sum.
// if node is already vis then dont add into mst.
// if parent is -1 and dist is 0 means intial node not add into mst list. 
// print nodes
// greedy type // T.C O(E*Log(E) + E*log(E)) S.C O(V)
map<int,int> spanningTree(int V,vector<vector<int>> adj[]){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(V,0);
    pq.push({0,{0,-1}});
    map<int,int> mp;
    int sum =0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dist = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(parent!=-1 && mp.find(parent)==mp.end()){
            mp[parent] = node;
        }
        
        if(vis[node]==1) continue;
        vis[node] = 1;
        sum += dist;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]){
                pq.push({edW,{adjNode,parent}});
            }
        } 
    }
    return mp;
}
// print sum
int spanningTree1(int V,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    pq.push({0,0});
    int sum =0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dist = it.first;
        int node = it.second;

        if(vis[node]==1) continue;
        vis[node] = 1;
        sum += dist;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]){
                pq.push({edW,adjNode});
            }
        } 
    }
    return sum;
}

// ---------------------------------------
// DISJOINT SET 
// if graph has components then to determine if two nodes present in same component aor not then we use disjoint set 
// if we use dfs or bfs it take V*log(E) which is brute force solution.
// to find it in contant time we can use disjoint set
// it is used in Dynamic Graph
// uses :- findParent() , Union()->rank->size

// Unioin By rank
// assign rank array witrh n node as 0 , and parent array initialize each with itself.
// 1.find ultimate parent of u , v , pu , pv
// 2. find rank of pu , pv
// 3. Connect smaller rank to larger rank always.
// 4. if rank is same then connect anyone with other one.


int main(){
    return 0;
}