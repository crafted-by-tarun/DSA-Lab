vector<int> BFS(int n, vector<int>adj[]){
    queue<int> q;
    int vis[n] = {0};
    vis[0] = 1;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node])
        if(vis[it]==0){
            vis[it] = 1;
            q.push(it);
        }
    }
    return bfs;
}
