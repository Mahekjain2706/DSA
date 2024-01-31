#inlcude<bits/stdc++/h>
using namespace std;

// given an array you have to buy stock in any day and sell any  another day find maximum profit.
// you can buy sell stock any no. of times find maxi profit.
// but can't buy before previous cell.

// if you sell in ith day , you buy on the minimum prices from 1st to i-1 th day

int buy_Sell_Stock(vector<int> &prices){
    int n = prices.size();
    int curr = prices[0];
    int profit = 0;

    for(int i=1;i<n;i++){
        if(prices[i-1]>prices[i]){
            profit += prices[i-1] - curr;
            curr = prices[i];
        }
    }
    profit += prices[n-1] - curr;
    return profit;
}
// or
int buy_Sell_Stock(vector<int> &prices){
    int n = prices.size();
    int profit = 0;

    for(int i=0;i<n-1;i++){
        if(prices[i+1]>prices[i]){
            profit += prices[i+1] - prices[i];
        }
    }
    return profit;
}


// recursive
// T.C O(2^n) s.C O(n)
int f(int  ind,int buy,vector<int> &prices,int n){
    if(ind==n) return 0;

    int profit = 0;
    if(buy){
        profit = max( -prices[ind] + f(ind+1,0,prices,n), 0 + f(ind+1,1,prices,n));
    }else{
        profit = max(prices[ind] + f(ind+1,1,prices,n), 0 + f(ind+1,0,prices,n));
    }
    return profit;
}
int buy_sell_stock(vector<int> &prices){
    return f(0,1,prices,n);
}

// memorization
// T.C O(n*2) S.C O(n*2) + o(n)
int f(int  ind,int buy,vector<int> &prices,int n, vector<vector<int>> &dp){
    if(ind==n) return 0;

    int profit = 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy){
        profit = max( -prices[ind] + f(ind+1,0,prices,n,dp), 0 + f(ind+1,1,prices,n,dp));
    }else{
        profit = max(prices[ind] + f(ind+1,1,prices,n,dp), 0 + f(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy] = profit;
}
int buy_sell_stock(vector<int> &prices){
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,n,dp);
}

// tabulation 
// T.C O(n*2) S.C O(n*2)
int buy_sell_stock(vector<int> &prices){
    vector<vector<int>> dp(n,vector<int>(2,-1));

    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            if(buy){
            profit = max( -prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        }else{
            profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
        }
        dp[ind][buy] = profit; 
            }
    }
    return dp[n][2];
}

// space optimization
int buy_sell_stock(vector<int> &prices){
    vector<vector<int>> ahead(2,0),curr(2,0);

    ahead[0] = ahead[1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            if(buy){
            profit = max( -prices[ind] + ahead[0], 0 + ahead[1]);
        }else{
            profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
        }
        curr[buy] = profit; 
            }
            ahead = curr;
    }
    return ahead[1];
}

int main(){
    return 0;
}