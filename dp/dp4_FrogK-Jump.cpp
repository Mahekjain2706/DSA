#include<bits/stdc++.h>
using namespace std;

//recursion t.c o(n) x K   s.c O(n) + O(n)
int frogKthJump(int ind,vector<int>&Height,int k){
    if(ind==0) return 0;
    int store = INT_MAX;

    for(int i=0;i<=k;i++){
        if(ind-i>=0){
        int jumps = frogKthJump(ind-i,Height,k)+ abs(Height[ind]-Height[ind-i]);
       store = min(store,jumps);}
    }
    return store;
}

// // memorization
// int frogKthJump(int ind,vector<int>&Height,int k,vector<int>dp[n]){
//     if(ind==0) return 0;
//     int store = INT_MAX;
//     if(dp[ind]!=-1) return dp[ind];
    
//     for(int i=0;i<=k;i++){
//         if(ind-i>=0){
//         int jumps = frogKthJump(ind-i,Height,k)+ abs(Height[ind]-Height[ind-i]);
//        store = min(store,jumps);}
//     }
//     return dp[ind] = store;
// }

// tabulation t.c O(n)x K  s.c O(n)
int frogKthJump(int ind,vector<int>&Height,int k){
    int n = Height.size();
    if(ind==0) return 0;
    vector<int> dp(n,0);
    dp[0]=0;
    int store = INT_MAX;
    
    for(int i=1;i<n;i++){
        store = INT_MAX;
       for(int j=1;j<=k;j++){
         if(i-j>=0){
            int jump = dp[i-j]+abs(Height[ind]-Height[ind-j]);
            store = min(store,jump);
         }
       }
       dp[i] =  store;
    }
    return dp[n-1];
}


int main(){

    int n;cin>>n;
    vector<int>Height;
    for(int i=0;i<n;i++){
        cin>>Height[i];
    }
    int k;cin>>k;
    vector<int>dp(n,-1);
   cout<<frogKthJump(n-1,Height,k)<<endl;


    return 0;
}