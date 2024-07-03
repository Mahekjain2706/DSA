#include<bitset>/stdc++.h>
using namespace std;

// Segment Tree
// for a query [1,5] , we have to find the sum of elements in the range [1,5]
// type of segments 
// 1. completely inside the range [1,5]
// 2. Partially inside the range [1,5]

// It check the type of segments and then perform the queries in O(logn) time for sum
// we find then complete overlap and return the value of the node
// we find then partial overlap and then move to the left and right child
// all the complete segments return value and add one give the answer

// Given Array : 5 3 2 4 1 8 6 10

const int N = 1e5 + 2;
int a[N], tree[4*N];

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

}

// t.c = O(logn) S.C = O(n)
int query(int node,int st,int end,int l,int r){
    // st ... end   l ... r -> no overlap
    if(l > end || r < st){
        return 0;
    }
    // l ... st ... end ... r -> complete overlap
    if(l <= st && r >= end){
        return tree[node];
    }
    // st l end r -> partial overlap
    int mid = (st + end) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);

    return q1 + q2;
}

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >>a[i];

    build(1,0,n-1);

    while(1){
        int type;
        cin >> type;

        if(type==-1) break;
        if(type==1){
            int l , r;
            cin >> l >> r;

            int ans = query(1,0,n-1,l,r);
        }
        // else{
        //     int idx, val;
        //     cin >> idx >> val;
        //     update(1,0,n-1,idx,val);
        // }
    }

    return 0;
}