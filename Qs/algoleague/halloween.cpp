#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n , m ;
	cin >> n;

	int max_ = 0;

	vector<int> v(n);
	for(auto &x : v) cin >> x;
	
	max_=v[0];

	for(int i = 0; i < n ; i++){
		max_ = max(max_, v[i]);
	}

	cin >> m;



	int sub_sum = 0;
	for(int i = 0 ; i < n; i++){
		sub_sum += max_ - v[i];
	}

	if((m - sub_sum) % n == 0 && sub_sum <= m){
		cout << 1;
	} else {
		cout << 0;
	}

	/*
	if (sub_sum > m){
		cout << 0;
		return;
	}else{
		cout << 1;
		return;
	}
	*/
}