#inlcude<bits/stdc++/h>
using namespace std;

// given an array you have to buy stock in one day and sell on another day find maximum profit.

// if you sell in ith day , you buy on the minimum prices from 1st to i-1 th day

// T.C O(n) S.C O(1)
int Buy_Sell_Stock(vector<int> prices){
    int n = prices.size();
    int curr = prices[0];
    int profit = 0;

    for(int i=1;i<n;i++){
        if(prices[i]<curr) curr = prices[i];

        profit = max(profit,prices[i]-curr);
    }
    return profit;
}

int main(){
    return 0;
}