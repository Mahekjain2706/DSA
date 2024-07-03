#include<bits/stdc++.h>
using namespace std;



// with the minimum we also need to count number of time that minimum element is present in the given range
// so we need to store the count of the minimum element in the given range

// 1. 1 i r -> update the value of a[i] to r
// 2. 2 l r -> find the number of minimum of element in the range l to r-1

const int N = 1e5 + 2;
int a[N] ;
pair<int,int> tree[4*N]; // first element is the minimum element and second element is the count of the minimum element

pair<int,int> query(int node,int st,int end,int l,int r){
    // st ... end   l ... r -> no overlap
    if(l > end || r < st){
        pair<int,int> p;
        p.first = INT_MAX;
        p.second = -1;
        return p;
    }
    // l ... st ... end ... r -> complete overlap
    if(l <= st && r >= end){
        return tree[node];
    }
    // st l end r -> partial overlap
    int mid = (st + end) / 2;
    pair<int,int> q1 = query(2*node, st, mid, l, r);
    pair<int,int> q2 = query(2*node+1, mid+1, end, l, r);
    pair<int,int> q;

    if(q1.first < q2.first){
        q = q1;
    }
    else if(q2.first < q1.first){
        q = q2;
    }
    else{
        q.first = q1.first;
        q.second = q1.second + s2.second;
    }
    return q;
}

void update(int node,int st,int end,int idx,int val){
    if(st == end)
    {
        a[idx] = val;
        tree[node].first = val;
        tree[node].second = 1;
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
    

    if(tree[node*2].first == tree[node*2+1].first){
        tree[node].first = tree[node*2].first;
        tree[node].second = tree[node*2].second + tree[node*2+1].second;
    }
    else if(tree[node*2].first < tree[node*2+1].first){
        tree[node].first = tree[node*2].first;
        tree[node].second = tree[node*2].second;
    }
    else{
        tree[node].first = tree[node*2+1].first;
        tree[node].second = tree[node*2+1].second;
    }
}

void build(int node,int start,int end)
{
    if(start == end){
        tree[node].first = a[start];
        tree[node].second = 1;
        return;
    }
    int mid = (start + end) / 2;
    // left child
    build(2*node, start, mid);
    // right child
    build(2*node+1,mid+1,end);

    // for max element find we take this.
    if(tree[node*2].first == tree[node*2+1].first){
        tree[node].first = tree[node*2].first;
        tree[node].second = tree[node*2].second + tree[node*2+1].second;
    }
    else if(tree[node*2].first < tree[node*2+1].first){
        tree[node].first = tree[node*2].first;
        tree[node].second = tree[node*2].second;
    }
    else{
        tree[node].first = tree[node*2+1].first;
        tree[node].second = tree[node*2+1].second;
    }
}

int main(){

    int n , m;
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];
    build(1,0,n-1);
    while(m--){
        int type = 0;
        cin >> type;

        if(type==1){
            // update
            int idx,val;
            cin >> idx >> val;
            update(1,0,n-1,idx,val);
        }
        else if(type==2){
            // query
            int l , r;
            cin >> l >> r;

            pair<int,int> ans = query(1,0,n-1,l,r);
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}