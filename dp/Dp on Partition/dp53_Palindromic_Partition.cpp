#include<bits/stdc++.h>
using namespace std;

// Palindrome Partition 2
// you are given string , find minimum partition to make string as palindrome
// ex:- bab abcba d c ede  -> 4 partitions

// FRONT PARTITION

// recursive 
// T.C O(exponential) S.C O(n)
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int solve(int i,string s,int n){
        if(i==n) return 0;

        int mini_Cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + solve(j+1,s,n);
                mini_Cost = min(mini_Cost,cost);
            }
        }
        return mini_Cost;
    }
    int minCut(string s) {
        int n = s.length();
        return solve(0,s,n)-1;
    }

// memorization
// T.C O(n*n) S.C O(n)+O(n)
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i] !=s[j]) return false;
        i++;
        j--;
    };
    return true;
}
int solve(int i,string &s,int n,vector<int> &dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mini_Cost = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int cost = 1 + solve(j+1,s,n,dp);
            mini_Cost = min(mini_Cost,cost);
        }
    }
    return dp[i] = mini_Cost;
}
int minCut(string s) {
    int n = s.length();
    vector<int> dp(2000,-1);
    return solve(0,s,n,dp)-1;
}
// Tabulation
// T.C O(n*n) S.C O(n)
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i] !=s[j]) return false;
        i++;
        j--;
    };
    return true;
}
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int mini_Cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + dp[j+1];
                mini_Cost = min(mini_Cost,cost);
            }
        }
        dp[i] = mini_Cost; 
    }
    return dp[0]-1;
}


int main(){
    return 0;
}