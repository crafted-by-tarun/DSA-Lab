#include<iostream>
void dfs(int node,int vis[],vector<int>adj[],vector<int>&ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it : adj[node]){
        if(vis[it]==0){
            dfs(it,vis,adj,ls);
        }
    }
}
vector<int>DFSOfGraph(int n,vector<int> adj[]){
    int vis[n] = {0};
    int start = 0;
    vector<int>ls;
    dfs(start,vis,adj,ls);
    return ls;
}
using namespace std;
int main(){
    return 0;
}
