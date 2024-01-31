#include<bits/stdc++.h>
using namespace std;

// print Longest Incresing subsequence


// from each index check the elemnt whihc is smaller then it and length of 
// alias possible till that index than find max of them to get length of lis

// now we are taking hash array which store the backtrackting from where maximum come 
// and then back track to hash array which stores the index and push_back element at index into the queue.

// T.C O(n*n) S.C O(2*n)
vector<int> lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1) , hash(n);
    int maxi = 0;
    int lastIndex = 0;
    for(int i=0;i<n;i++){
        for(int prev =0;prev<i;prev++){
            if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[i]){
                dp[i] =  1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while(hash[lastIndex] !=lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(),lis.end());
    return lis;
}


int main(){
    return 0;
}