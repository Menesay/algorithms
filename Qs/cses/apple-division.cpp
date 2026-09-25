
// brute force ile çözücez
// sağdakiler 0 soldakiler 1 olsun.
// her sayının binary gösterimi alınır.
// mesela 0 : 00000 : tüm sayılar sağda
// 2^n-1'den 0'a for döndür.
// her bi elemanda left most 0 ise sağa koy, left most 1 ise sola koy: tüm permütasyonlar üretildi.

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
	vector<int> v(n);
	for(auto &x : v) cin >> x;

	// (1 << n) = pow(2,n);
	// bütün alt kümleri gezmek için : bitmask yöntemi 
	for(int mask = 0;  mask < (1 << n) ; mask++){

		int diff = 0;
		// mask = 00000 : tüm elemanlar sağda olsaydı ne kadar difference çıkardı.
		// mask = 00101 : 0. ve 2. eleman solda, diğerleri sağda olsaydı: ne kadar difference çıkardı.
		
		
		int mask_tmp = mask;

		int left = 0, right = 0;


		for(int i = 0; i < n; i++){
			while(mask_tmp > 0){

				if (mask_tmp % 2 == 0){
					// sağda
					//rigth.push_back(mask_tmp);
					left += v[i];
				} else {
					// solda
					//left.push_back(mask_tmp);
					right += v[i];
				}
				mask_tmp /= 2;
			}			
		}

		diff = abs(left-right);
		min_diff = min(min_diff, diff);


	}

	cout << min_diff;
}


