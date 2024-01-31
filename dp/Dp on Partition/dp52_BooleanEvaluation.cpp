#include<bits/stdc++.h>
using namespace std;

// you are given an expression in the form of a string where operands will be :(True or False) , and operations will be :(and,or,xor)
// now you have to find the number of ways we can parthesize the expression such that it will evaluate to TRUE.
// ans with mod 1e9+7
// alternative T/F or operand
// so in every operand we can divide string into sub problems
// mcm at each operand
// at each operation we can do +2
// -> x & y then we can say no of way true then x*y
// -> x | y then we can say no.of true then x*y(true both) + x1*y(one true or false) + y1*x (ine true one false)
// -> x^y then no.of true is way any one of then true x*y1 + x1*y 
// we take a variable isTrue tell the overall true....
// isTrue tell want you looking for making it.

// Recursive
// T.C O(exponential) S.C O(n)
int mod = 1000000007;

int boolEval(int i,int j,bool isTrue,string &exp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==1){
            return exp[i]=='T';
        }else{
            return exp[i]=='F';
        }
    }

    long long int ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        long long int LT = boolEval(i,ind-1,1,exp);
        long long int LF = boolEval(i,ind-1,0,exp);
        long long int RT = boolEval(ind+1,j,1,exp);
        long long int RF = boolEval(ind+1,j,0,exp);

        if(exp[ind]=='&'){
            if(isTrue) ways = (ways + (RT*LT)%mod)%mod;
            else ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;

        }else if(exp[ind]=='|'){
            if(isTrue) ways = (ways + (RT*LT)%mod + (RT*LF)%mod + (LT*RF))%mod ;
            else ways = (ways + (RF*LF)%mod)%mod;
        }else{
            if(isTrue) ways = (ways + (RT*LF)%mod + (RF*LT)%mod)%mod;
            else {ways = (ways + (RT*LT)%mod + (RF*LF)%mod) %mod;}
        }
    }
    return ways;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    return boolEval(0,n-1,1,exp);
}

// Memorization
// T.C O(n*n*2)*n ~ n^3  S.C O(n*n*2) + O(n)
int mod = 1000000007;

int boolEval(int i,int j,bool isTrue,string &exp,vector<vector<vector<int>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==1){
            return exp[i]=='T';
        }else{
            return exp[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    long long int ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        long long int LT = boolEval(i,ind-1,1,exp,dp);
        long long int LF = boolEval(i,ind-1,0,exp,dp);
        long long int RT = boolEval(ind+1,j,1,exp,dp);
        long long int RF = boolEval(ind+1,j,0,exp,dp);

        if(exp[ind]=='&'){
            if(isTrue) ways = (ways + (RT*LT)%mod)%mod;
            else ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;

        }else if(exp[ind]=='|'){
            if(isTrue) ways = (ways + (RT*LT)%mod + (RT*LF)%mod + (LT*RF))%mod ;
            else ways = (ways + (RF*LF)%mod)%mod;
        }else{
            if(isTrue) ways = (ways + (RT*LF)%mod + (RF*LT)%mod)%mod;
            else {ways = (ways + (RT*LT)%mod + (RF*LF)%mod) %mod;}
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1))); 
    return boolEval(0,n-1,1,exp,dp);
}

// Tabulation
// T.C O(n*n*2)*n ~ n^3  S.C O(n*n*2)
int mod = 1000000007;

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,0))); 


    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=n-1;j++){
            if(i>j) continue;
            for(int isTrue=0;isTrue<=1;isTrue++){
                if(i==j){
                    if(isTrue==1) dp[i][j][isTrue] = (exp[i]=='T');
                    else dp[i][j][isTrue] = (exp[i]=='F');
                    continue;
                }

                long long int ways = 0;
                for(int ind=i+1;ind<=j-1;ind+=2){
                    long long int LT = dp[i][ind-1][1];
                    long long int LF = dp[i][ind-1][0];
                    long long int RT = dp[ind+1][j][1];
                    long long int RF = dp[ind+1][j][0];

                    if(exp[ind]=='&'){
                        if(isTrue) ways = (ways + (RT*LT)%mod)%mod;
                        else ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;

                    }else if(exp[ind]=='|'){
                        if(isTrue) ways = (ways + (RT*LT)%mod + (RT*LF)%mod + (LT*RF))%mod ;
                        else ways = (ways + (RF*LF)%mod)%mod;
                    }else{
                        if(isTrue) ways = (ways + (RT*LF)%mod + (RF*LT)%mod)%mod;
                        else {ways = (ways + (RT*LT)%mod + (RF*LF)%mod) %mod;}
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n-1][1];
}

int main(){
    return 0;
}