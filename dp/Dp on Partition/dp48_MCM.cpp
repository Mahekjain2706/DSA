#include<bits/stdc++.h>
using namespace std;

// we divide the problem into two part or different partitions and we have to change something.

// Matrix Chain Multiplication
// PARTITION DP
// given 3 matrix we have to find no.of operations to multiply these matrix

// for multiplying two matrix :- i*j   j*k   dimension like this needed new matrix -> i*k 
// no.of multiplication done -> i*j*k
// 3 matrix -> a,b,c -> A (10*30) , B (30*5) , C (5*60)
// total operations -> (A*B)*C -> (10*30*5) + (10*5*60)(result matrix) -> 1500 + 3000 -> 4500 so large
// A*(B*C) -> total oper -> 2700
// you are given array in whicch you are given dimension like :-
// A[1] -> arr[0]*arr[1] , A[2] -> arr[1]*arr[2] , 
// A[i] -> arr[i-1]*arr[i]
// we have to find minimum no.of operation to multiply this matrix

// RULES :-
// 1. start with the entore block.
// 2. break the problem with smaller problems , marrk with start and end point in each partition.
// 3. Try all partitions , run a loop to try all partitions.
// 4. return the best possible 2 partitions.

// 10,20,30,40,50
// (10,20),(20,30),(30,40),(40,50).
//    A   ,   B   ,   C   ,   D  
//    i(1)                  j(n-1)
// F(1,4) -> return min multiplication to multiply matrix 1 to 4

// recursion
// T.C O(exponential) S.C O(n)
int funct(int i,int j,int* arr){
    if(i==j) return 0;

    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = (arr[i-1]*arr[k]*arr[j]) + funct(i,k,arr) + funct(k+1,j,arr);
        if(steps<mini) mini = steps;
    }
    return mini;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    return funct(1,n,arr);
}

// memorization
// T.C O(n*n) S.C O(n*n)+O(n)
int funct(int i,int j,int* arr,vector<vector<int>> &dp){
    if(i==j) return 0;

    int mini = 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    
    for(int k=i;k<j;k++){
        int steps = (arr[i-1]*arr[k]*arr[j]) + funct(i,k,arr,dp) + funct(k+1,j,arr,dp);
        if(steps<mini) mini = steps;
    }
    return dp[i][j] = mini;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return funct(1,n,arr,dp);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
int matrixChainMultiplication(int* arr, int n) {
    int dp[n+1][n+1];
    
    for(int i=1;i<=n;i++) dp[i][i] = 0;
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                if(steps<mini) mini = steps;
            }
            dp[i][j] = mini;
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }cout<< endl;
    // }
    return dp[1][n];
}


int main(){
    return 0;
}