#include<bits/stdc++.h>
using namespace std;

// given an array from whwere we cut the length and we have to find minimum cost to cut the string.

// if we sort the array and then do the partition of array it will give correct answer because prev cut does'nt depend on others.
// put 0 on front and n at last of array.
// cost -> length 0f the stick in which i is
// length -> nums[j+1] - nums[i-1];


// Recursive 
// T.C O(exponential) S.C O(k)
int costCut(int i,int j,vector<int> &nums){
    if(i>j) return 0;

    int mini = INT_MAX;
    for(int k=i;k<=j;k++){
        int cost = (nums[j+1]-nums[i-1]) + costCut(i,k-1)+costCut(k+1,j);
        if(mini> cost) mini = cost;
    }
    return mini;
}
int minCost(vector<int> &nums,int n){
    int k = nums.size();
    nums.push_back(n);
    nums.insert(nums.begin(),0);
    sort(nums.begin(),nums.end());
    return costCut(0,k-1,nums);
}


// Memorization
// T.C O(k*k*k)~ k^3 S.C O(k*k)+O(k)
int costCut(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
    if(i>j) return 0;

    int mini = INT_MAX;

    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<=j;k++){
        int cost = (nums[j+1]-nums[i-1]) + costCut(i,k-1,dp)+costCut(k+1,j,dp);
        if(mini> cost) mini = cost;
    }
    return dp[i][j] = mini;
}
int minCost(vector<int> &nums,int n){
    int k = nums.size();
    nums.push_back(n);
    nums.insert(nums.begin(),0);
    sort(nums.begin(),nums.end());
    vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
    return costCut(0,k-1,nums,dp);
}


// tabulation
// T.C O(k*k*k) S.C O(k*k)
int minCost(vector<int> &nums,int n){
    int k = nums.size();
    nums.push_back(n);
    nums.insert(nums.begin(),0);
    sort(nums.begin(),nums.end());
    vector<vector<int>> dp(k+2,vector<int>(k+2,0));
    
    for(int i=k;i>=1;i--){
        for(int j=1;j<=k;j++){
            if(i>j) continue;
            int mini = INT_MAX;
            for(int k=i;k<=j;k++){
                int cost = (nums[j+1]-nums[i-1]) +dp[i][k-1]+ dp[k+1][j];
                if(mini> cost) mini = cost;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][k];
}



int main(){
    return 0;
}