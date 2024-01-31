#include<bits/stdc++.h>
using namespace std;

// Longest common substring
// in this case in dp table we does not see prev and upper in match we see daigonal cond else return 0;

// Tabulation
// T.C O(n*m) S.C O(n*m)
int lcsubString(string s1,string s2){
    int n = s1.length(), m = s2.length();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans = max(ans,dp[ind1][ind2]);
            }
            else{
                dp[ind1][ind2] = 0;
            }
        }
    }
    return ans;
}

// space optimization
// T.C O(n*m) S.C O(m)
int lcsubString(string s1,string s2){
    int n = s1.length(), m = s2.length();
    
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i=0;i<=m;i++) prev[i] = 0;
    int ans=0;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                curr[ind2] = 1 + prev[ind2-1];
                ans = max(ans,curr[ind2]);
            }
            else{
                curr[ind2] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}


int main(){
    return 0;
}