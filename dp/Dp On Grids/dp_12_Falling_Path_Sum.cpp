#include<bits/stdc++.h>
using namespace std;

// Maximum and Minimum Falling Path Sum

// Recursive 
// T.C O(3^n) S.C O(n*n)+O(n*n)
int maxiSum(int row,int col,vector<vector<int>>&grid){
    if(col<0 || col>=grid[0].size()) return 1e8;
    if(row==0) return grid[0][col];
    
    int left = grid[row][col] + maxiSum(row-1,col-1,grid);
    int down = grid[row][col] + maxiSum(row-1,col,grid);
    int right = grid[row][col] + maxiSum(row-1,col+1,grid);
    return min(left,min(down,right));
}
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
    int maxi=1e8;
    for(int i=0;i<m;i++){
        int temp = maxiSum(n-1,i,grid);
        maxi = min(maxi,temp);
    }
    return maxi;
}

// Memorization
// T.C O(n*n) S.C O(n*n)+O(n*n)
int maxiSum(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(col<0 || col>=grid[0].size()) return 1e8;
    if(row==0) return grid[0][col];

    if(dp[row][col]!=-1) return dp[row][col];
    int left = grid[row][col] + maxiSum(row-1,col-1,grid,dp);
    int down = grid[row][col] + maxiSum(row-1,col,grid,dp);
    int right = grid[row][col] + maxiSum(row-1,col+1,grid,dp);

    return dp[row][col] = min(left,min(down,right));
}
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int maxi=1e8;
    for(int i=0;i<m;i++){
        int temp = maxiSum(n-1,i,grid,dp);
        maxi = min(maxi,temp);
    }
    return maxi;
}

// Tabulation 
// T.C O(n*n) S.C O(n*n)
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
        
    for(int i=0;i<n;i++) dp[0][i] = grid[0][i];

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int left = grid[i][j],down = grid[i][j],right = grid[i][j];

            if(j>0) left += dp[i-1][j-1];
            else left += 1e8;

            down += dp[i-1][j];

            if(j+1<m) right += dp[i-1][j+1];
            else right += 1e8;

            dp[i][j] = min(left,min(down,right));
        }
    }
        
    int maxi = 1e8;
    for(int i=0;i<n;i++){
        maxi = min(maxi,dp[n-1][i]);
    }
    return maxi;
}

// space optimization
// T.C O(n*n) S.C O(n)
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
    vector<int> prev(n,-1);
        
    for(int i=0;i<n;i++) prev[i] = grid[0][i];

    for(int i=1;i<n;i++){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            int left = grid[i][j],down = grid[i][j],right = grid[i][j];

            if(j>0) left += prev[j-1];
            else left += 1e8;

            down += prev[j];

            if(j+1<m) right += prev[j+1];
            else right += 1e8;

            curr[j] = min(left,min(down,right));
        }
        prev = curr;
    }

        
    int maxi = 1e8;
    for(int i=0;i<n;i++){
        maxi = min(maxi,prev[i]);
    }
    return maxi;
}

int main(){

    return 0;
}