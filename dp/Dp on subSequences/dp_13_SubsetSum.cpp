#include<bits/stdc++.h>
using namespace std;

// We have to find maximum subset sum
// SubSet sum equal to K
// recursion
// T.C O(2^n) S.C O(n)
bool subset(int ind,int k,vector<int> nums){
    if(k==0){
        return true;
    }
    if(ind==0) return nums[0]==k;
    bool notTake = subset(ind-1,k,nums);
    bool take = 0;
    if(nums[ind]<=k){
        take = subset(ind-1,k-nums[ind],nums);
    }
    return (take || notTake);
}
bool subsetSumToK(int n, int k, vector<int> &nums) {
    return subset(n-1,k,nums);
}


// Memorization
// T.C O(n*target) S.C o(n*target) + O(n)
bool subset(int ind,int k,vector<int> nums,vector<vector<int>> &dp){
    if(k==0){
        return true;
    }
    if(ind==0) return nums[0]==k;
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool notTake = subset(ind-1,k,nums,dp);
    bool take = 0;
    if(nums[ind]<=k){
        take = subset(ind-1,k-nums[ind],nums,dp);
    }
    return dp[ind][k] = (take || notTake);
}
bool subsetSumToK(int n, int k, vector<int> &nums) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return subset(n-1,k,nums,dp);
}

// Tabulation 
bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=k;j++){
            bool notTake = dp[ind-1][j];
            bool take = false;
            if(nums[ind]<=j){
                take = dp[ind-1][j-nums[ind]];
            }
            dp[ind][j] = (take | notTake);
        }
    }

    return dp[n-1][k];
}


// space optimization
bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0] = curr[0] = true;
    prev[nums[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=k;j++){
            bool notTake = prev[j];
            bool take = false;
            if(nums[ind]<=j){
                take = prev[j-nums[ind]];
            }
            curr[j] = (take | notTake);
        }
        prev = curr;
    }

    return prev[k];
}


int main(){

    return 0;
}