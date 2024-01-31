#include<bits/stdc++.h>
using namespace std;

// Partition Array for Maximum Sum
// given array such that length of partition is not more than k
// arr[1,15,7,9,2,5,10] k=3 -> [1,15] [7,9,2] [5,10]
// [15,15][9,9,9][10,10] -> maximum in each array and add this 
// sum of subarray is -> length of subarray * maxiElement

// Recursive 
// T.C o(exponential) S.C O(n)
int parti(int i,vector<int> &nums,int k,int n){
    if(i==n) return 0;
    int len =0,maxi=INT_MIN;
    int maxAns = INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,nums[i]);
        int sum = (len*maxi) + parti(j+1,nums,k,n);
        maxAns = max(maxAns,sum);
    }
    return maxAns;
}
int maxiSum(vector<int> &nums,int n){
    return parti(0,nums,k,n);
}


// memorization
// T.C O(n)*O(k) S.C O((n)+(n))
int parti(int i,vector<int> &nums,int k,int n,vector<int> &dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int len =0,maxi=INT_MIN;
    int maxAns = INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,nums[j]);
        int sum = (len*maxi) + parti(j+1,nums,k,n,dp);
        maxAns = max(maxAns,sum);
    }
    return dp[i] = maxAns;
}
int maxSumAfterPartitioning(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n,-1);
    return parti(0,nums,k,n,dp);
}

// tabulation
// T.C O(n*k) S.C O(n+n)
int maxSumAfterPartitioning(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n+1,0);

    for(int i=n-1;i>=0;i--){
        int len =0,maxi=INT_MIN;
        int maxAns = INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,nums[j]);
            int sum = (len*maxi) + dp[j+1];
            maxAns = max(maxAns,sum);
        }
        dp[i] = maxAns;
    }    
    return dp[0];
}


int main(){
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    auto bfs = [&](vector<vector<int>>& safeness_grid) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        safeness_grid[0][0] = 0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int new_safeness = min(safeness_grid[r][c], abs(nr - (n - 1)) + abs(nc - (n - 1)));
                    if (new_safeness > safeness_grid[nr][nc]) {
                        safeness_grid[nr][nc] = new_safeness;
                        q.push({nr, nc});
                    }
                }
            }
        }
    };

    // Initialize the safeness grid with negative infinity values.
    vector<vector<int>> safeness_grid(n, vector<int>(n, INT_MIN));

    // Run BFS to calculate safeness factors for each cell.
    bfs(safeness_grid);

    // The maximum safeness factor of all paths leading to (n - 1, n - 1).
    return safeness_grid[n - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}
    };

    cout << maximumSafenessFactor(grid) << endl;  // Output: 2

    return 0;
}
