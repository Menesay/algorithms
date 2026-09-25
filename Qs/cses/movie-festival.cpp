#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	/*
3
3 5
4 9
5 8
	*/

	// greedy çözüm, sonraki ilk biten seçilir:
	// bitiş saatlerine göre sort edilir.
	
	int n;
	int a,b;
	cin >> n;
	vector<vector<int>> v;	
	for(int i = 0 ; i < n; i++){
		
		cin >> a >> b;
		// sort rahat olsun diye b,a
		v.push_back({b,a});
	}

	sort(v.begin(), v.end());

	int curr_time = 0;
	int count_ = 0;
	for(int i = 0; i < n ; i++){
		// a
		if(v[i][1] >= curr_time){
			count_++;

			// b zamanına set et.
			curr_time = v[i][0];
		}

	}
	
	cout << count_ << "\n";
}