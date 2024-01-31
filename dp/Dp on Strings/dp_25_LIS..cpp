#include<bits/stdc++.h>
using namespace std;

// subsequence in string - if string can be consecutive and maintain the order
// so to find subsequence we find power set

// Longest common subsequence 
// Given two string and we have to find common subsequence among both of them.

// 1. generate all subsequences
// 2. Generate all subsequences and  compare on way
// -> we use parameter to generate them
// -> do comparasion characterwise
// -> match then 1 + on back , not match then try both way first array ind1-1 or ind2-1 + 0; and take max.

// recursion
// T.C O(2^n * 2^m) ~ exponantial 
int findMax(int ind1,string a,int ind2,string b){
    if(ind1<0 || ind2<0){
        return 0;
    }

    if(a[ind1]==b[ind2]){
       return  1 + findMax(ind1-1,a,ind2-1,b);
    }
    else{
       return  0 + max(findMax(ind1-1,a,ind2,b),findMax(ind1,a,ind2-1,b));
    }
}
int longestSubsequence(string a,string b){
    int n = a.length() , m = b.length();
    findMax(n-1,a,m-1,b);
}

// memorization
// T.C O(n*m)   S.C O(n*m)+O(n*m) auxillary
int commonSequence(int ind1,string text1,int ind2,string text2,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2] = 1 + commonSequence(ind1-1,text1,ind2-1,text2,dp);
    }
    else{
        return dp[ind1][ind2] = 0 + max(commonSequence(ind1-1,text1,ind2,text2,dp),commonSequence(ind1,text1,ind2-1,text2,dp));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(),m = text2.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return commonSequence(n-1,text1,m-1,text2,dp);
}

// Tabulation 
// T.C O(n*m)   S.C O(n+m)
// shifting of index
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(),m = text2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int ind=0;ind<=n;ind++) dp[ind][0] =  0;
    for(int ind=0;ind<=m;ind++) dp[0][ind] = 0;

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
            }
            else{
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }

    return dp[n][m];
}

// space optimization
// T.C O(n*m) S.C O(n+m)
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(),m = text2.length();
    vector<int> prev(m+1,0),curr(m+1,0);

    for(int ind=0;ind<=m;ind++) prev[ind] = 0;

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                curr[ind2] = 1 + prev[ind2-1] ;
            }
            else{
                curr[ind2] = 0 + max(prev[ind2],curr[ind2-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main(){
    return 0;
}