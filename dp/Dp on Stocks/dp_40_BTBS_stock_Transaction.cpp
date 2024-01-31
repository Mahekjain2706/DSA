#include<bits/stdc++.h>
using namespace tsd;

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// 1. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// 2. The transaction fee is only charged once for each stock purchase and sale.
 

// recursive
// T.C O(exponential)  S.C O(n)
int transaction(int ind,int buy,int feevector<int> &prices,int n){
    if(ind>=n){
        return 0;
    }
    if(buy){
        return max(-prices[ind]+transaction(ind+1,0,fee,prices,n) , transaction(ind+1,1,fee,prices,n));
    }
    else{
        return max(prices[ind] - fee + transaction(ind+1,1,fee,prices,n) , transaction(ind+1,0,fee,prices,n));
    }
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    return transaction(0,1,fee,prices,n);
}

// memorization
// T.C O(n*2) S.C O(n*2)+O(n)
int transaction(int ind,int buy,int fee,vector<int> &prices,int n, vector<vector<int>> &dp){
    if(ind>=n){
        return 0;
    }
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy){
        return dp[ind][buy] = max(-prices[ind]+transaction(ind+1,0,fee,prices,n,dp) , transaction(ind+1,1,fee,prices,n,dp));
    }
    else{
        return dp[ind][buy] = max(prices[ind] - fee + transaction(ind+1,1,fee,prices,n,dp) , transaction(ind+1,0,fee,prices,n,dp));
    }
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return transaction(0,1,fee,prices,n,dp);
}

// Tabulation
// T.C O(n*2) S.C O(n*2)
int maxProfit(vector<int>& prices, int fee) {
     int n = prices.size();
     vector<vector<int>> dp(n+1,vector<int>(2,0));
     for(int ind=n-1;ind>=0;ind--){
         for(int buy=0;buy<=1;buy++){
             if(buy){
                 dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
             }
             else{
                 dp[ind][buy] = max(prices[ind] - fee + dp[ind+1][1] , dp[ind+1][0]);
             }
         }
     }
     return dp[0][1];
}

// space optimization
// T.C O(n*2) S.C O(4)
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> ahead(2,0);
    vector<int> curr(2,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                curr[buy] = max(-prices[ind] + ahead[0], ahead[1]);
            }
            else{
                curr[buy] = max(prices[ind] - fee + ahead[1] , ahead[0]);
            }
        }
        ahead = curr;
    }
    return curr[1];
}


int main(){
    return 0;
}