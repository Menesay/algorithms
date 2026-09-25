#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> v(n);
	int res = 0;
	
	for (int i = 0; i < n; i++) {
	
		cin >> v[i];
		
		int d;
		cin >> d;
		res += d;
	}

	sort(v.begin(), v.end());
	
	int time = 0 ;
	
	for (int i = 0; i < n; i++) {
	
		time += v[i];
		res -= time;
	
	}
	

	cout << res;


}