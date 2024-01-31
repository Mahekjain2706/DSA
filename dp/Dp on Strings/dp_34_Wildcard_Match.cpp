#include<bits/stdc++.h>
using namespace std;

// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// recursive 
// T.C O(exponential)  S.C O(n+m)
bool stringMatch(int ind1,int ind2,string s,string l){
    if(ind1<0 && ind2<0){
        return true;
    }
    if(ind2<0 && ind1>=0){
        return false;
    }
    if(ind1<0 && ind2>=0){
        for(int i=ind2;i<l.length();i++) if(l[i]!='*') return false;
        return true;
    }

    if(s[ind1]==l[ind2] || l[ind2]=='?'){
        return stringMatch(ind1-1,ind2-1,s,l);
    }else if(l[ind2]=='*'){
            return stringMatch(ind1-1,ind2,s,l) | stringMatch(ind1,ind2-1,s,l);
    }else{
        return false;
    }
}

bool isMatch(string s, string l) {
    int n = s.length(),m=l.length();
    return stringMatch(n-1,m-1,s,l);
}

// Memorization
// T.C O(n*m) S.C O(n*m)
bool stringMatch(int ind1,int ind2,string s,string l,vector<vector<int>> &dp){
    if(ind1<0 && ind2<0){
        return true;
    }
    if(ind2<0 && ind1>=0){
        return false;
    }
    if(ind1<0 && ind2>=0){
        for(int i=0;i<=ind2;i++) {if(l[i]!='*') return false;}
        return true;
    }

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s[ind1]==l[ind2] || l[ind2]=='?'){
        return dp[ind1][ind2] = stringMatch(ind1-1,ind2-1,s,l,dp);
    }
    else{ 
        if(l[ind2]=='*'){
            return dp[ind1][ind2] = stringMatch(ind1-1,ind2,s,l,dp) | stringMatch(ind1,ind2-1,s,l,dp);
        }
        else return dp[ind1][ind2] = false;
    }
}

bool isMatch(string s, string l) {
    int n = s.length(),m=l.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return stringMatch(n-1,m-1,s,l,dp);
}

// Tabulation
bool stringMatch(int ind1,int ind2,string s,string l,vector<vector<int>> &dp){
    if(ind1<0 && ind2<0){
        return true;
    }
    if(ind2<0 && ind1>=0){
        return false;
    }
    if(ind1<0 && ind2>=0){
        for(int i=0;i<=ind2;i++) {if(l[i]!='*') return false;}
        return true;
    }

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s[ind1]==l[ind2] || l[ind2]=='?'){
        return dp[ind1][ind2] = stringMatch(ind1-1,ind2-1,s,l,dp);
    }
    else{ 
        if(l[ind2]=='*'){
            return dp[ind1][ind2] = stringMatch(ind1-1,ind2,s,l,dp) | stringMatch(ind1,ind2-1,s,l,dp);
        }
        else return dp[ind1][ind2] = false;
    }
}

bool isMatch(string s, string l) {
    int n = s.length(),m=l.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,false));

    dp[0][0] = true;
    for(int i=1;i<=n;i++) dp[i][0] = false;
    for(int i=1;i<=m;i++){
        for(int ind=0;ind<=i;ind++){
            if(l[ind]!='*') dp[0][ind]=false;
        }
        dp[0][i] = true;
    }

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s[ind1-1]==l[ind2-1] || l[ind2-1]=='?'){
                dp[ind1][ind2] = dp[ind1-1][ind2-1];
            }
    else{ 
        if(l[ind2-1]=='*'){
             dp[ind1][ind2] = dp[ind1-1][ind2] | dp[ind1][ind2-1];
        }
        else dp[ind1][ind2] = false;
    }
        }
    }
    return dp[n][m];
}

// Correct Approach

bool isMatch(string s, string p) 
{
    int n = s.length();
    int m = p.length();
    int dp[2010][2010];
    memset(dp,0,sizeof(dp));
    // base case
    dp[0][0]=1; 
    // for(int i=1;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++) // discuss later 
        {
            if( i-1>=0 && j-1>=0  &&  (s[i-1]==p[j-1] || p[j-1]=='?')  )  dp[i][j] |= dp[i-1][j-1];
            else if( j-1>= 0 && p[j-1]=='*' )
            {
                for(int k=i+1;k>=-1;k--) dp[i][j]|=dp[k+1][j-1];
            }
        }
    }
    return dp[n][m];
}
int main(){
    return 0;
}