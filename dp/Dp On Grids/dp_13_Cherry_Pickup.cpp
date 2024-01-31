#include<bits/stdc++.h>
using namespace std;

// recursion
//T.C O(3^n * 3^n)  S.C O(n)
int maxiCherry(int row,int j1,int j2,int r,int c, vector<vector<int>> &grid){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;
    if(row == r-1){
        if(j1==j2) return grid[row][j1];
        else return grid[row][j1] + grid[row][j2];
    } 

    // explore all the paths of alice and bob simuntaneously.
    int maxi = -1e8;

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int val = 0;
            if(j1==j2) val = grid[row][j1];
            else val = grid[row][j1] + grid[row][j2];

            val += maxiCherry(row+1,j1+i,j2+j,r,c,grid);
            maxi = max(maxi,val);
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    return maxiCherry(0,0,m-1,n,m,grid);
 }


// memorization
// T.C O(n*m*m)*9  S.c O(n*m*m)+O(n)
int maxiCherry(int row,int j1,int j2,int r,int c,        vector<vector<int>> &grid , vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;
    if(row == r-1){
        if(j1==j2) return grid[row][j1];
        else return grid[row][j1] + grid[row][j2];
    } 
    if(dp[row][j1][j2]!=-1) return dp[row][j1][j2];
    // explore all the paths of alice and bobsimuntaneously.
    int maxi = -1e8;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int val = 0;
            if(j1==j2) val = grid[row][j1];
            else val = grid[row][j1] + grid[row][j2];
            val += maxiCherry(row+1,j1+i,j2+j,r,c,grid,dp);
            maxi = max(maxi,val);
        }
    }
    return dp[row][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m,-1)));
    return maxiCherry(0,0,m-1,n,m,grid,dp);
}

// Tabulation
// T.C O(n*m*m*9) S.C O(n*m*m)
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m,-1)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j2]= grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2;i>=0;i++){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e8;
                for(int d1=-1;d1<=1;d1++){
                    for(int d2=-1;d2<=1;d2++){
                        int val = 0;
                        if(j1==j2) val = grid[i][j1];
                        else val = grid[i][j1] + grid[i][j2];
                        if(j1+d1 >=0 && j1+d1<m && j2+d2<m && j2+d2>=0) val += dp[i+1][j1+d1][j2+d2];
                        else 
                            val += -1e8;
                        maxi = max(maxi,val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}


int main(){

    return 0;
}