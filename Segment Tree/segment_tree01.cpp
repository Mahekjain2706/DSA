#include<bits/stdc++.h>
using namespace std;

// Segment Tree
// given an array of n elements, we have to perform two types of queries
// 1. update the value of an element at index i to x
// 2. find the sum of elements in the range [l, r]

// first approach is to use a simple array to store the elements
// and then perform the queries in O(n) time for sum
// and O(1) time for update

// second approach is to prefix sum array
// 1. and then perform the queries in O(1) time for sum ,
// so for finding the sum of elements in the range [l, r] , we can simply return prefix[r] - prefix[l-1]
// 2. and O(n) time for update.

// third approach is to use segment tree
// 1. and then perform the queries in O(logn) time for sum
// 2. and O(logn) time for update.

// Given Array : 5 3 2 4 1 8 6 10

// Power of number 2 in Programming :-
// Binary representation of numbers -> benefit - all the operations be it sum / subtration / product ,are done in O(1) time.
// Division of Array  ->  divide and conquer
// 5 3 2 4 1 8 6 10 -> left half -> 5 3 2 4 -> right half -> 1 8 6 10
// Number of nodes =  n + n/2 + n/4 + n/8 + .... + 1 = 2n - 1-> G.P -> cmmon ratio = 1/2
// let , number of terms as x , a* pow(r, x-1) = 1 -> 2n = 2^x -> x = log2(n) + 1 -> height of the tree
// for odd number of elements , we can add 0 to the array to make it even 
// we make segment tree of size 2 * 2^x = 2 * 2^(log2(n) + 1) = 4n

// segment tree for the given array
//                    49 
//          14                    35 
//      5        9         16          19 
//   5    3    2    4    1    8     6      10

// root node represent the sum of all the elements in the array
// left child of a node represent the sum of elements in the left half of the array
// right child of a node represent the sum of elements in the right half of the array
// and so on

// divide and conquer

const int N = 1e5 + 2;
int a[N], tree[4*N];

// build the segment tree
// start and end of segemnt tree
void build(int node,int start,int end)
{
    if(start == end){
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    // left child
    build(2*node, start, mid);
    // right child
    build(2*node+1,mid+1,end);

    // for sum of element find we take this.
    tree[node] = tree[2*node] + tree[2*node+1];

    // for max element find we take this.
    // tree[node] = max(tree[2*node], tree[2*node+1]);
}


int main(){ 

    int n;
    cin>> n;
    
    for(int i=0;i<n;i++) cin>>a[i];

    build(1,0,n-1);
    for(int i=1;i<4*n;i++) cout<<tree[i]<<" ";
    return 0;
}