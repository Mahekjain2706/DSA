#include<bits/stdc++.h>
using namespace std;

// Recursion
// T.C O(2^n) S.C O(n) 
int subsetK(int ind,int sum,vector<int>&nums){
    if(sum==0) return 1;
    if(ind==0){
        return nums[0]==sum;
    }
    int notPick = 0 + subsetK(ind-1,sum,nums);
    int pick = 0;
    if(nums[ind]<=sum){
        pick = subsetK(ind-1,sum-nums[ind],nums);
    }
    return pick + notPick;
}

int countWays(vector<int> nums,int k){
    int n = nums.size();
    return subsetK(n-1,0,nums);
}

// in this dp array store the no.of subseq possible till that index which give you target.
// memorization
// T.C O(n*n)  S.C O(n*n)+O(n)auxillary stack space
int subSum(int ind,vector<int> &nums,int k,vector<vector<int>> &dp){
    if(sum==0) return 1;
    if(ind==0){
        return nums[0]==sum;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];

    int notPick = subSum(ind-1,nums,k,dp);
    int pick=0;
    if(nums[ind]<=k){
        pick = subSum(ind-1,nums,k-nums[ind],dp);
    }
    return dp[ind][k] = pick + notPick;
}
int countWays(vector<int> &nums,int k){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return subSum(n-1,nums,k,dp);
}

// tabulation
int countWays(vector<int> &nums,int k){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));

    for(int i=0;i<n;i++) dp[i][0] = 1;
    if(nums[0]<=k) dp[0][nums[0]] = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int notPick = dp[i-1][j];
            int pick=0;
            if(nums[ind]<=k){
                pick = dp[i-1][j-nums[i]];
            }
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n-1][k];
}

// space optimization
int countWays(vector<int> &nums,int k){
    int n = nums.size();
    vector<int> prev(k+1,-1),curr(k+1,-1);

    prev[0] = curr[0] = 1;
    if(nums[0]<=k) prev[nums[0]] = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int notPick = prev[j];
            int pick=0;
            if(nums[ind]<=k){
                pick = prev[j-nums[i]];
            }
            curr[j] = pick + notPick;
        }
        prev = curr;
    }
    return prev[k];
}

// if negative numbers then instead of dp 2-d vector we can use unordered_map 

// if the case is {0,0,1}-> no.of subset sum 1 -> 4
// {0,1} {0,1} {0,0,1} {1}  but this code give us answer as 1;

// -> figure out number of zeros , then find how many ways we represent to zero , by power set  pow(2,n)
// so final answer is pow(2,n) * original answer.

// but why it is fail -> as we are moving from last to first then if sum==0 then we stop and dont consider that 0's.
// we have to go deep and consider zero also
// so we chnage base case that is 

// if(ind==0) {
//     if(k==0 && nums[0]==0)  return 2;
//      else if(k==0 || sum==nums[0]) return 1;
//      return 0;
// }

int main(){
    return 0;
}