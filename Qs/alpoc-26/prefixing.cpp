
/* O(n^2) çözüm
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,x ;
	cin >> n >> x;
	vector<int> v(n);
	for(auto &x : v){
		cin >> x;
	}
	int sum = 0;
	int res = 0;
	int i = 0;
	int j = 0;
    while(j < n){
        sum = sum + v[i];
     	if (sum == x){
            res++;
 	    }
        i++;
        if (i == n){      
            j++;
            i = j;
            sum = 0;
        }
    }
	cout << res;
}

*/

// O(n) çözüm
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    long long x;
    cin >> n >> x;

    map<long long, long long> mp;
    long long sum = 0, ans = 0;

    mp[0] = 1;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        ans += mp[sum - x];
        mp[sum]++;

        //cout << "ans = " << ans << "sum = " << sum  <<" mp = " <<mp[sum] << " i " << endl;
    }

    cout << ans;
    return 0;
}

// 5 3
// 1 -2 3 1 -1