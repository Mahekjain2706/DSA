#include <bits/stdc++.h>
using namespace std;

// weight , value given  of Items and capacity of bag given -> infinite supply of any item , not break the item,
// Recursion
// T.C O(2^n) S.C O(n) auxillary stack space
int maxiValue(int ind, vector<int> &weight, vector<int> &value, int W)
{
    if (ind == 0)
    {
        if (W % weight[0] == 0)
            return (W / weight[0]) * value[0];
        return 0;
    }

    int notTake = 0 + maxiValue(ind - 1, weight, value, W);
    int take = 0;
    if (weight[ind] <= W)
    {
        take = value[ind] + maxiValue(ind, weight, value, W - weight[ind]);
    }
    return max(notTake, take);
}
int unboundedKnapsack(vector<int> &weight, vector<int> value, int W)
{
    int n = weight.size();
    return maxiValue(n - 1, weight, value, W);
}

// Mmeoization
// T.C O(n*n) S.C O(n*n) + O(n)
int unbounded(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (ind == 0)
        return (W / wt[ind]) * val[ind];

    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notTake = 0 + unbounded(ind - 1, W, val, wt, dp);
    int take = 0;
    if (wt[ind] <= W)
    {
        take = val[ind] + unbounded(ind, W - wt[ind], val, wt, dp);
    }

    return dp[ind][W] = max(take, notTake);
}
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return unbounded(N - 1, W, val, wt, dp);
}

// Tabulation
// T.C O(n*n) S.C O(n)
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));

    for (int we = 0; we <= W; we++)
        dp[0][we] = ((int)(W / wt[0])) * val[0];

    for (int ind = 1; ind < N; ind++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + dp[ind - 1][j];
            int take = 0;
            if (wt[ind] <= j)
            {
                take = val[ind] + dp[ind][j - wt[ind]];
            }
            dp[ind][j] = max(take, notTake);
        }
    }
    return dp[N - 1][W];
}

// space optimization
// T.C O(n*n) S.C O(n)
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W + 1, -1),curr(W+1,-1);

    for (int we = 0; we <= W; we++)
        prev[we] = ((int)(W / wt[0])) * val[0];

    for (int ind = 1; ind < N; ind++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + prev[j];
            int take = 0;
            if (wt[ind] <= j)
            {
                take = val[ind] + curr[j - wt[ind]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}


// for every curr index we need curr row prev values and prev col element of prev so we dont need full previous row.
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W + 1, -1);

    for (int we = 0; we <= W; we++)
        prev[we] = ((int)(W / wt[0])) * val[0];

    for (int ind = 1; ind < N; ind++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + prev[j];
            int take = 0;
            if (wt[ind] <= j)
            {
                take = val[ind] + prev[j - wt[ind]];
            }
            prev[j] = max(take, notTake);
        }
    }
    return prev[W];
}



int main()
{

    return 0;
}