#include<bits/stdc++.h>
using namespace std;

// in grid from 0,0 go to last no.of ways

// How to write recurence
// 1. express everything in terms of i and j
// 2. explore and do all the stuffs
// 3. sum up all the ways amx and min

// How many ways go from 0,0 to n-1,m-1
// Recursion // T.C 2^(n*m)  S.C Path Length
int ways(int row,int col , vector<vector<int>> &grid){
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;

    int up = ways(row-1,col,grid);
    int left = ways(row,col-1,grid);
    return up + left;
}
int countWays(vector<vector<int>> &grid){
    int n = grid.size(),m=grid[0].size();
    return ways(n-1,m-1,grid);
}
// Memorization
// T.C O(n*m) S.C O((n-1)*(m-1))+O(n*m)
long long waysPossible(int row,int col,vector<vector<int>> &dp){
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;
    
    if(dp[row][col]!=-1) return dp[row][col];
    
    int up = waysPossible(row-1,col,dp);
    int down = waysPossible(row,col-1,dp);
    
    return dp[row][col] = up + down;
}
long long  numberOfPaths(int m, int n)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return waysPossible(m-1,n-1,dp);
}


// Tabulation
// T.C O(n*m) S.C O(n*m)
long long  numberOfPaths(int m, int n)
{  
    vector<vector<int>> dp(m,vector<int>(n,-1));
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            if(row==0 && col==0) dp[0][0]=1;
            else{   
                int up = 0 ,down = 0;
                if(row>0) up += dp[row-1][col];
                if(col>0) down += dp[row][col-1];
            
                dp[row][col] = up + down;
            }
            
        }
    }
    return dp[m-1][n-1];
}

// Space Optimization
// if there is a previous row and prev col then we can do it.
long long  numberOfPaths(int m, int n)
{  
     vector<int> prev(n,0);
    for(int row=0;row<m;row++){
        vector<int> curr(n,0);
        for(int col=0;col<n;col++){
            if(row==0 && col==0) curr[col]=1;
            else{   
                int up = 0 ,down = 0;
                if(row>0) up += prev[col];
                if(col>0) down += curr[col-1];
            
                curr[col] = up + down;
            }  
        }
        prev = curr;
    }
    return prev[n-1];
}

// optimized 
long long  numberOfPaths(int m, int n)
{  
    int N = n + m -2;
    int r = m-1;
    double res = 1;

    for(int i=0;i<=r;i++){
        res = res * (N-r+i)/i;
    }   
    return (int)res; 
}

int main(){

    return 0;
}