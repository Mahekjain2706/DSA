#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

// for max element find we take this.
// given array 6 8 -1 2 17 1 3 2 4
// segment tree for the given array

//                                   17(0,8)
//                   17(0,4)                          4(5,8)
//           8(0,2)          17(3,4)          3(5,6)          4(7,8)
//      8(0,1)  -1(2,2)   2(3,3)  17(4,4)  1(5,5)  3(6,6)  2(7,7)  4(8,8)
// 6(0,0)  8(1,1)


// Query 
// we find the compeltely overlapping nodes and partially overlapping nodes
// completely overlapping nodes -> return the value of the node
// partially overlapping nodes -> move to the left and right child
// all the completely overlapping nodes return value and max one give the answer

const int N = 1e5 + 2;
int a[N], tree[4*N];
int query(int node,int st,int end,int l,int r){
    // st ... end   l ... r -> no overlap
    if(l > end || r < st){
        return INT_MIN;
    }
    // l ... st ... end ... r -> complete overlap
    if(l <= st && r >= end){
        return tree[node];
    }
    // st l end r -> partial overlap
    int mid = (st + end) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);

    return max(q1, q2);
}

// Update
// put a[7] = 18
// check where 7 lies in the segment tree , left or right
// move to the left or right child
// update the value of the node and then update the parent node , backtracking
void update(int node,int st,int end,int idx,int val){
    if(st == end)
    {
        a[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + end) / 2;
    // left child
    if(idx <= mid){
        update(2*node, st, mid, idx, val);
    }
    // right child
    else{
        update(2*node+1, mid+1, end, idx, val);
    }
    

    tree[node] = max(tree[2*node], tree[2*node+1]);
}

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

    // for max element find we take this.
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int main(){
    int n;
    cin>> n;

    for(int i=0;i<n;i++) cin>>a[i];

    build(1,0,n-1);
    while(1){
        int type;
        cin >> type;

        if(type==-1) return;
        if(type==1){
            int l,r;
            cin >> l >> r;
            cout << query(1,0,n-1,l,r) << endl;
        }
        else{
            int idx,val;
            cin >> idx >> val;
            update(1,0,n-1,idx,val);
            cout << query(1,0,n-1,0,n-1) << endl;
        }
    }

    return 0;
}