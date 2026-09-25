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

	if (n == 1){ cout << 0; return 0;}

	
	cout << 0 << endl;
	for(int i = 2 ; i <=n ; i++){
		//        2 li kombinasyon - general formula
		cout <<  ((i*i)*(i*i-1)/2) - (4*(i-2)*(i-2) + 4*(i-2)) << endl;

	}

}