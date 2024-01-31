#include<bits/stdc++.h>
using namespace std;

// find the length of longest common subsequence in log(n) complexity by Binary search algorithm.

int long_substr(vector<int> &nums){
    int n = nums.size();
    vector<int> curr;
    curr.push_back(nums[0]);

    int ans = 1;
    for(int i=1;i<n;i++){
        int bk = curr.back();
        if(nums[i] > bk){
            curr.push_back(nums[i]);
            ans = max(ans,(int)curr.size());
        }else{
            auto it = lower_bound(curr.begin(),curr.end(),nums[i]) - curr.begin();
            curr[it] = nums[i];
        }
    }
    return ans;
}

int main(){
    return 0;
}