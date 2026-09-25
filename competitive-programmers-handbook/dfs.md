
# Depth First Search
* O(n+m)
* n: node, m: edge

basic
```cpp
// doldurulduğu varsayılıyor
vector<int> adj[N];

// ilk başta false'lar ile dolu.
bool visited[N];

void dfs(int s) {
	if (visited[s]){
		return;
	}
	visited[s] = true;
	
	// process node s
	
	for (auto u: adj[s]) {
		dfs(u);
	}
}
```

* connected graph yazmıcan çünkü zaten disconnected, onu kapsıyor

disconnected graph
```cpp
#include <bits/stdc++.h>
using namespace std;

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
    

    // 1.node'dan N. node'a kadar
    for (int i = 1; i < N; i++) {
        
        // eğer source (i) ziyaret edilmediyse gir.
        // yani yeni bir component varsa gir.
        if (!visited[i]) {
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

    /* manuel
    // node number max 5
    int N = 5;
    vector<vector<int>> adj(N+1);

//(1)-------(2)-------(0)-------(3)           (4)-------(5)
//     Component 1 (Path Graph)         Component 2 (Isolated Edge)  
  
    // creating adjacency list
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 5, 4);

    vector<int> res = dfs(adj); 
    
    for (auto it : res){
        cout << it << " ";
    }
    */

    int N, M;
    cin >> N >> M;
    // önce adj list oluştur
    vector<vector<int>> adj(N+1);
    for(int i = 0; i<M; i++){
        int u,v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    // sonra dfs at.
    vector<int> res = dfs(adj); 


}
```