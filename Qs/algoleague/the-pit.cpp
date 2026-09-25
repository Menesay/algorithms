#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;


void rec(int n, vector<int> &v, int depth, int zero_or_one){
	
	
	if(zero_or_one != -1){
		v[depth-1] = zero_or_one;	
	}
	 

	if (depth == n){
		
		for(auto x : v){
			cout << x;
		}
		cout << endl;

		return;
	}

	depth++;

	

	//cout << "current depth: "<< depth << "zero_or_one: " << zero_or_one;
	
	rec(n, v, depth, 0);
	rec(n, v, depth, 1);

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n ;
	cin >> n;

	int pow_ = pow(2, n);


	vector<int> v(n);
	// henüz depth başlamadı
	rec(n, v, 0, -1);

}