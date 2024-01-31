#include<bits/stdc++.h>
using namespace std;

// you are given a perticular n->rod length and price array 
// cut the round into pieces and for each length when sell have some price given in price array
// we have to find maximum price we get
// collect rod length maximize it

// Recursion 
// T.C > O(2^n) S.C  O(target)
int maxiLen(int ind,vector<int>&prices,int W){
    if(ind==0){
        return (W/ind+1) * prices[ind];
    }

    int notTake = 0 + maxiLen(ind-1,prices,W);
    int take =0;
    if(ind+1<=W){
        take = prices[ind] + maxiLen(ind,prices,W-(ind+1));
    }
    return max(notTake,take);
}

int rodCutting(int n,vector<int> &prices){
    return maxiLen(n-1,prices,n);
}

// Memorization
// T.C O(n*n) S.C O(n*n) + O(target)
int rodCutting(int ind,int price[],int L, vector<vector<int>> &dp){
    if(ind==0){
        return L*price[0];
    }
    if(dp[ind][L]!=-1) return dp[ind][L];
    int notTake = 0 + rodCutting(ind-1,price,L,dp);
    int take = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= L){
        take = price[ind] + rodCutting(ind,price,L-rodLength,dp);
    }
    return dp[ind][L] = max(notTake,take);
}
int cutRod(int price[], int n) {
    //code here
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return rodCutting(n-1,price,n,dp);
}

// Tabulations
int rodCutting(int n,vector<int> &prices){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++) dp[0][i] = i*prices[0];

    for(int ind=1;ind<n;ind++){
        for(int L=0;L<=n;L++){
            int notTake = 0 + dp[ind-1][L];
            int take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= L){
                take = price[ind] + dp[ind][L-rodLength];
            }
            dp[ind][L] = max(notTake,take); 
        }
    }
    return dp[n-1][n];
}

// space optimization
int rodCutting(int n,vector<int> &prices){
    vector<int> prev(n+1,-1),curr(n+1,-1);
    for(int i=0;i<=n;i++) prev[i] = i*price[0];

    for(int ind=1;ind<n;ind++){
        for(int L=0;L<=n;L++){
            int notTake = 0 + prev[L];
            int take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= L){
                take = price[ind] + curr[L-rodLength];
            }
            curr[L] = max(notTake,take); 
        }
        prev = curr;
    }
    return prev[n];
}

// optimized aproach
int rodCutting(int n,vector<int> &prices){
    vector<int> prev(n+1,-1);
    for(int i=0;i<=n;i++) prev[i] = i*price[0];

    for(int ind=1;ind<n;ind++){
        for(int L=0;L<=n;L++){
            int notTake = 0 + prev[L];
            int take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= L){
                take = price[ind] + prev[L-rodLength];
            }
            prev[L] = max(notTake,take); 
        }
    }
    return prev[n];
}
int main(){
    return 0;
}