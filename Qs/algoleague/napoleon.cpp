#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


	/*
10 24
1803 +20
1805 +29
1807 -7
1808 +30
1812 -3
1814 +7
1816 +23
1820 -11
1821 +21
1825 +3
	*/

    int n, k;
    cin >> n >> k;
    
    vector<int> c(n);
    int y;

    for(int i = 0; i < n; i++){
        cin >> y >> c[i];
    }
    
    int ans = 0;
    
    
    for(int skip = 0; skip < n; skip++){
    
        int cur = k;
        int maxVal = k;
    
        for(int i = 0; i < n; i++){
    
            if(i == skip){
            	continue;
            }
    
            cur += c[i];
            maxVal = max(maxVal, cur);
    
        }

        ans = max(ans, maxVal);
    
    }
    
    cout << ans << endl;


}