#include<bits/stdc++.h>
using namespace std;

// recursive
long long int pathSum(int row,int col,vector<vector<int>> &grid){
    if(row<0 || col<0) return INT_MAX;
    if(row==0 && col==0) return grid[row][col];

    long long int up =  grid[row][col] + pathSum(row-1,col, grid);
    long long int left = grid[row][col] + pathSum(row,col-1, grid);

    return min(up,left);
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

   return pathSum(n-1,m-1,grid);
}

//memorization
// T.C O(n*m) S.C O(n*m)+ ((n-1)+(m-1))
long long int pathSum(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(row<0 || col<0) return INT_MAX;
    if(row==0 && col==0) return grid[row][col];
    
    if(dp[row][col]!=-1) return dp[row][col];
    long long int up =  grid[row][col] + pathSum(row-1,col, grid,dp);
    long long int left = grid[row][col] + pathSum(row,col-1, grid,dp);

    return dp[row][col]=min(up,left);
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
   return pathSum(n-1,m-1,grid,dp);
}

// tabulation

int main(){

}