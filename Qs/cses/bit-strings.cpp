#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n ;
	cin >> n;

	if (n==0){
		cout << 0;
	}

	int res = 1;
	for(int i = 1; i<=n; i++){
		res = res % MOD;
		res *= 2;
		

	}
	res = res % MOD;
	cout << res;

}

//%2g8p&{C=6{_>v$8;us7~aFl