int prims(int n, vector<vector<int>> adj[]){
    vector<int>vis(n,0);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(vis[node]==1) continue;
        vis[node] = 1;
        sum+=wt;
        for(auto itt : adj[node]){
            int adj_element = itt[0];
            int weight = itt[1];
            if(vis[adj_element]==0){
                pq.push({weight,adj_element});
            }
        }

        
    }
    return sum;
}
