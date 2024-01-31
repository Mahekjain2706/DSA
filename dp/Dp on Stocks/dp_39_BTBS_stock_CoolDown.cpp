#include<bits/stdc++.h>
using namespace std;


// recursion
// T.C O(exponential)  S.C O(n)
int sellStocks(int ind,int buy,vector<int> &prices,int n){
    if(ind>=n) return 0;

    if(buy==1){
        return max(-prices[ind]+sellStocks(ind+1,0,prices,n) , sellStocks(ind+1,1,prices,n));
    }else{
        return max(prices[ind]+sellStocks(ind+2,1,prices,n) , sellStocks(ind+1,0,prices,n));
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return sellStocks(0,1,prices,n);
}

// memorization
// T.C O(n*2) S.C O(n)+O(n)
int sellStocks(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(ind>=n) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==1){
        return dp[ind][buy] = max(-prices[ind]+sellStocks(ind+1,0,prices,n,dp) , sellStocks(ind+1,1,prices,n,dp));
    }else{
        return dp[ind][buy] = max(prices[ind]+sellStocks(ind+2,1,prices,n,dp) , sellStocks(ind+1,0,prices,n,dp));
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return sellStocks(0,1,prices,n,dp);
}

// tabulations
// T.C O(n*2) S.C O(n)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            if(buy==1){
                dp[ind][buy] = max(-prices[ind]+ dp[ind+1][0], dp[ind+1][1]);
            }else{
                dp[ind][buy] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}

// space optimized
// T.C O(n) S.C O(6)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    vector<int> curr(2,0);

    for(int ind=n-1;ind>=0;ind--){
            if(buy==1){
                dp[ind][buy] = max(-prices[ind]+ front1[0], front1[1]);
            }else{
                dp[ind][buy] = max(prices[ind] + front2[1], front1[0]);
            }
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}

int main(){
    return 0;
}