#include<bits/stdc++.h>
using namespace std;

// Bellman Ford Algorithm
// it is also use for shortest path from source to other nodes.
// but for negative cycle dijkstra not work.
// Bellman ford help to detect negative cycle in Directed Graph
// for undirected convert undirected to directed graph to two side edges with same weight.
// edges can be given in any order

// Steps:-
// 1. relax all the edges n-1 times sequencially.
// relax:- if(dist[u]+wt < dist[v]) dist[v] = dist[u]+ wt;
 
// Q. why n-1 iteration :- as edges in any order,after n-1 edges everyone must covers. in worst case in n-1 all travel.
// Q. how to detech negative cyle :- if in every iteration value changes,
// if in Nth iteration again value decrease then we can say that negative cycle present.
// TC O(V*E)  S.C O(V)
vector<int>  bellman_ford(int V,vector<vector<int>> &edges,int sr){
    vector<int> dist(V,1e8);
    for(int i=0;i<V-1;i++){
        dist[i]=0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] !=1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //Nth relaxtion to check negative cycle.
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if( dist[u]!=1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}

// Floyd Warsheell Algorithm
// it is different from both , In this we tell the shortest path from each node & detech negative cycle.
// Multisource shortest Path
// 1. go by every vertex and edges
// check path via each node [i][j] via [i][k] + [k][j]
// change matrix for each and store minimum value in matrix
// How to detech negative cycle :- if cost of [i][i] is <0 then negative cycle exsist;
// T.C O(n^3)   S.C O(n*n)
// if no negative cycle then we can implement dijkstra for each node T.C O(n*Elog(V))
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1){
                matrix[i][j] = 1e9;
            }
            if(i==j) matrix[i][j] = 0;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    // for negative cycle
    for(int i=0;i<n;i++){
        if(matrix[i][i] < 0){
            cout<<"Negative"<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9){
                matrix[i][j] = -1;
            }
        }
    }
}


// City with the smallest number of neighbours at a threshold distance
// in this we have to reach from one city to another but distance in less then dist
// Threshold so we have to find city which travels minimum city.
int findCity(int n,vector<vector<int>>&edges,int distThresh){
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(auto it:edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i=0;i<n;i++) dist[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]== INT_MAX || dist[k][j]==INT_MAX) continue;
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int cnt = 0,cityNo=-1,countMin = n;
    for(int city=0;city<n;city++){
        for(int adjNode=0;adjNode<n;adjNode++){
            if(dist[city][adjNode] <= distThresh){
                cnt++;
            }
        }
        if(cnt <= countMin){
            countMin = cnt;
            cityNo = city;
        }
        cnt = 0;
    }
    return cityNo;
}
// dijkstra's 
int findCity1(int n,vector<vector<int>> &edges,int distThresh){
    vector<pair<int,int>> adj[n];
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int cnt=0,cityNo=-1,countMin=n;
    for(int i=0;i<n;i++){
        vector<int> dist(n,INT_MAX);
        dist[i]=0;
        pq.push({0,i});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i]<=distThresh){
                cnt++;
            }
        }
        if(cnt <= countMin){
            countMin = cnt;
            cityNo = i;
        }
        cnt = 0;
    }
    return cityNo;
}




int main(){

    return 0;
}