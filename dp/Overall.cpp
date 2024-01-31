#include<bits/stdc++.h>
using namespace std;

// i+1 th stair height is Height[i] 
// if frog jump from i th to j th stair Height[i-1]-Height[j-1] energy lost
// frog jump 1 or 2 stair at a time
// MINIMUM energy used to reach 1 to n

// Q. why greedy not work
// in this we take minimum path give wrong answer and want to try all possible ways.

// recurance // t.c = O(nlog(n)) s.c = O(n)
int frog(int ind,vector<int>Height){
    if(ind==0) return 0;

    int left = frog(ind-1,Height) + abs(Height[ind]-Height[ind-1]);
    int right = INT_MAX;
    if(ind>1){
     right = frog(ind-2,Height) + abs(Height[ind]-Height[ind-2]);}

    return min(left,right);
}

// dp memorization top down // t.c = O(n) s.c = O(n) + O(n)
int frog(int ind,vector<int> &Height,vector<int>&dp){
    if(ind == 0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int left = frog(ind-1,Height) + abs(Height[ind]-Height[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
    right = frog(ind-2,Height) + abs(Height[ind]-Height[ind-2]);
    }

    return dp[ind] = min(left,right);
}
int frogjump(int n,vector<int> &Height){
    vector<int> dp(n+1,-1);
    frog(n-1,Height,dp); 
}

// dp tabulation bottom up // t.c = O(n) s.c = O(n) + O(n)
// see the edge case // s.c= O(n) t.c= O(n)
int frog(int n,vector<int>Height){
   vector<int> dp(n,0);
   dp[0]=0;
   for(int i=1;i<n;i++){
    int fs = dp[i-1] + abs(Height[i]-Height[i-1]);
    int ss = INT_MAX;
    if(i>1){
        ss = dp[i-2] + abs(Height[i]-Height[i-2]);
    }
    dp[i] = min(fs,ss);
   }
   return dp[n-1];
}

// reduce stack space
int frogJump(int n,vector<int> Height){
     // optimized
    int prev=0,prev2=0;

    for(int i=1;i<n;i++){
        int fs = prev + abs(Height[i] - Height[i-1]);
        int ss = prev2 + abs(Height[i] - Height[i-2]);

        int curr = min(fs,ss);
        prev = curr;
        prev2 = prev;
    }
    return prev;
}

// House Robber 2
// rober can rob the money from n house but if rob from adjacent house then alarm start , last house and first house is adjacent , find the maximum money he rob.
// same as maxi sum in circular
// t.c 
int maximumSum(vector<int> &arr){
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i=0;i<n;i++){
        int take = arr[i] ;
        if(i>1) take +=prev2;
        int notTake = 0 + prev;

        int curr = max(take,notTake);
        prev2 = prev;
        prev  = curr;
    }
    return prev;
}
int rob(vector<int> &arr){
    int n = arr.size();
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1)  temp2.push_back(arr[i]);
    }
    return max(maximumSum(temp1),maximumSum(temp2));
}

// Ninja 's Traning
//  N days traning schedule , 3 activites have some merit points, he can't do same activity in two consecutive days.
// maximum merit points ninja can earn ?
// n * 3 array for 3 activity merit points according to days.
// 0 - 1st task , 1 - 2nd task , 2 - 3rd task , 3 - No task
// Recursive 
int Traning(int ind,vector<vector<int>> &points,int last){
    if(ind==0) {
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[ind][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int task = points[ind][i] + Traning(ind-1,points,i);
            maxi = max(maxi,task);
        }
    }
    return maxi;
}
int ninjaTraning(vector<vector<int>>&points){
    int n = points.size();
    retrun Traning(n-1,points,3);
}

// Mmeorization
// T.C O(n*4)*3 S.C O(n) recursion + O(n*4)
int traning(int ind,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(ind==0){
       int maxi = 0; 
       for(int i=0;i<3;i++){
           if(i!=last){
               maxi = max(maxi,points[ind][i]);
           }
       }
       return maxi;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int task = points[ind][i] + traning(ind-1,i,points,dp);
            maxi = max(maxi,task);
        }
    }
    return dp[ind][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return traning(n-1,3,points,dp);
}

// Tabulation
// T.C O(n*4*3) S.C O(n*4)
int ninjaTraning(int n,vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                dp[i][j]=0;
                for(int task =0;task<3;task++){
                    if(task!=j){
                        int point = points[i][task] + dp[i-1][task];
                        dp[i][j] = max(dp[i][j],point);
                    }
                }
            }
        }
    }
    return dp[n-1][3];
}

// space optimization
// T.C O(n*4*3) S.C O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4,-1);
    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][0],points[0][2]);
    dp[2] = max(points[0][0],points[0][1]);
    dp[3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int i=1;i<n;i++){
        vector<int> temp(4,-1);
        for(int j=0;j<4;j++){
            temp[j]=0;
            for(int task =0;task<3;task++){
                if(task!=j){
                    int point = points[i][task] + dp[task];
                    temp[j] = max(temp[j],point);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}


// DP on Grids or 2 D Matrix
// 1. Count Paths
// 2. Count Paths with obstacles 
// 3. Minimum path sum 
// 4. Maximum Path Sum 
// 5. Triangle 
// 6. 2 start points.

// in grid from 0,0 go to last no.of ways

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

