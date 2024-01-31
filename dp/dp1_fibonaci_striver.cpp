 #include<bits/stdc++.h>
using namespace std;

// 1. Tabulation - Bottom Up  // final soln 
// 2. Memorization - Top Down

// Recursion - top down  
// Dp - top up

// if   their is anywhere overlapping happen then we store it is done by memorization.
// so for overlapping we make dp array and store elements inside it so that repeat solve not happen


// recursion(t.c = o(n) s.c = o(n) + o(n))

// int fibonacci(int n,vector<int> &dp){
//     if(n<=1){
//         return n;
//     }
//     if(dp[n] != -1) return dp[n];
//     return sp[n] = fibonacci(n-1) + fibonacci(n-2);
// }

// tabulation (t.c = o(n) s.c = o(n))

// int fib(int n,vector<int> &dp){ 
//      dp[0]=0;
//      dp[1]=1;
//      for(int i=2;i<=n;i++){
//         dp[i] = dp[i-1] + dp[i-2];
//      }
//      return dp[n];
// }



int main(){

    // fibonacci Number
    // cout<< fibonacci(4)<<endl;

    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<< fibonacci(n,dp);

    // dp space utilize
    int prev =0;
    int prev2 = 1;
    int curr = -1;

    for(int i=2;i<=n;i++){
        curr = prev + prev2;
        prev2 = prev; 
        prev = curr;
    }
    cout<< curr << endl;

    return 0;
}