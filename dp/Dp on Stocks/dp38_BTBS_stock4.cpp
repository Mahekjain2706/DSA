#include<bits/stdc++.h>
using namespace std;

// given an array you have to buy stock in any day and sell any  another day find maximum profit.
// you can buy sell stock atmost K no. of times find maxi profit.
// but can't buy before previous cell.

// if you sell in ith day , you buy on the minimum prices from 1st to i-1 th day

// recursive 
// T.C O(exponential) S.C O(n)
sellprices(int ind,vector<int>&prices,int buy,int cap){
        if(ind==n|| cap==0){
            return 0;
        }

        if(buy){
            return max(sellprices(ind+1,prices,1,cap),-prices[ind] + sellprices(ind+1,prices,0,cap));
        }else{
            return max(sellprices(ind+1,prices,0,cap) , prices[ind] + sellprices(ind+1,prices,1,cap-1));
        }
} 

int but_sell_stock(vecto<int> prices,int k){
    return sellpreices(0,prices,1,k);
}

// memorization
// T.C O(n*k*2) S.C O(n*k*2) + O(n)
int sellprices1(int ind,vector<int>&prices,intbuy,int cap, vector<vector<vector<int>>> &dp){
    if(ind==prices.size()|| cap==0){
        return 0;
    }
    if(dp[ind][cap][buy]!=-1) return dp[ind][cap][buy];
    if(buy){
        return dp[ind][cap][buy] = max(sellprices1(ind+1,prices,1,cap,dp),-prices[ind] + sellprices1(ind+1,prices,0,cap,dp));
    }else{
        return dp[ind][cap][buy] = max(sellprices1(ind+1,prices,0,cap,dp) , prices[ind] + sellprices1(ind+1,prices,1,cap-1,dp));
    }
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
    return sellprices1(0,prices,1,k,dp);
}

// tabulation
// T.c O(n*k*3) S.C O(n*k*3)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

    for(int cap=0;cap<k;cap++){
        for(int buy=0;buy<=1;buy++){
            dp[n][buy][cap]=0;
        }
    }
    for(int ind=0;ind<n;ind++){
        for(int buy=0;buy<=1;buy++){
            dp[ind][buy][0] = 0;
        }
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int cap=1;cap<=k;cap++){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[ind][buy][cap] = max(dp[ind+1][1][cap],-prices[ind] + dp[ind+1][0][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(dp[ind+1][0][cap] , prices[ind] + dp[ind+1][1][cap-1]);
                }
            }
        }
    }

    return dp[0][1][k];
}

// space optimization
// T>c o(n*2*3) S.C O(n)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2,vector<int>(k+1,0));
    vector<vector<int>> curr(2,vector<int>(k+1,0));

    for(int cap=0;cap<k;cap++){
        for(int buy=0;buy<=1;buy++){
            ahead[buy][cap]=0;
        }
    }
    // for(int ind=0;ind<n;ind++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[ind][buy][0] = 0;
    //     }
    // }

    for(int ind=n-1;ind>=0;ind--){
        for(int cap=1;cap<=k;cap++){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy][cap] = max(ahead[1][cap],-prices[ind] + ahead[0][cap]);
                }
                else{
                    curr[buy][cap] = max(ahead[0][cap] , prices[ind] + ahead[1][cap-1]);
                }
            }
        }
        ahead = curr;
    }

    return ahead[1][k];
}

// optimized
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*(k)+1,0));


    for(int ind=n-1;ind>=0;ind--){
        for(int cap=2*k-1;cap>=0;cap--){
                if(cap%2==0){
                    dp[ind][cap] = max(dp[ind+1][cap],-prices[ind] + dp[ind+1][cap+1]);
                }
                else{
                    dp[ind][cap] = max(dp[ind+1][cap] , prices[ind] + dp[ind+1][cap+1]);
                }
        }
    }

    return dp[0][0];
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2*(k)+1,0);
    vector<int> curr(2*(k)+1,0);

    for(int ind=n-1;ind>=0;ind--){
        for(int cap=2*k-1;cap>=0;cap--){
            if(cap%2==0){
                curr[cap] = max(ahead[cap],-prices[ind] + ahead[cap+1]);
            }
            else{
                curr[cap] = max(ahead[cap] , prices[ind] + ahead[cap+1]);
            }
        }
        ahead = curr;
    }

    return ahead[0];
}


int main(){

    return 0;
}