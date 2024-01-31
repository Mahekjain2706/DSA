#include<bits/stdc++.h>
using namespace std;

// Recursion
// T.C O(2^(n*m)) S.C O(n*m)
int obstacles(int row,int col , vector<vector<int>> &grid){
    if(row>=0 && col>=0 && grid[row][col]==1) return 0;
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;

    int up = obstacles(row-1,col,grid);
    int left = obstacles(row,col-1,grid);
    return up + left;
}   
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    return obstacles(n-1,m-1,grid);
}

// Memorization
// T.C O(n*m) S.C O(n*m)+recursion stack space
int obstacles(int row,int col , vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row>=0 && col>=0 && grid[row][col]==-1) return 0;
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = obstacles(row-1,col,grid,dp);
        int left = obstacles(row,col-1,grid,dp);
        return dp[row][col] = (up + left) ;
    }   
int mazeObstacles(int n, int m, vector< vector< int> > &grid) {
    // Write your code here
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return obstacles(n-1,m-1,grid,dp);
}

// Tabulation
// T.C O(n*m) S.C O(n*m)
int mazeObstacles(int n, int m, vector< vector< int> > &grid) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==-1) dp[row][col]=0;
                else if(row==0 && col==0) dp[0][0]=1;
                else{   
                    int up = 0 ,down = 0;
                    if(row>0) up += dp[row-1][col];
                    if(col>0) down += dp[row][col-1];

                    dp[row][col] = (up + down);
                }

            }
        }
        return dp[n-1][m-1];
}

// space optimization
// T.C O(n*m) S.C O(m)
int mazeObstacles(int n, int m, vector< vector< int> > &grid) {
        vector<int> prev(m,-1);
        for(int row=0;row<n;row++){
            vector<int> curr(m,0);
            for(int col=0;col<m;col++){
                if(grid[row][col]==-1)curr[col]=0;
                else if(row==0 && col==0) curr[0]=1;
                else{   
                    int up = 0 ,down = 0;
                    if(row>0) up += prev[col];
                    if(col>0) down += curr[col-1];

                    curr[col] = (up + down);
                }
            }
            prev = curr;
        }
        return prev[m-1];
}
int main(){
    return 0;
}