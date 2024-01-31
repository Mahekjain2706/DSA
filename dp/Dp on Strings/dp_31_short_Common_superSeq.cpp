#include<bits/stdc++.h>
using namespace std;

// Shortest common supersequence
// -> lis and print lis
// s1 -> brute s2 ->  groot  -> bgruoote
// s1 -> bleed s2 -> blue   -> bleued
// common guyz should be taken once -> lis
// length of super sequence -> n + m - lis
// print lcs 

// with the help of dp table check if same then take it once else take it .
// print lcs

int longestSubseq(string s ,string l){
    int n = s.length(),m=l.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++) dp[0][j] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==l[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0 + max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    string ans="";

    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==l[j-1]){
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+= s[i-1];
            i--;
        }
        else{
            ans+=l[j-1];
            j--;
        }
    }

    while(i>0){
        ans+=s[i-1];
        i--;
    }
    while(j>0){
        ans+=l[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
 
int main(){
    return 0;
}