#include<bits/stdc++.h>
using namespace std;
// Area of largest Rectangle in Histogram

// Maximum Rectangle Area with all 1's

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nsr,nsl;
    stack<pair<int,int>> s1;
    for(int i=0;i<n;i++){
        if(s1.size()==0) nsl.push_back(-1);
        else if(s1.size()>0 && s1.top().first<heights[i]){
            nsl.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=height[i]){
            while(s1.size()>0 && s1.top().first>=height[i]) s1.pop();
            if(s1.size()==0) nsl.push_back(-1);
            else{
                nsl.push_back(s1.top().second);
            }
        }
        s1.push({heights[i],i});
    }
    while(!s1.empty()){
        s1.pop();
    }
    for(int i=n-1;i>=0;i--){
        if(s1.size()==0) nsr.push_back(n);
        else if(s1.size()>0 && s1.top().first<heights[i]{
            nsr.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=height[i]){
            while(s1.size()>0 && s1.top().first>=height[i]) s1.pop();
            if(s1.size()==0) nsr.push_back(n);
            else{
                nsr.push_back(s1.top().second);
            }
        }
        s1.push({heights[i],i});
    }
    reverse(nsr.begin(),nsr.end());
    int curr=0,max_area=0;
    for(int i=0;i<n;i++){
        curr = abs(nsr[i]-nsl[i]-1)*heights[i];
        max_area = max(max_area,curr);
    }
    return max_area;
}

int maxiArearect(vector<vector<int>> &mat,int n,int m){
    int maxArea = 0;
    vector<int> height(m,0);
    // T.C O(n*(m+n)) S.C O(N)(heightarray + stack)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) height[j]++;
            else height[j] = 0;
        }

        int area = largestRectangleArea(height);
        maxArea = max(maxArea,area);
    }
    return maxArea;
}


int main(){
    return 0;
}