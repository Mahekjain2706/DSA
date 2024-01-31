#include<bits/stdc++.h>
using namespace std;

// print the LIS
// T.C O(n*m) S.C O(n*m )
string longestCommonSubsequence(string text1, string text2) {
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

    //T.C O(n+m) at the worst case
    int len = dp[n][m];
    string ans ="";
    for(int i=0;i<len;i++) ans+="$"; 

    int index = len-1;
    int i=n,j=m;
    while(i>0 && j>0){
        if(text1[i-1] == text2[j-1]){
            ans[index] = text1[i-1];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return ans;
}

int main(){
    return 0;
}