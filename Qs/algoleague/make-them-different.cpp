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
	int n;
	cin >> n;

	string s;
	cin >> s;

	string s2 = s;

	int sum1 = 0;
	int sum2 = 0;
	for(int i=0 ; i < n - 1 ; i++){

		if(s[i] == s[i+1]){
			if(s[i] == '1'){
				s[i+1] = '0';
				sum1++;
			}
			if(s[i] == '0'){
				s[i+1] = '1';
				sum1++;
			}
		}

		if(s2[i] == s2[i+1]){
			if(s2[i+1] == '1'){
				s2[i] = '0';
				sum2++;
			}
			if(s2[i+1] == '0'){
				s2[i] = '1';
				sum2++;
			}
		}
	}


	//cout << s << endl;
	cout << min(sum1,sum2) << endl;

*/


int n; cin >> n;
string s; cin >> s;

int a = 0, b = 0;

for (int i = 0; i < n; i++) {

    if (i % 2 == 0) {
      
      if (s[i] == '0') a++;
      else b++;

    } else {
      
      if (s[i] == '0') b++;
      else a++;

    }
}

cout << min(a, b);

}