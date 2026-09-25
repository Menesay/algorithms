#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;



int count_divisors(int n){
    /*
    Count the number of divisors for a given integer n.
    Time Complexity: O(√n)
    Args:
        n: Integer to find divisor count for
    Returns:
        Number of divisors
    Examples:
        count_divisors(12) -> 6  (divisors: 1, 2, 3, 4, 6, 12)
        count_divisors(28) -> 6  (divisors: 1, 2, 4, 7, 14, 28)
        count_divisors(1) -> 1   (divisor: 1)
    */
    if (n <= 0 ){
        return 0;
    }
    
    int count = 0;
    int i = 1;
    
    while (i * i <= n ){
        
        if ( n % i == 0 ){
        
            if (i * i == n ){
                count += 1;
            } else {
            	count += 2;
            }
        }
                
        i += 1;
    }
    
    return count;

}

/*
15 3 5
1
4
7
12
17
*/



signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


	/* time limit yiyo yaaa. belki binary search lazım
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> v(n);
	// 0. indexte 1 sayısının bölen syısı olack
	// 14. indexte 15 sayısının bölen syısı olack
	for(int i = 0 ; i < n ; i++){
		v[i] = count_divisors(i+1);
	}

	int flag = -1;
	while(q){
		int qi;
		cin >> qi;
		
		flag = 0;
		for(int i = 0; i < n ; i++){
			if(v[i] >= k){

				if( i + 1 > qi){
					cout << i+1 << endl;
					flag = 1;
					break;
				}
			}
		}
		if (!flag){
			cout << -1 << endl;
		}
		
		
		q--;
	}

	*/


	int n, k, q;
	cin >> n >> k >> q;


	vector<int> bolen_sayisi(n + 1);

	for (int i = 1; i <= n; i++) {
	  for (int j = i; j <= n; j += i) {
	    bolen_sayisi[j]++;
	  }
	}


																																																																																																																									  vector<int> ans(N + 1);
																																																																																																																									  int val = -1;
																																																																																																																									  for (int i = N; i >= 1; i--) {
																																																																																																																									    ans[i] = val;
																																																																																																																									    if (bolen_sayisi[i] >= K) val = i;
																																																																																																																									  }

																																																																																																																									  while (Q--) {
																																																																																																																									    int x; cin >> x;
																																																																																																																									    if (x > N) cout << -1 << endl;
																																																																																																																									    else cout << ans[x] << endl;
																																																																																																																									  }
}

