#include <bits/stdc++.h>
using namespace std;

int country_number = 0;

void dfsRec(vector<vector<int>> &adj, 
vector<bool> &visited, int curr, vector<int> &res) {
    
    visited[curr] = true;

    // process curr
    res.push_back(curr);


    for (int i : adj[curr]){
        if (!visited[i]){
            dfsRec(adj, visited, i, res);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj) {
    int N = adj.size();
    vector<bool> visited(N, false);
    vector<int> res;
    

    // 1. nodedan N. node'a kadar
    for (int i = 1; i < N; i++) {
        if (!visited[i]) {
            // i : source
            // tüm nodelar için ayrı ayrı dfs
            // ama visited ise atlıyor.

            // her bir i 
 
            country_number += 1;
            dfsRec(adj, visited, i, res);
        }
    }

    return res;
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);

    // undirected
    adj[v].push_back(u);
}

int main() {

    int N, M;
    cin >> N >> M;


    vector<vector<int>> adj(N+1);
    for(int i = 0; i<M; i++){
        int u,v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    vector<int> res = dfs(adj); 

    cout << country_number;    
    
}

