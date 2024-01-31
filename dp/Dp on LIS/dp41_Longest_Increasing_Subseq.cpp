#include<bits/stdc++.h>
using namespace std;

// Length of Longest Increasing subsequence

// 1. print all subsequence then se it is increase and store longest. /// T.c O(2^n)

// 2. Trying all ways bu recursion
// T.,C O(2^n) S.C O(n) auxillary
int findSubsq(int ind,int prev,vector<int> &nums,int n){
    if(ind==n){
        return 0;
    }

    int notTake = findSubsq(ind+1,prev,nums,n);
    int take = 0;
    if(prv==-1 || arr[ind] > arr[prev]){
        take = 1 + findSubsq(ind+1,ind,nums,n);

    }
    return max(notTake,take);
}
int lis(vector<int> &nums){
    int n = nums.size();
    return findSubsq(0,-1,nums,n);
}


// memorization
// t.C O(n*n) S.C O(n*n)+O(n)
int findSubsq(int ind,int prev,vector<int> &nums,int n,vector<vector<int>> &dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int notTake = findSubsq(ind+1,prev,nums,n,dp);
    int take = 0;
    if(prev==-1 || nums[ind] > nums[prev]){
        take = 1 + findSubsq(ind+1,ind,nums,n,dp);

    }
    return dp[ind][prev+1] = max(notTake,take);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int> (n+1,-1));

    return findSubsq(0,-1,nums,n,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));

    for(int ind=n-1;ind>=0;ind--){
        for(int prev =ind-1;prev>=-1;prev--){
                int notTake = dp[ind+1][prev+1];
                int take = 0;
                if(prev==-1 || nums[ind] > nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(notTake,take);
        }
    }
    return dp[0][0];
}

// space optimization
// T.C O(n*n) S.C O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> curr(n+1,0);
    vector<int> ahead(n+1,0);
    
    for(int ind=n-1;ind>=0;ind--){
        for(int prev =ind-1;prev>=-1;prev--){
                int notTake = ahead[prev+1];
                int take = 0;
                if(prev==-1 || nums[ind] > nums[prev]){
                    take = 1 + ahead[ind+1];

                }
                curr[prev+1] = max(notTake,take);
        }
        ahead = curr;
    }
    return curr[0];
}

// optimized
// T.C O(n*n) S.C O(1)
// from each index check the elemnt whihc is smaller then it and length of 
// alias possible till that index than find max of them to get length of lis.
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    int maxi = 0;

    for(int i=0;i<n;i++){
        for(int prev =0;prev<i;prev++){
            if(nums[prev] < nums[ind]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}


int main(){
    return 0;
}