#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


/*
6
2
()
2
)(
3
(((
6
())(()
4
(()(
5
)()()
*/

	int q; cin >> q;

	while(q>0){

		int o = 0;int c_ = 0;
		
		int leng; cin >> leng;
		string s;cin >> s;		

		for(auto c : s){
			if(c == '('){o++;}
			if(c == ')'){c_++;} 
		}

		if(o==c_){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}

		q--;
	}
}