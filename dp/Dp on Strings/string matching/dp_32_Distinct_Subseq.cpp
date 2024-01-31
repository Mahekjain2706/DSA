#include<bits/stdc++.h>
using namespace std;

// string matchiing
// given two string we want to tell how many subseq of string one is string 2 

// 1. express in terms of index , 2. exploe all possibilities ,
// 3. return summation of all possibility , 4. Base case

// no of subseq of s2 in s1
// recursive 
// T.C O(exponential) S.C O(n+m)
int subseq(int ind1,string s ,int ind2,string l){
    if(ind2<0){
        return 1;
    }
    if(ind1<0){
        return 0;
    }

    if(s[ind1]==l[ind2]){
        int notTake = subseq(ind1-1,s,ind2,l);
        int take = subseq(ind1-1,s,ind2-1,l);
        return take + notTake;
    }else{
        return subseq(ind1-1,s,ind2,l);
    }
}
int dist_Subseq(string s,string l){
    int n = s.length() , m = l.length();
    return subseq(n-1,s,m-1,l);
}


// memorization
// T.c O(n*m) S.C O(n*m)+O(n+m)

int subseq(int ind1,string s ,int ind2,string l,vector<vector<int>> &dp){
    if(ind2<0){
        return 1;
    }
    if(ind1<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s[ind1]==l[ind2]){
        int notTake = subseq(ind1-1,s,ind2,l,dp);
        int take = subseq(ind1-1,s,ind2-1,l,dp);
        return dp[ind1][ind2] = take + notTake;
    }else{
        return dp[ind1][ind2] = subseq(ind1-1,s,ind2,l);
    }
}
int dist_Subseq(string s,string l){
    int n = s.length() , m = l.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return subseq(n-1,s,m-1,l,dp);

}

// tabulation
// T.C O(n*m) S.C O(n*m)
int mod = 1e9;
int numDistinct(string s, string l) {
    int n = s.length(),m=l.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=1;
        
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s[ind1-1]==l[ind2-1]){
                dp[ind1][ind2] = (dp[ind1-1][ind2-1] + dp[ind1-1][ind2])%mod;
            }
            else{
                dp[ind1][ind2] = dp[ind1-1][ind2];
            }
        }
    }
    return dp[n][m];
} 


// space optimization
// T.C O(n*m) S.C O(2*m)
int mod = 1e9;
int numDistinct(string s, string l) {
    int n = s.length(),m=l.length();
        vector<int> prev(m+1,0),curr(m+1,0);
        prev[0] = curr[0] = 1;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==l[ind2-1]){
                    prev[ind2] = (prev[ind2-1] + prev[ind2])%mod;
                }
                else{
                    prev[ind2] = prev[ind2];
                }
            }
        }
        return prev[m];
}

// single array optimization
// T.C O(n*m) S.C O(m)
int mod = 1e9;
int numDistinct(string s, string l) {
    int n = s.length(),m=l.length();
    vector<int> prev(m+1,0);
    prev[0] =  1;
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=m;ind2>=1;ind2--){
            if(s[ind1-1]==l[ind2-1]){
                prev[ind2] = (prev[ind2-1] + prev[ind2])%mod;
            }
        }
    }
    return prev[m];
}

int main(){

    return 0;
}