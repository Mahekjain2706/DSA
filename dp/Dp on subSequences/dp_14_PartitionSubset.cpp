#include<bits/stdc++.h>
using namespace std;

// recursion
// T.C O(2^n) S.C O(n)
bool subsetSum(int ind,int target,vector<int> &nums){
    if(target==0) return true;
    if(ind==0) return nums[0]==target;

    bool notTake = subsetSum(ind-1,target,nums);
    bool take = false;
    if(nums[ind]<=target){
        take = subsetSum(ind-1,target-nums[ind],nums);
    }
    return (take | notTake);
}
    bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2==1) return false;
    int k  = sum/2;
    return subsetSum(n-1,k,nums);
    }

// memorization
// T.C O(n*n) S.C O(n*n)+O(n)
bool subsetSum(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return nums[0]==target;

    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake = subsetSum(ind-1,target,nums,dp);
    bool take = false;
    if(nums[ind]<=target){
        take = subsetSum(ind-1,target-nums[ind],nums,dp);
    }
    return dp[ind][target] = (take | notTake);
}

bool canPartition(vector<int>& nums) {
int sum = 0;
int n = nums.size();
for(int i=0;i<nums.size();i++) sum+=nums[i];
if(sum%2==1) return false;
int k  = sum/2;
vector<vector<int>> dp(n,vector<int>(k+1,-1));
return subsetSum(n-1,k,nums,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
bool canPartition(vector<int>& nums) {
    if(nums.size()==1) return false;
    int sum = 0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2==1) return false;
    int k  = sum/2;
    int n = nums.size();
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][nums[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(nums[i]<=j){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = (take | notTake);
        }
    }
    return dp[n-1][k];
    }


// space optimization
bool canPartition(vector<int> &nums, int n)
{
    int sum = 0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2==1) return false;
    int k  = sum/2;
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