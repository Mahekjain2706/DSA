#include <bits/stdc++.h>
using namespace std;

// i+1 th stair height is Height[i] 
// if frog jump from i th to j th stair Height[i-1]-Height[j-1] energy lost
// frog jump 1 or 2 stair at a time
// MINIMUM energy used to reach 1 to n

// Q. why greedy not work
// in this we take minimum path give wrong answer and want to try all possible ways.

// recurance // t.c = O(nlog(n)) s.c = O(n)
int frog(int ind,vector<int>Height){
    if(ind==0) return 0;

    int left = frog(ind-1,Height) + abs(Height[ind]-Height[ind-1]);
    int right = INT_MAX;
    if(ind>1){
     right = frog(ind-2,Height) + abs(Height[ind]-Height[ind-2]);}

    return min(left,right);
}

// dp memorization top down // t.c = O(n) s.c = O(n) + O(n)
int frog(int ind,vector<int> &Height,vector<int>&dp){
    if(ind == 0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int left = frog(ind-1,Height) + abs(Height[ind]-Height[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
    right = frog(ind-2,Height) + abs(Height[ind]-Height[ind-2]);
    }

    return dp[ind] = min(left,right);
}
int frogjump(int n,vector<int> &Height){
    vector<int> dp(n+1,-1);
    frog(n-1,Height,dp); 
}

// dp tabulation bottom up // t.c = O(n) s.c = O(n) + O(n)
// see the edge case // s.c= O(n) t.c= O(n)
int frog(int n,vector<int>Height){
   vector<int> dp(n,0);
   dp[0]=0;
   for(int i=1;i<n;i++){
    int fs = dp[i-1] + abs(Height[i]-Height[i-1]);
    int ss = INT_MAX;
    if(i>1){
        ss = dp[i-2] + abs(Height[i]-Height[i-2]);
    }
    dp[i] = min(fs,ss);
   }
   return dp[n-1];
}

int frog(int n,vector<int>Height){
    int curr = 0;
    int prev = 0;
    int prev2 = 0;
   for(int i=1;i<n;i++){
    int fs = prev + abs(Height[i]-Height[i-1]);
    int ss = INT_MAX;
    if(i>1){
        ss = prev2 + abs(Height[i]-Height[i-2]);
    }
    curr = min(fs,ss);
    prev2 = prev;
    prev = curr;
   }
   return prev;
}

// reduce stack space



int main(){

    int n;
    cin>>n;
    vector<int> Height;

    for(int i=0;i<n;i++){
        cin>>Height[i];
    }
    // cout<< frogjump(n-1,Height);

    
    // optimized
    int prev=0,prev2=0;

    for(int i=1;i<n;i++){
        int fs = prev + abs(Height[i] - Height[i-1]);
        int ss = prev2 + abs(Height[i] - Height[i-2]);

        int curr = min(fs,ss);
        prev = curr;
        prev2 = prev;
    }
    cout<< prev << endl;
    
    return 0;
}


// Question
// i to i+1
// i to i+2 , i+3 , i+4 ........ i+k