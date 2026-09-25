#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b;
	int q;cin >> q;

	while(q > 0){

		cin >> a >> b;

		if(a&1 == 1 && b&1 == 1){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}

		q--;

	}


}