#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	// HATTIVATI
	string str;
	cin >> str;

	// AAHIITTTV
	sort(str.begin(), str.end());

	/*
	map<char, int> mp;
	for(int i = 0; i<str.length(); i++){
		mp[str[i]]++;
	}
	*/

	 
	int n = str.size();
    bool swapped;

    /*                  7
    for (int i = 0; i < n - 1 - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1 - 1; j++) {
            
            if (str[j-1] == str[j]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
      
        if (!swapped){
            break;
        }
        
    }
    */

	// sorted : AAHIITTTV
	// AHAIITTTV
	// AHAITITTV


    for (int i = 0; i < n; i++) {
		for (int j = 1; j < n-1; j++) {
			if (str[j-1] == str[j]) {
				swap(str[j], str[j + 1]);
			}
		}
	}
	// AHAITITVT

    // AHATITITVT
    cout << str;

}