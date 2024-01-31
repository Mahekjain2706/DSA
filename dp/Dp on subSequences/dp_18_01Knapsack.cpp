#include <bits/stdc++.h>
using namespace std;

// recursion
// T.C O(2^n) S.C O(1)
int func(int ind, int W, int wt[], int val[], int n)
{
    // base
    if (ind < 0)
        return 0;
    if (W == 0)
        return 0;

    int notTake = func(ind - 1, W, wt, val, n);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + func(ind - 1, W - wt[ind], wtval, n);
    }
    return max(notTake, take);
}
int knapSack(int W, int wt[], int val[], int n)
{
    return func(n - 1, W, wt, val, n);
}

// Memoization
// T.C O(n*n)  S.C O(n*n)+O(n) recursion stack space
int func(int ind, int W, int wt[], int val[], int n)
{
    // base
    if (ind < 0)
        return 0;
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTake = func(ind - 1, W, wt, val, n);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + func(ind - 1, W - wt[ind], wtval, n);
    }
    return dp[ind][W] = max(notTake, take);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // memset(dp,-1,sizeof(dp));
    return func(n - 1, W, wt, val, n);
}

// tabulation
// T.C O(n*n) S.C O(n*n)
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    for (int i = wt[0]; i < W + 1; i++)
        dp[0][i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wei = 0; wei <= W; wei++)
        {
            int notTake = dp[ind - 1][wei];
            int take = 0;
            if (wt[ind] <= wei)
            {
                take = val[ind] + dp[ind - 1][wei - wt[ind]];
            }
            dp[ind][wei] = max(notTake, take);
        }
    }
    return dp[n - 1][W];
}

// space complexitiy 
// T.C O(n*n)  S.C O(n)
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, -1),curr(W+1,-1);
    for (int i = wt[0]; i < W + 1; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wei = 0; wei <= W; wei++)
        {
            int notTake = prev[wei];
            int take = 0;
            if (wt[ind] <= wei)
            {
                take = val[ind] + prev[wei - wt[ind]];
            }
            curr[wei] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[W];
}

// optimized 
// as each block depend on above row not on previous column so 
// 1. we can run loop opposite direction also
// as if i want to curr i just ned prev not curr 
// 2. no curr array needed we use prev only
// single array space optimization
// T.C O(n*n) S.C O(n)->one array
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, -1);
    for (int i = wt[0]; i < W + 1; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wei = W; wei>=0; wei--)
        {
            int notTake = prev[wei];
            int take = 0;
            if (wt[ind] <= wei)
            {
                take = val[ind] + prev[wei - wt[ind]];
            }
            prev[wei] = max(notTake, take);
        }
    }
    return prev[W];
}

int main()
{
    return 0;
}