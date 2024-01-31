#include<bits/stdc++.h>
using namespace std;

// ways to make coin change -> no of ways we have to tell
// any element can take any no.of time

// Recursion
// T.C > O(2^n)  S.C O(n)
int coins(int ind,vector<int> &nums,int target){
    if(ind==0){
          if(target%nums[ind]==0) return 1;
          else return 0; 
    }

    int notTake = coins(ind-1,nums,target);
    int take = 0;
    if(nums[ind] <= target){
        take = 1 + coins(ind,nums,target-nums[ind]);
    }
    return take + notTake; 
}
int findTotalWays(vector<int> &nums,int target){
    return coins(n-1,nums,target);
}

// memoization
// T.C > O(n*n) S.C O(n*n)+O(n)
int coins(int ind,vector<int> &nums,int target,vector<vector<int>> &dp){
    if(ind==0){
         return (target%nums[ind]==0) ;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notTake = coins(ind-1,nums,target,dp);
    int take = 0;
    if(nums[ind] <= target){
        take = coins(ind,nums,target-nums[ind],dp);
    }
    return dp[ind][target] = take + notTake; 
    }   
int change(int target, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    
    return coins(n-1,nums,target,dp);
}

// tabulation 
// T.C O(n*n) S.C O(n*n)
int change(int target, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    for(int T=0;T<=target;T++) dp[0][target] = (target%nums[0]==0);
    
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=target;tar++){
            int notTake = dp[ind-1][tar];
            int take = 0;
            if(nums[ind]<=target){
                take = dp[ind][tar-nums[ind]];
            }
            dp[ind][tar] = notTake + take;
        }
    }
    return dp[n-1][target];
}

// space optimization
// T.C O(n*n) S.C O(n)
int change(int target, vector<int>& nums) {
       int n = nums.size();
   vector<int> prev(target+1,-1),curr(target+1,-1);

   for(int T=0;T<=target;T++) prev[T] = (T%nums[0]==0);
   
   for(int ind=1;ind<n;ind++){
       for(int tar=0;tar<=target;tar++){
           int notTake = prev[tar];
           int take = 0;
           if(nums[ind]<=tar){
               take = curr[tar-nums[ind]];
           }
           curr[tar] = notTake + take;
       }
       prev = curr;
   }
   return prev[target];
}


int main(){
    return 0;
}
