#include<bits/stdc++.h>
using namespace std;

// Partition with given difference 
// divide into two subsets, "D" d as difference is given , count no.of partition were s1 >= s2 and s1-s2 = "D", ans in terms of 1e9+7

// s1-s2 = d      s1+s2 = Tsum
// Tsum - s2 - s2 = d;
// s2 = Tsum - d / 2  -> subset with sum s2 -> it always poisitive

// count subset with sum as s2
// edge cases -> as 0<=nums[i] integers
// as all are integers no fraction therefore s2 is also int then s2 must be even means Tsum - d -> even

// memoization  T.C O(n*n)  S.C O(n*n)
// 1. Tsum-d >=0  && 2. Tsum-d even
int mod = 1e9 + 7;
int funct(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){

    if(ind==0){
        if(sum==0 && nums[0]==0) return 2;
        else if(sum==0 || sum == nums[0]) return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][k];
    int notTake = funct(ind-1,k,nums,dp);
    int take = 0;
    if(nums[ind]<=sum){
        take = funct(ind-1,sum-nums[ind],nums,dp);
    }
    return dp[ind][sum] = (notTake + take)%mod;
}
int countWays(vector<int> &nums,int d,int n){
    int Tsum = 0;
    for(int 0;i<n;i++) Tsum += nums[i];
    int k = Tsum - d / 2;
    if((Tsum-d)<0 || (Tsum-d)%2==1) return 0;

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return funct(n-1,k,nums,dp);
}


// tabulations
int findways(vector<int> &nums,int d,int n){
    
    int Tsum = 0;
    for(int 0;i<n;i++) Tsum += nums[i];
    int k = Tsum - d / 2;
    if((Tsum-d)<0 || (Tsum-d)%2==1) return 0;  

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    if(nums[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(nums[0] != 0 &&nums[0]<=tar) dp[0][nums[0]] = 1;

    for(int ind = 1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            int notTake = dp[ind-1][tar];
            int take = 0;
            if(tar>=nums[ind]){
                take = do[ind-1][tar-nums[ind]];
            }
            dp[ind][tar] = (take + notTake)%mod;
        }
    }
    return dp[n-1][k];
}

// space optimization
int findways(vector<int> &nums,int d,iny n){
    
    int Tsum = 0;
    for(int 0;i<n;i++) Tsum += nums[i];
    int k = Tsum - d / 2;
    if((Tsum-d)<0 || (Tsum-d)%2==1) return 0;  

    vector<int> prev (k+1,-1),curr(k+1,-1);
    if(nums[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(nums[0] != 0 &&nums[0]<=tar) prev[nums[0]] = 1;

    for(int ind = 1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            int notTake = prev[tar];
            int take = 0;
            if(tar>=nums[ind]){
                take = prev[tar-nums[ind]];
            }
            curr[tar] = (take + notTake)%mod;
        }
        prev = curr;
    }
    return prev[k];
}


int main(){

    return 0;
}