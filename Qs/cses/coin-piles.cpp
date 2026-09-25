#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;

	for(int i =0; i < t; i++){

		int a,b;
		cin >> a >> b;
		if ((a+b) %  3 == 0  &&   a<=2*b && b<=2*a){
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}

	}
}
// frz