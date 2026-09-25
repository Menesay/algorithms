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

	int bolum=0;
	int res = 0;
	while(n>0){
		res += n/5;
		n = n/5;
	}
	cout << res;
}
// 2015