
# Breadth First Search
* herhangi bir node'dan başlanır ve distance değerleri tutulur
* O(m+n) : node ve egde sayısı kadar

```
(1)-------(2)-------(3)
 |         |         |
 |         |         |
(4)       (5)-------(6)
```
node 1'den başlayarak bfs
```
node distance
1 	 0
2    1
3    2
4    1
5    2
6    3
```

* queue'ya adjacent nodlar konur ve tek tek işlenirler.
* visited bool arrayi sayesinde duplicate visit gerçekleşmez.
* `distance[s]` : x node'undan s node'una olan uzaklık
* `q.push(x);` : x node'undan başlayarak bfs

basic
```cpp
queue<int> q;
bool visited[N];
int distance[N];

visited[x] = true;
distance[x] = 0;

q.push(x);
while (!q.empty()) {
	int s = q.front(); q.pop();
	
	// process node s
	
	for (auto u : adj[s]) {
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
	}
}
```


single connected graph (hiç ayrık eleman yok)
```cpp
#include <bits/stdc++.h>
using namespace std;

// BFS for single connected component
vector<int> bfs(vector<vector<int>>& adj) {
    int N = adj.size();
    vector<bool> visited(N, false);
    
    // result vectorde hangi sırayla ziyaret ettiği yer alcak
    vector<int> res;
    queue<int> q;
    
    // src: başlangıç değeri
    int src = 1;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // process curr
        // result vectore atılıyor
        res.push_back(curr);

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
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
    
    // node number 6'ya kadar var
    int N = 6;

    // index tuttuğu için 6.noda'a erişmek için
    // 7 büyüklüğünde bir vector gerekli
    vector<vector<int>> adj(N+1);

    /*
(1)-------(2)-------(3)
 |         |         |
 |         |         |
(4)       (5)-------(6)
    */
    // creating adjacency list
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 6);
    addEdge(adj, 5, 6);

    vector<int> res = bfs(adj);
    for (int i : res){
        cout << i << " ";
    }

    // output: process sırası
    // 1 2 4 5 3 6
}
```


disconnected graphs
```cpp
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

    /* manuel
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

    for (int i : res){
        cout << i << " ";
    }
    // output
    // 0 2 3 1 4 5
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
    // sonra bfs at.
    vector<int> res = bfs(adj);

}
```

