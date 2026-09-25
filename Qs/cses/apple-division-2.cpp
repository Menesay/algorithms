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

	int sum_of_all = 0;
	
	vector<int> v(n);
	for(auto &x : v){
		cin >> x; sum_of_all += x;
	}

	
	//	n=5
	//	3 2 7 4 1

	// 2^n subset
	vector<int> subset_sum_diff;
    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            
        	// b & 2^i
            if (b & (1 << i)) {

                subset.push_back(i);
            }
        }

    
        // bu sebset for ile gezilip işlem yapılabilir.

		//cout << "subset is : ";        
        for (int x : subset){
            // o anki subsetin elemanlarını ekle

        	// subset indexleri
            // 0
            // 0 1 
            // 0 1 2
            // 0 2 4
            // cout << "x: " << x << "|" << "v[x]: " << v[x];
            sum+= v[x];
        
            //cout << x  << " "; 

        }

        //cout << endl;
        

        subset_sum_diff.push_back(abs(sum_of_all - sum - sum));

    }

    int res = INF;

    for(auto x : subset_sum_diff){
    	res = min(res, x);
    }

    cout << res;

}

/* better version of same brute force tech
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    int total = 0;
    for (auto &x : v) { cin >> x; total += x; }

    int res = INF;
    for (int b = 0; b < (1LL << n); b++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (b & (1LL << i))
                sum += v[i];
        res = min(res, abs(total - 2 * sum));
    }
    cout << res << "\n";
}

*/