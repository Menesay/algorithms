#include <bits/stdc++.h>
using namespace std;


void bfsConnected(vector<vector<int>>& adj, int src, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // process curr
        res.push_back(curr);

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

vector<int> bfs(vector<vector<int>>& adj) {
    int N = adj.size();
    vector<bool> visited(N, false);
    vector<int> res;

    // 1.node'dan N. node'a kadar
    for (int i = 1; i < N; i++) {
        
        // eğer source (i) ziyaret edilmediyse gir.
        if (!visited[i]){
            //if(!adj[i].empty()){cout << "new component" << endl;}
            bfsConnected(adj, i, visited, res);
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

    // node number 5'e kadar var
    int N = 5;
    vector<vector<int>> adj(N+1);
//(1)-------(2)-------(0)-------(3)           (4)-------(5)
//     Component 1 (Path Graph)         Component 2 (Isolated Edge)  
   // creating adjacency list
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 4, 5);
    
    vector<int> res = bfs(adj);

    //for (int i : res){
    //    cout << i << " ";
    //}
    // output
    // 0 2 3 1 4 5
    

    /*
    int N, M;
    cin >> N >> M;
    // önce adj list oluştur
    vector<vector<int>> adj(N+1);
    for(int i = 0; i<M; i++){
        int u,v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    // sonra bfs at.
    vector<int> res = bfs(adj);
    */
}