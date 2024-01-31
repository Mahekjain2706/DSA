#include<bits/stdc++.h>
using namespace std;

// we can insert any no of char to make palindrome and we have to find minimum insertion to make it palindrome.
// 1. add same string and check if element not same c+=1;but we want minimum operation

// 2. keep the longest palindrome portion intacked
// and reverse not palindromic portion and reverse and put it.
// ans will be (n - longest palindromic sequence)

// tabulation 
// T.C O(n*n) S.C O(n*n)
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
int minimumInsertion(string s){
    retrun (s.length() - longestPalindromeSubseq(s));
}

// space optimization
// t.C O(n*n) S.C O(n)
int longestPalindromeSubseq(string s) {
    string l = "";
    reverse(s.begin(),s.end());
    l = s;
    reverse(s.begin(),s.end());
    int n = s.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=n;i++) {prev[i] = 0;}

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
int minInsertions(string s) {
    int n = s.length();
    return (n-longestPalindromeSubseq(s));
}


int main(){

    return 0;
}