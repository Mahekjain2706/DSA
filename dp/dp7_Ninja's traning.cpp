#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &ninja,int ind,int prev,vector<vector<int>> &dp){
    // base case
    if(ind==0){
        int store = 0;
        for(int i=-1;i<3;i++){
            if(prev!=i){
                store = max(store,ninja[ind][i]);
            }
        }
        return store;
    }
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int ans=0;
    for(int i=-1;i<3;i++){
        if(prev!=i){
            ans = max(ans,ninja[ind][i]+maxPoints(ninja,ind-1,i,dp));
        }
    }
    return dp[ind][prev+1] = ans;
}

int ninjaTraning(vector<vector<int>> &ninja,int n){
    vector<vector<int>> dp(n,vector<int>(4,0));
    return maxPoints(ninja,n-1,-1,dp);
}
int main(){
    return 0;
}

// 3
// 1            2           3      0
// task 1     task 2     task 3   task -1
//  1            2          5
//  3            1          1       0
//  3            3          3    <-

// 5 + 3 + 3 -> 11
