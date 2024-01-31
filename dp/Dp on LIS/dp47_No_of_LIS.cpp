#include<bits/stdc++.h>
using namespace std;
// IMP
// no of lis subsequence
int findNumberOfLIS(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,1),cnt(n,1);
    int maxi = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                cnt[i] += cnt[j];
            }
        }
        if(dp[i]>maxi) maxi = max(maxi,dp[i]);
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi) cnt1+= cnt[i];
    }
    return cnt1;
}

int main(){
    return 0;
}