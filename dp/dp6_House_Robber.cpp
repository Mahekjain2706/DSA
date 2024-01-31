#include<bits/stdc++.h>
using namespace std;

// House Robber 2
// rober can rob the money from n house but if rob from adjacent house then alarm start , last house and first house is adjacent , find the maximum money he rob.
// same as maxi sum in circular
// t.c 
int maximumSum(vector<int> &arr){
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i=0;i<n;i++){
        int take = arr[i] ;
        if(i>1) take +=prev2;
        int notTake = 0 + prev;

        int curr = max(take,notTake);
        prev2 = prev;
        prev  = curr;
    }
    return prev;
}
int rob(vector<int> &arr){
    int n = arr.size();
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1)  temp2.push_back(arr[i]);
    }
    return max(maximumSum(temp1),maximumSum(temp2));
}

int main(){

    return 0;
}