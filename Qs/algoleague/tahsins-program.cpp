
/* O(N) çözüm.
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n ,m;
	cin >> n >> m;

	vector<int> d(n);
	// sadece n eleman okuyor güzeel
	for(auto &x : d) cin >> x;

	vector<int> b(n);
	for(auto &x : b) cin >> x;

	int x,y;
	int count_x = 0;
	int count_y = 0;
	for(int j = 0; j < m; j++){


		count_x = 0;
		count_y = 0;
		// min x : deadlift
		// min y : bench
		cin >> x >> y;


		for(auto e : d){

			if (x <= 0){ break;}
			x = x - e;
			count_x++;
		}


		for(auto e : b){
			if (y <= 0){ break;}
			y = y - e;
			count_y++;
		}


		cout << max(count_x,count_y) << endl;

	}

}

*/


// O(n logn) çözüm.
// 1) prefix sum oluşturup binary search yapıyor.
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n ,m;
    cin >> n >> m;
    vector<int> d(n);
    for(auto &x : d) cin >> x;
    vector<int> b(n);
    for(auto &x : b) cin >> x;


    vector<int> pd(n+1, 0), pb(n+1, 0);
    for(int i = 0; i < n; i++) {
    	pd[i+1] = pd[i] + d[i];
    }
    for(int i = 0; i < n; i++) {
    	pb[i+1] = pb[i] + b[i];
    }

    int x, y;
    
    for(int j = 0; j < m; j++){
        
        cin >> x >> y;

        int dx, bx;
        if(pd[n] < x){
        	dx = -1;
        } else {
        	// dx'e x'in bulunduğu küçük eşit indexi yaz.
        	// bu sayede index+1 gün sayısı kadar gün gerekli diyor.
        	dx = (int)(lower_bound(pd.begin(), pd.end(), x) - pd.begin());
		}
        if(pb[n] < y){
        	bx = -1;
        } else {
        	bx = (int)(lower_bound(pb.begin(), pb.end(), y) - pb.begin());
        }

        if(dx == -1 || bx == -1){
        	cout << -1 << "\n";
        } else {
        	cout << max(dx, bx) << "\n";
        }
    }
}