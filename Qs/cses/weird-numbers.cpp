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
	cout << n << " ";

	while(n>1){

		// odd
		if((n&1)==1){
			n = (3*n)+1;
		} else {
			n = n/2;
		}
		cout << n << " ";

	}

}