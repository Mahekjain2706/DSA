#include<bits/stdc++.h>
using namespace std;

// with the help of subset sum if we find the value of target which can be possible then 
// we can return the difference of taregt and remain and find the minimumm.

// each dp row col represent that before that indeex target can achieve or not.
int minSubsetSumDifference(vector<int>& nums, int n)
{
	int sum = 0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    int k = sum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][nums[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(nums[i]<=j){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = (take | notTake);
        }
    }
    int final = 1e9;
    // as after half same thing is repeating so for optimization.
    for(int i=0;i<=k/2;i++){
        if(dp[n-1][i]==true){
            int s1 = i;
            int s2 = sum -i; 
            final = min(final,abs(s1-s2));
        }
    }
    return final;
}

int main(){
    return 0;
}