#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/*
3 2
1 2
3 1

2 1 1
*/

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n+1);
	for(int i = 0; i<m ; i++){
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	/*
	 adj = [ 
	 		[],   : 0. node'un adjsi yok 
	 		[2,3],: 1. node'un adjsi 2 ve 3
	 		[1],  : 2. node'un adjsi 1
	 		[1]   : 3. node'un adjsi 1
	 	   ]	
	*/

	// nodelar 1'den numarandırılmaya başlandığı için i = 1
	//  1≤ u,v ≤ N
	for(int i = 1; i <= n; i++){
    	
    	cout << adj[i].size() << " ";

	}

}