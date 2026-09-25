
# shortest path


* BFS
* r'dan u'ya shortest path uzunluğu
```cpp
// algoleague run roka run
// https://algoleague.com/training/algorithm-training-beginner-set/problem/run-roka-run/detail
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

                // kaç tane child varsa o kadar edge vardır.
                // shortest path için edge sayıyoruz
                
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
/* input
10 12
5 9
1 3 5 6 8
2 3 3 7 10
3 3 2 5 6
4 2 5 7
5 2 1 3
6 3 1 3 9
7 2 2 4
8 1 1
9 2 6 10
10 2 2 9
*/
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
```