#include <bits/stdc++.h>
using namespace std;

int N,M,r,u;


void bfsConnected(vector<vector<int>>& adj, int src, vector<bool>& visited) {
    queue<int> q;

    // 10 tane node büyüklüğünde distance vectoru
    vector<int> dist(adj.size(), 0);

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if(curr == u){
            cout << dist[curr];
            break;
        }
        

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;

                // x olan child ve curr'den 1 fazla
                dist[x] = dist[curr] + 1;

                q.push(x);
            }
        }
    }
}


void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    // undirected
    adj[v].push_back(u);
}

int main() {

    cin >> N >> M;

    cin >> r >> u;

    vector<vector<int>> adj(N+1);
    for(int i= 0; i<N ; i++){
        int node1;
        cin >> node1;
        int adj_number;
        cin >> adj_number;
        for(int j = 0; j<adj_number ; j++){
            int node2;
            cin >> node2;
            addEdge(adj, node1, node2);
        }
    }


    vector<bool> visited(N+1, false);
    bfsConnected(adj, r, visited);

}