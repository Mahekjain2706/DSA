
void dikjistra(vector<vector<int>> adj[],int source){
    int n = adj.size();
    priority_queue<int> pq;
    pq.push(source);
    vector<bool> visit(n,0);
    vis[source] = true;

    while(!pq.empty()){
        int node = pq.top();
    }
}