// suppose you have two sets A and B. You have to perform the following operations:
#include <bits/stdc++.h>
using namespace std;
#include <vector>


// Brute force approach
// DFS traversal in both the set and find that two elements belong to the same set or not.
// Time complexity: O(n+e) linear time

// Efficient approach - Disjoint Set Union (DSU)
// Time complexity: O(1) for all operations
// Dynamic Graph Connectivity Problem
// 1. Union: Join two sets A and B. - By Rank and Path Compression
// 2. Find: Find the representative of the set to which an element belongs.
// 3. Check: Check whether two elements belong to the same set or not.
 

// DSU implementation
// Rank: Height of the tree   [0, 0, 0, 0, 0, 0, 0]
// Parent: Parent of the node [1, 2, 3, 4, 5, 6, 7]

// Union (u,v) 
// 1. Find the ultimate parent of u and v (pu, pv)
// 2. find rank of ultimate parent of u and v
// 3. Connect smaller rank tree to the larger rank tree always

// Union (1,2)  
// parent [1, 1, 3, 4, 5, 6, 7]
// rank   [1, 0, 0, 0, 0, 0, 0]

// Union (2,3)
// parent [1, 1, 1, 4, 5, 6, 7]
// rank   [1, 0, 0, 0, 0, 0, 0]

// Union (4,5)
// parent [1, 1, 1, 4, 4, 6, 7]
// rank   [1, 0, 0, 1, 0, 0, 0]

// Union (6,7)
// parent [1, 1, 1, 4, 4, 6, 6]
// rank   [1, 0, 0, 1, 0, 1, 0]

// Union (5,6)
// parent [1, 1, 1, 4, 4, 4, 6]
// rank   [1, 0, 0, 2, 0, 1, 0]

// Union (3,7)
// parent [4, 1, 1, 4, 4, 4, 4]
// rank   [1, 0, 0, 2, 0, 1, 0]

// T.C O(4*alpha(n)) = O(4) = O(1) where alpha(n) is the inverse Ackermann function
class DSU
{
    vector<int> parent, rank, size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.ersize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node==parent[node]){
             return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int a,int b){
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);

        if(ulp_a==ulp_b) return;
        if(rank[ulp_a] < rank[ulp_b]){
            parent[ulp_a] = ulp_b;
        }
        else if(rank[ulp_a] > rank[ulp_b]){
            parent[ulp_b] = ulp_a;
        }
        else{
            parent[ulp_a] = ulp_b;
            rank[ulp_b]++;
        }
    }

    void unionBySize(int a,int b){
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);

        if(ulp_a==ulp_b) return;
        if(size[ulp_a] < size[ulp_b]){
            parent[ulp_a] = ulp_b;
            rank[ulp_b] += rank[ulp_a];
        }
        else{
            parent[ulp_b] = ulp_a;
            size[ulp_a] += size[ulp_b];
        }
    
    }
};
// why connect smaller to larger ?
// because if we connect larger to smaller then the height of the tree will increase and 
// it will take more time to find the parent of the node.

// Union By size
// size = [1, 1, 1, 1, 1, 1, 1]
// parent = [1, 2, 3, 4, 5, 6, 7]

// Union (1,2)
// size = [2, 1, 1, 1, 1, 1, 1]
// parent = [1, 1, 3, 4, 5, 6, 7]

// Union (2,3)
// size = [3, 1, 1, 1, 1, 1, 1]
// parent = [1, 1, 1, 4, 5, 6, 7]

// Union (4,5)
// size = [3, 1, 1, 2, 1, 1, 1]
// parent = [1, 1, 1, 4, 4, 6, 7]

// Union (6,7)
// size = [3, 1, 1, 2, 1, 2, 1]
// parent = [1, 1, 1, 4, 4, 6, 6]

// Union (5,6)
// size = [3, 1, 1, 4, 1, 2, 1]
// parent = [1, 1, 1, 4, 4, 4, 6]

// Union (3,7)
// size = [3, 1, 1, 7, 1, 2, 1]
// parent = [1, 1, 1, 4, 4, 4, 4]



int main()
{
    int n;
    cin >> n ;
    DSU dsu(n);
    dsu.unionByRank(1,2);
    dsu.unionByRank(2,3);
    dsu.unionByRank(4,5);
    dsu.unionByRank(6,7);
    dsu.unionByRank(5,6);
    // if 3 and 7 same set or not
    if(dsu.findParent(3)==dsu.findParent(7)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    dsu.unionByRank(3,7);
    if(dsu.findParent(3)==dsu.findParent(7)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}