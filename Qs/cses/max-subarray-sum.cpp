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
	int x;


	// initializing them as -infinity 
    int sum = -INF;
    int best = -INF;
	// 8
	// -1 3 -2 5 3 -5 2 2
	// 9

	// 10
	// 24 7 -27 17 -67 65 -23 58 85 -39
	// 185

	for(int i=0; i< n ; i++){
		cin >> x;

		sum= max(x, sum + x);

		best= max(best, sum);

	}

	cout << best;
}