#include<bitset>/stdc++.h>
using namespace std;

// Union Set
// Suppose we have n elements and we have to perform two operations
// 1. Union: Combine two sets
// 2. Find: Find the set to which the element belongs
// We can use Union Set to perform these operations in O(logn) time
// We can use Union Set to find the number of connected components in a graph
// Suppose we have 0-7 numbers and we need to perform operations like make friends and are friends.
// With the help of Union Set, we can find the number of friends in O(logn) time

// Implementation
// We define a parent array of size n and initialize it with its own index which store root .
// We define a rank array of size n and initialize it with 0 which store the height of the tree.
// We define a function find which takes an element and returns the root of the element.


// "Union by Rank"
// To optimize the function we use Rank 
// In rank we always attach the smaller tree to the larger tree by seeing rank

int parent[1001]={0};
int rank[1001]={0};
void initialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
};
// T.C: O(logn) // normal method
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return find(parent[x]);
}
void unionA(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px==py){
        return;
    }
    if(rank[py]<rank[px]){
        parent[py]=px;
    }
    else if(rank[px]<rank[py]){
        parent[px]=py;
    }
    else{
        parent[px]=py;
        rank[py]++;
    }
}
 // 0 1 2 3 4 5 6 7.  Parent Array
 // 0 1 2 3 4 5 6 7
 // 0 1 0 3 4 5 6 7. After union(0,2)
 // 0 1 0 3 3 5 6 7. After union(3,4)
 // 0 1 0 0 3 5 6 7. After union(2,4)
 //  5 1  0 0 3 5 6 7. After union(5,4)

// Path Compression
// In the above implementation, we have to traverse the path to find the root of the element.
int parent[1001]={0};
int rank[1001]={0};
void initialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
};

// T.C: O(logn) for n operations
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unionA(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px==py){
        return;
    }
    if(rank[py]<rank[px]){
        parent[py]=px;
    }
    else if(rank[px]<rank[py]){
        parent[px]=py;
    }
    else{
        parent[px]=py;
        rank[py]++;
    }
}

int main(){
    int n;
    cin>>n;
    initialize(n);
    unionA(0,2);
    unionA(3,4);
    unionA(2,4);
    unionA(5,4);
    return 0;
}