#include<bits/stdc++.h>
using namespace std;

// count no. of square sub matrix
// ex:-  1 0 1, 1 1 0 , 1 1 0 -> 7 square -> ^ ones + 2*2 (1)

// brute force
// stand in each block and check each squares possible
// dp
// 1. create similar size dp array / matrix
// 2. how many squares end at i,j(right bottom)
// so sum of all elemnt of dp table is answer

// How to fill dp table
// -> first row, column fix right 1 each place where it is 1's
// formula ->  dp[i][j] = min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1;

   int countSquares(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j=0;j<m;j++) dp[0][j]= nums[0][j];
    for(int i=0;i<n;i++) dp[i][0] = nums[i][0];

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(nums[i][j]==0) dp[i][j]=0;
            else{
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    int sum =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum += dp[i][j];
        }
    }
    return sum;  
    }

    
int main(){
    return 0;
}