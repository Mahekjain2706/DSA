#include<bitset>/stdc++.h>
using namespace std;

// Kruskal's Algorithm
// find minimum spanning tree for a connected, undirected graph
// By Union-Find Algorithm
// 1. Sort all the edges in non-decreasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.

// Example: [wt,u,v]
// Input: [1,4,1], [2,1,2],[3,2,3],[3,2,4],[4,1,5],[5,3,4],[7,2,6],[8,3,6],[9,4,5]
// tot_weight = 0;
// check ultimate parent of u and v 
// [1 4 1] 1->4 wt=1 tot_weight=1
// [2 1 2] 1->2 wt=2 tot_weight=3
// [3 2 3] 2->3 wt=3 tot_weight=6
// [3 2 4] already connected , not taken
// [4 1 5] 1->5 wt=4 tot_weight=10
// [5 3 4] already connected , not taken
// [7 2 6] 2->6 wt=7 tot_weight=17
// [8 3 6] already connected , not taken
// [9 4 5] already connected , not taken
// Output: 17
#include <vector> // Include the <vector> header file

class DSU{
    public:
    

    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int n){
        if(parent[n]==n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int a,int b){
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);

        if(ulp_a==ulp_b) return;
        else if(ulp_a<ulp_b){
            parent[ulp_a] = ulp_b;
        }
        else if(ulp_a>ulp_b){
            parent[ulp_b] = ulp_a;
        }
        else{
            parent[ulp_a] = ulp_b;
            rank[ulp_b]++;
        }
    }
};
// T.C O(n+e+e*log(e)) = O(e*log(e))
// S.C O(n)
int spanningTree(int v, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<v;i++){ // O(n*e)
        for(auto x: adj[i]){
            edges.push_back({x[1],{i,x[0]}});
        }
    }
    // O(e*log(e))
    sort(edges.begin(),edges.end());
    int mst_wt = 0;
    DSU dsu(v);
    // O(e * 4 * alpha(n)*2) = O(e)
    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(dsu.findParent(u)!=dsu.findParent(v)){
            mst_wt+=wt;
            dsu.unionByRank(u,v);
        }
    }
    return mst_wt;
}