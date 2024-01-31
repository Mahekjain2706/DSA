#include<bits/stdc++.h>
using namespace std;

// You are given a triangel and we have to give minimum path sum

// Recursive
int miniPath(int row,int col,vector<vector<int>> &triangle,int n){
    if(row==n-1) return triangle[n-1][col];

    int up = triangle[row][col] + miniPath(row+1,col, triangle,n);
    int left = triangle[row][col] + miniPath(row+1,col+1, triangle,n);

    return min(up,left);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return miniPath(0,0,triangle,n);
}

// Memorization
// T.C O(n*n) S.C O(n*n)+recursion
int miniPath(int row,int col,vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
    if(row==n-1) return triangle[n-1][col];
    if(dp[row][col]!=-1) return dp[row][col];
    int up = triangle[row][col] + miniPath(row+1,col, triangle,n,dp);
    int left = triangle[row][col] + miniPath(row+1,col+1, triangle,n,dp);
    return dp[row][col]=min(up,left);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return miniPath(0,0,triangle,n,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up = triangle[i][j] + dp[i+1][j];
            int left = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(up,left);
        }
    }
    return dp[0][0];
}

// space optimization
// T.C O(n*n) S.C O(n)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev(n,0);
    for(int i=0;i<n;i++){
        prev[i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int> curr(n,0);
        for(int j=i;j>=0;j--){
            int up = triangle[i][j] + prev[j];
            int left = triangle[i][j] + prev[j+1];

            curr[j] = min(up,left);
        }
        prev = curr;
    }
    return prev[0];
}


int main(){
    return 0;
}