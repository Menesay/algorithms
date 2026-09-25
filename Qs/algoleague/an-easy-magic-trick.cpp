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
    
    vector<int> v(1024);
    for(auto &x : v) cin >> x;
    
    int a = 0, b = 1023;
    while (a <= b) {
        int mid = (a + b) / 2;
        
        cout << mid + 1 << " " << v[mid] << endl;
        
        if (v[mid] == n) {

            break;
        
        } else if (v[mid] > n) {
            b = mid - 1;
        
        } else {
            a = mid + 1;
        }
    }

}