#include<bits/stdc++.h>
using namespace std;

// Largest Divisible subset -> longest increasing subseq

// given an array and we have to find largest subset in which each element divide each other.
// array will have each distinct element
// arr[i] % arr[j] == 0  or arr[j] % arr[i] == 0;

// arr = {1,16,7,8,4}
// -> {1,16,8,4} ans or any jumble

vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int lastIndex = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i] < 1 + dp[j]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j; 
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
}

int main(){
    return 0;
}