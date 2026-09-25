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

	int c = 0;
	int mod_;
	while(n>0){
		mod_ = n % 2;
		n /= 2;

		if(mod_ == 1){
			c++;
		}
	}

	cout << c;
}