#include<bits/stdc++.h>
using namespace std;

// Minimum number of Coins needed to reach the target.
// GREEDY work for some test case but have some cases where it does'nt work
// ex:- {9,6,5,1}  tar = 11 greedy-{9,1,1} actual-{6,5}
// T.C > O(2^n)  S.C > O(N) Auxillary space
int coinsNeed(int ind,vector<int>&coins,int tar,int n){
    if(ind==0){
        if(tar%coins[0]==0){
            return tar/coins;
        }
        else return 1e9;
    }

    int notTake = 0 + coinsNeed(ind-1,coins,tar,n);
    int take = 1e9;
    if(coins[ind]<=tar){
        take = 1 + coinsNeed(ind,coins,tar-coins[ind],n);
    }
    return min(take,notTake);
}
int MinimumCoins(vector<int> &coins,int n,int tar){
    sort(coins.begin(),coins.end());
        int n = coins.size();
        int ans = coinsNeed(n-1,coins,tar,n);
        if(ans == 1e9) return -1;
        else return ans;
}

// memorization
// T.C O(n*n) S.C O(n*n)+O(n)
 int coinsNeed(int ind,vector<int>&coins,int tar,int n,vector<vector<int>> &dp){
    if(ind==0){
        if(tar%coins[0]==0){
            return tar/coins[0];
        }
        else return 1e9;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notTake = 0 + coinsNeed(ind-1,coins,tar,n,dp);
    int take = 1e9;
    if(coins[ind]<=tar){
        take = 1 + coinsNeed(ind,coins,tar-coins[ind],n,dp);
    }
    return dp[ind][tar] = min(take,notTake);
}
int coinChange(vector<int>& coins, int tar) {
    sort(coins.begin(),coins.end());
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    int ans = coinsNeed(n-1,coins,tar,n,dp);
    if(ans == 1e9) return -1;
    else return ans;
}

// Tabulation 
// T.C O(n*n) S.C O(n*n) 
int coinChange(vector<int>&coins,int tar){
    sort(coins.begin(),coins.end());
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    for(int T=0;T<=tar;T++){
        if(T%coins[0] == 0) dp[0][T] = T/coins[0];
        else dp[0][T] = 1e9;
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=tar;T++){
          int notTake = 0 + dp[ind-1][T];
          int take = 1e9;
        if(coins[ind]<=T){
            take = 1 + dp[ind][T-coins[ind]];
        }
        dp[ind][T] = min(take,notTake);  
        }
    }
    int ans = dp[n-1][tar];
    if(ans==1e9) return -1;
    else return ans;
}

// space optimization
// T.C O(n*n) S.C O(n)
int coinChange(vector<int>&coins,int tar){
    sort(coins.begin(),coins.end());
    int n = coins.size();
    vector<int> prev(tar+1,-1),curr(tar+1,-1);
    for(int T=0;T<=tar;T++){
        if(T%coins[0] == 0) prev[T] = T/coins[0];
        else prev[T] = 1e9;
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=tar;T++){
          int notTake = 0 + prev[T];
          int take = 1e9;
        if(coins[ind]<=T){
            take = 1 + curr[T-coins[ind]];
        }
        curr[T] = min(take,notTake);  
        }
        prev=curr;
    }
    int ans = prev[tar];
    if(ans==1e9) return -1;
    else return ans;
}

int main()
{
    return 0;
}