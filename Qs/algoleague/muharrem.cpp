#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int Q;
	cin >> Q;

	for(int i = 0; i< Q; i++){
		int N;
		cin >> N;

		int ans = 1;

		for(int i = 1; i<=N-1; i++){
			ans *= i;
		}

		cout << ans + N << endl;

	}
}