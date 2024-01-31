#include<bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence
// generate all subsequence and check palindromic or not.

// else apply lcs

// recursion
// T.C O(2^n) S.C O(n)
int longestSubseq(int ind1,string s,int ind2,string l){
    if(ind1<0 || ind2<0) return 0;
    if(s[ind1]==l[ind2]){
        return 1 + longestSubseq(ind1-1,s,ind2-1,l);
    }
    else{
        return 0 + max(longestSubseq(ind1-1,s,ind2,l),longestSubseq(ind1,s,ind2-1,l));
    }
}
int longestPalindromeSubseq(string s) {
    string l = "";
    reverse(s.begin(),s.end());
    l = s;
    reverse(s.begin(),s.end());
    int n = s.length();
    return longestSubseq(n-1,s,n-1,l);
}

// Memorization
// T.C O(n*n) S.C O(n*n)+O(n)
int longestSubseq(int ind1,string s,int ind2,string l,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0) return 0;

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s[ind1]==l[ind2]){
        return dp[ind1][ind2] = 1 + longestSubseq(ind1-1,s,ind2-1,l,dp);
    }
    else{
        return dp[ind1][ind2] = 0 + max(longestSubseq(ind1-1,s,ind2,l,dp),longestSubseq(ind1,s,ind2-1,l,dp));
    }
}
int longestPalindromeSubseq(string s) {
    string l = "";
    reverse(s.begin(),s.end());
    l = s;
    reverse(s.begin(),s.end());
    int n = s.length();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return longestSubseq(n-1,s,n-1,l,dp);
}

// tabulation
// T.C O(n*n) S.C O(n)
int longestPalindromeSubseq(string s) {
    string l = "";
    reverse(s.begin(),s.end());
    l = s;
    reverse(s.begin(),s.end());
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++) {dp[i][0] = 0; dp[0][i] = 0;}

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=n;ind2++){
            if(s[ind1-1]==l[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            }
            else{
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }
    return dp[n][n];
}


// space optimization
// T.C O(n*n) S.C O(n)
int longestPalindromeSubseq(string s) {
    string l = "";
    reverse(s.begin(),s.end());
    l = s;
    reverse(s.begin(),s.end());
    int n = s.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=n;i++) { prev[i] = 0;}

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=n;ind2++){
            if(s[ind1-1]==l[ind2-1]){
                curr[ind2] = 1 + prev[ind2-1];
            }
            else{
                curr[ind2] = 0 + max(prev[ind2],curr[ind2-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}

int main(){

    return 0;
}