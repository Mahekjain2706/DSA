 #include<bits/stdc++.h>
using namespace std;
// 1. try to represent the problem in terms of index
// 2. Do all possible stuffs on that index according to the problem statement.
// 3. Sum of all stuffs -> count all ways
// min (of all the stuffs) -> find minimum


// we have n stairs we have to reach nth stair in minimum steps
// fibonacci ~ n stairs

// int f(int ind){ // t.c o(n)
//     if(ind==1) return 1;
//     if(ind==0) return 0;
//     int left = f(ind-1);
//     int right = f(ind-2);
//     return left + right;
// }

// int dp[101];
// int f(int ind){ // t.c o(n)
//     if(ind<=1) return ind;
//     if(dp[ind]!=-1) return dp[ind];

//     int left = f(ind-1);
//     int right = f(ind-2);
//     return dp[ind] = left + right;
// }

// int f(int ind){
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=ind;i++){
//        dp[i] = dp[i-1] + dp[i-2];
//     }
//      return dp[ind];
// }

// t.c o(log(n)) fibonacci by matrix exponentiation



int main(){
    
    return 0;
}