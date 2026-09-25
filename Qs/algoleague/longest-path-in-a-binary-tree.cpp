#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18;

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

int max_ = -INF;
int counter = 0;

vector<int> dfs(vector<vector<int>> &adj) {
    int N = adj.size();
    vector<bool> visited(N, false);
    vector<int> res;
    

    // 1.node'dan N. node'a kadar
    for (int i = 1; i < N; i++) {

        counter++;

        max_ = max(max_ , counter);

        
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


    int N;
    cin >> N ;
    // önce adj list oluştur
    vector<vector<int>> adj(N+1);
    for(int i = 0; i<N-1; i++){
        int u, null_,v;
        cin >> u >> null_ >> v;
        addEdge(adj, u, v);
    }
    // sonra dfs at.
    vector<int> res = dfs(adj); 

    //for (auto it : res){
    //    cout << it << " ";
    //}

    //cout << max_ - 1;

}