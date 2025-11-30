class Disjoint_set{
    vector<int> rank,size,parent;
    public:
    Disjoint_set(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int find_up(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_up(parent[node]);
        
    }
    void union_by_rank(int u,int v){
        int ulp_u = find_up(u);
        int ulp_v = find_up(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void union_by_size(int u,int v){
        int ulp_u = find_up(u);
        int ulp_v = find_up(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];     
        }
    }
};
int kruskal(int n,vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjnode}});
        }
    }
    sort(edges.begin(),edges.end());
    int edge_wt = 0;
    Disjoint_set ds(n);
    for(auto it: edges){
      int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.find_up(u)!=ds.find_up(v)){
            edge_wt+=weight;
            ds.union_by_size(u,v);
        }
    }
    return edge_wt;
}
