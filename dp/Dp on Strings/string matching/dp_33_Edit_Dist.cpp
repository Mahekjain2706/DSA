#include<bits/stdc++.h>
using namespace std;

// edit Distance
// given two strings , uyou can take any char and add into s1 , remove any character from s1 , replace any character
// Minimum steps to convert s1 -> s2

// 1. delete everything then insert elemnt in s2. N + M operations.
// s1 = "horse" s2="ros"  replace h -> r , remove r,remove e -> minimum operation
// string matching

// recursion
// T.C O(exponential)  S.C O(n+m)
int miniOper(int ind1,string word1,int ind2,string word2){
    if(ind1<0){
        return ind2+1;
    }
    if(ind2<0){
        return ind1+1;
    }

    if(word1[ind1]==word2[ind2]){
        return 0 + miniOper(ind1-1,word1,ind2-1,word2);
    }else{
        int insert = 1 + miniOper(ind1,word1,ind2-1,word2);
        int replace = 1 + miniOper(ind1-1,word1,ind2-1,word2);
        int deleteO = 1 + miniOper(ind1-1,word1,ind2,word2);
        return min(insert,min(replace,deleteO));
    }
}
int minDistance(string word1, string word2) {
    int n = word1.length(),m = word2.length();
    return miniOper(n-1,word1,m-1,word2);
}


// memorization
// T.C o(n*m) S.C O(n*m)+O(n+m)
int miniOper(int ind1,string word1,int ind2,string word2,vector<vector<int>> &dp){
    if(ind1<0){
        return ind2+1;
    }
    if(ind2<0){
        return ind1+1;
    }

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(word1[ind1]==word2[ind2]){
        return dp[ind1][ind2] = 0 + miniOper(ind1-1,word1,ind2-1,word2,dp);
    }else{
        int insert = 1 + miniOper(ind1,word1,ind2-1,word2,dp);
        int replace = 1 + miniOper(ind1-1,word1,ind2-1,word2,dp);
        int deleteO = 1 + miniOper(ind1-1,word1,ind2,word2,dp);
        return dp[ind1][ind2] = min(insert,min(replace,deleteO));
    }
}
int minDistance(string word1, string word2) {
    int n = word1.length(),m = word2.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return miniOper(n-1,word1,m-1,word2,dp);
}

// Tabulation
// T.C O(n*m) S.C O(n*m)
int minDistance(string word1, string word2) {
    int n = word1.length(),m = word2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // one based indexing
    for(int j=0;j<=m;j++) dp[0][j] = j;
    for(int i=0;i<=n;i++) dp[i][0] = i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                int insert = 1 + dp[i][j-1];
                int replace = 1 + dp[i-1][j-1];
                int deleteO = 1 + dp[i-1][j];
                dp[i][j] = min(insert,min(replace,deleteO));
            }
        }
    }
    
    return dp[n][m];
}

// space optimization
int minDistance(string word1, string word2) {
    int n = word1.length(),m = word2.length();
    vector<int> prev(m+1,0),curr(m+1,0);
    // one based indexing
    for(int j=0;j<=m;j++) dp[0][j] = j;

    for(int i=1;i<=n;i++){
        curr[0] = i;
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j] = 0 + prev[j-1];
            }
            else{
                int insert = 1 + curr[j-1];
                int replace = 1 + prev[j-1];
                int deleteO = 1 + prev[j];
                dp[i][j] = min(insert,min(replace,deleteO));
            }
        }
        prev =curr;
    }
    
    return prev[m];
}

// no futher 1-d space optimization

int main(){
    return 0;
}