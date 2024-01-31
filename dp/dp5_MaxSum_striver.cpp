#include<bits/stdc++.h>
using namespace std;

// given and array n integers and you have to return subsequence of maximum sum  but non-off the elements are adjacent.

// lets try all subsequecences 
// express in terms of index , do stuffs on that index ,return best

// Recurssion
// T.C O(2^n)
int function1(int ind,vector<int> arr){
    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    int pick = arr[ind] + function1(ind-2,arr);
    int notPick = 0 + function1(ind-1,arr);

    return max(pick,notPick);
}
int maximumSum(vector<int> arr){
    int n = arr.size();
    return function1(n-1,arr);
}

// dp array // memorization
// T.C O(n*n) S.C O(n)
int function2(int ind,vector<int> &arr,vector<int> &dp){
    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];
    int pick = arr[ind] + function2(ind-2,arr,dp);
    int notPick = 0 + function2(ind-1,arr,dp);

    return dp[ind] = max(pick,notPick);
}
int maximumSum1(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    return function2(n-1,arr,dp);
}

// Tabulation
// T.C O(n) S.C O(n)
int maximumSum2(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    dp[0] = arr[0];

    for(int i=1;i<n;i++){
        int take = arr[i];
        if(i>1) take +=dp[i-2];
        int notTake = 0 + dp[i-1];

        dp[i] = max(take,notTake);
    }
    return dp[n];
}

// space optimization
int maximumSum2(vector<int> arr){
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i=0;i<n;i++){
        int take = arr[i] ;
        if(i>1) take +=prev2;
        int notTake = 0 + prev;

        int curr = max(take,notTake);
        prev2 = prev;
        prev  = curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }

    return 0;
}