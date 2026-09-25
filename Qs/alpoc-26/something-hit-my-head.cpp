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
    string t, k;
    
    cin >> t >> k;
    
    for(int i = 0; i < n; i++){

    	/*
t[i] - '0'  →  '1' - '0'  =  1     (convert char to actual number)
k[i] - '0'  →  '0' - '0'  =  0     (convert char to actual number)

1 ^ 0  =  1                          (XOR the two bits)

'0' + 1  =  '1'                      (convert number back to char)
(char)('1')  →  prints '1'
		*/
        cout << (char)('0' + ((t[i] - '0') ^ (k[i] - '0')));
    }

}