#include<bits/stdc++.h>
using namespace std;

// Target Sum
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// it is same like divide in two partitions with difference as target
// s1-s2=tar s1+s2 = Tsum  , s1 = (Tsum-d) / 2;

int targetSum(int ind,vector<int> &nums,int tar){
    if(ind==0){
        if(tar==0 && nums[0]==0) return 2;
        if(tar==0 || tar==nums[0]) return 1;
        return 0;
    }

    int notTake = targetSum(ind-1,nums,tar);
    int take = 0;
    if(nums[ind]<=tar){
        take = targetSum(ind-1,nums,tar-nums[ind]);
    }
    return notTake + take;
}
int findTarget(vector<int> &nums,int target){
    int n = nums.size();
    int Tsum = 0;
    for(int i=0;i<n;i++) Tsum +=nums[i];

    if(Tsum-target < 0 || (Tsum-target)%2==1) return 0;
    int sum = (Tsum-target)/2;
    return targetSum(n-1,nums,sum);
}


// memoization
// T.C O(n*n)  S.C O(n*n)*O(n)
 int targetSum(int ind,vector<int> &nums,int tar, vector<vector<int>> &dp){
    if(ind==0){
        if(tar==0 && nums[0]==0) return 2;
        if(tar==0 || tar==nums[0]) return 1;
        return 0;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notTake = targetSum(ind-1,nums,tar,dp);
    int take = 0;
    if(nums[ind]<=tar){
        take = targetSum(ind-1,nums,tar-nums[ind],dp);
    }
    return dp[ind][tar] = notTake + take;
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int Tsum = 0;
    for(int i=0;i<n;i++) Tsum +=nums[i];

    if(Tsum-target < 0 || (Tsum-target)%2==1) return  0;
    int sum = (Tsum-target)/2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return targetSum(n-1,nums,sum,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)

 int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int Tsum = 0;
    for(int i=0;i<n;i++) Tsum +=nums[i];

    if((Tsum-target) < 0 || (Tsum-target)%2==1) return  0;
    int sum = (Tsum-target)/2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));

    if(nums[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(nums[0]!=0 && nums[0]<=sum) dp[0][nums[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(nums[i]<=j){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = notTake + take;
        }
    }

    return dp[n-1][sum];
    }

// space optimization
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int Tsum = 0;
    for(int i=0;i<n;i++) Tsum +=nums[i];

    if((Tsum-target) < 0 || (Tsum-target)%2==1) return  0;
    int sum = (Tsum-target)/2;
    vector<int> prev(sum+1,-1),curr(sum+1,-1);

    if(nums[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(nums[0]!=0 && nums[0]<=sum) prev[nums[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int notTake = prev[j];
            int take = 0;
            if(nums[i]<=j){
                take = prev[j-nums[i]];
            }
            curr[j] = notTake + take;
        }
    }

    return prev[sum];
    }


int main(){

    return 0;
}