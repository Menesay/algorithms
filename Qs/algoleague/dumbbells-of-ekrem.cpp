/* O(n^2) çözüm.
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n ,q ;
	cin >> n >> q;
	vector<int> v(n);
	for(auto &x : v) cin >> x;

	int q1 ,q2;
	int sum = 0;


	for(int i = 0 ; i < q ; i++){	

		cin >> q1 >> q2;

		for(int i = q1-1; i < q2 ; i++){
			sum += v[i];
		}
		cout << sum << endl;
		sum = 0;
	}
}

*/

// O(n) çözüm prefix sum ile
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n ,q ;
	cin >> n >> q;

	// toplama işlemi sadece n kere yapıldı
	vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int weight;
        cin >> weight;
        pref[i] = pref[i - 1] + weight;
    }

    // q boyunca
    while (q--) {
        int l, r;
        cin >> l >> r;

        // 5, 4, 2 - 5 = 6 
        cout << pref[r] - pref[l - 1] << endl;
    }

}