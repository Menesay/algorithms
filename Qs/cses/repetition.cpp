#include <bits/stdc++.h>
using namespace std;
#define int long long

#include <string.h>

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s;
	cin >> s;

	int count = 1;
	int res = 1;

	//if (s.size() == 1 ) {cout << 1;}

	for(int i = 1 ; i < s.size() ; i++){
		if (s[i] == s[i-1]){
			count++;
		} else {
			count = 1;
		} 
		res = max(res, count);

	}

	cout << res;
}