#include<bits/stdc++.h>
using namespace std;

// when you burst a ballon number written on ballon you will get it adj ballon also multiply then each time you have to do this and find sum of coins should be maximum.

// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

// Recursive 
// T.C O(exponential) S.C O(n)
int funct(int i,int j,vector<int> &nums){
    if(i>j) return 0;

    int maxi = INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost = nums[i-1]*nums[ind]*nums[j+1] + funct(i,ind-1,nums) + funct(ind+1,j,nums);

        maxi= max(maxi,cost);
    }
    return maxi;
}

int maxCoins(vector<int> &nums){
    int n = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    return funct(1,n,nums);
}


// memorization
// T.C O(n*n) S.C O(n*n)+O(n)
int funct(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
    if(i>j) return 0;

    int maxi = INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int cost = nums[i-1]*nums[ind]*nums[j+1] + funct(i,ind-1,nums,dp) + funct(ind+1,j,nums,dp);

        maxi= max(maxi,cost);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &nums){
    int n = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return funct(1,n,nums,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));

    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int maxi = INT_MIN;
            for(int ind=i;ind<=j;ind++){
                int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi= max(maxi,cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}


int main(){
    return 0;
}