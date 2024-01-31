#include<bits/stdc++.h>
using namespace std;

// given two strings we have to convert one string into another string 
// find the no.of delete aand insert operation needed in first string to convert into another string.

// approach
// find lis of both the strings and then no.of operations needed into 
// string size - lis , with both string and add them final anwer.

// tabulation 
// T.C O(n*m) S.C O(n*m)
int longCommonSubseq(string word1,string word2){
    int n = word1.size(),m=word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
int minDistance(string word1, string word2) {
    int n = word1.size(),m=word2.size();
    return n + m - (2*longCommonSubseq(word1,word2));
}

// space optimization
// T.C O(n*m) S.C O(m)
int longCommonSubseq(string word1,string word2){
    int n = word1.size(),m=word2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++) prev[j] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = 0 + max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}
int minDistance(string word1, string word2) {
    int n = word1.size(),m=word2.size();
    return n + m - (2*longCommonSubseq(word1,word2));
}

int main(){

    return 0;
}