#include<bits/stdc++.h>
using namespace std;

// given an array you have to buy stock in any day and sell any  another day find maximum profit.
// you can buy sell stock at most 2 times. find maxi profit.
// but can't buy before previous cell.

// if you sell in ith day , you buy on the minimum prices from 1st to i-1 th day

// recursive 
// T.C O(exponential) S.C O(n)
int needProfit(int ind,int buy,int cap,vector<int> &prices,int n){
    if(ind==n || cap==0){
        return 0;
    }
    if(buy==1){
        return max(needProfit(ind+1,1, cap, prices,n),-prices[ind] + needProfit(ind+1,0, cap, prices,n));
    }else{
        return max(needProfit(ind+1,0, cap, prices,n),+prices[ind] + needProfit(ind+1,1, cap-1, prices,n));
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return needProfit(0,1,2,prices,n);
}

// Memorization
// T.C O(N*2*3) S.C O(n*2*3) + O(n)
int needProfit(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(ind==n || cap==0){
        return 0;
    }
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    if(buy==1){
        return dp[ind][buy][cap] = max(needProfit(ind+1,1, cap, prices,n,dp),-prices[ind] + needProfit(ind+1,0, cap, prices,n,dp));
    }else{
        return dp[ind][buy][cap] = max(needProfit(ind+1,0, cap, prices,n,dp),+prices[ind] + needProfit(ind+1,1, cap-1, prices,n,dp));
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return needProfit(0,1,2,prices,n,dp);
}

// Tabulations
// T.C O(N*2*3) S.C O(N)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,    vector<vector<int>>(2,vector<int>(3,0)));

    for(int ind=0;ind<n;ind++){
        for(int buy=0;buy<2;buy++){
            dp[ind][buy][0] = 0;
        }
    }

    for(int buy=0;buy<2;buy++){
        for(int cap=0;cap<3;cap++){
            dp[n][buy][cap] = 0;
        }
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){

            if(buy==1){
                dp[ind][buy][cap] = max(dp[ind+1][1][cap],-prices[ind] + dp[ind+1][0][cap]);
            }else{
                dp[ind][buy][cap] = max(dp[ind+1][0][cap],+prices[ind] + dp[ind+1][1][cap-1]);
            } 
            }
        }
    }
    return dp[0][1][2];
}

// space optimization
// T.C O(n*2*3) S.C O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));


    for(int ind=0;ind<n;ind++){
        for(int buy=0;buy<2;buy++){
            prev[buy][0] = 0;
        }
    }

    for(int buy=0;buy<2;buy++){
        for(int cap=0;cap<3;cap++){
            prev[buy][cap] = 0;
        }
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){

            if(buy==1){
                curr[buy][cap] = max(prev[1][cap],-prices[ind] + prev[0][cap]);
            }else{
                curr[buy][cap] = max(prev[0][cap],+prices[ind] + prev[1][cap-1]);
            } 
            }
        }
        prev = curr;
    }
    return prev[1][2];
}

// Optimised
// as we can perform   b s b s
// so accord to index  0 1 2 3
// odd index -> sell , even index -> buy
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(4,0));

    for(int ind=0;ind<=n;ind++){
        dp[ind][4] = 0;
    }

    for(int buy=0;buy<4;buy++){
        dp[n][buy] = 0;
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<4;buy++){

            if(buy%2==1){
                dp[ind][buy][cap] = max(dp[ind+1][1][cap],-prices[ind] + dp[ind+1][0][cap]);
            }else{
                dp[ind][buy][cap] = max(dp[ind+1][0][cap],+prices[ind] + dp[ind+1][1][cap-1]);
            } 
        }
    }
    return dp[0][4];
}


int main(){
    return 0;
}