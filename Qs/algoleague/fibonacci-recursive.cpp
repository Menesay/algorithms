#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

void fibo(int prev, int prevprev, int n){

	if(n == 0){

		return;
	}


	cout << prev + prevprev << " ";

	fibo(prev+prevprev, prev, n-1);

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;

	cin >> n;

	cout << "1 1 ";
	fibo(1, 1, n);

}