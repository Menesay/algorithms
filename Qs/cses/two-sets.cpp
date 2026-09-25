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
    
    int total = n * (n + 1) / 2;
    

    if (total % 2 != 0) {
        cout << "NO";
        return 0;
    }
    

    int target = total / 2;
    
    vector<int> s1, s2;
    int rem = target;
    

    for (int i = n; i >= 1; i--) {

        if (i <= rem) {
            s1.push_back(i);
            rem -= i;

        } else {
            s2.push_back(i);
        }
    }
    
    cout << "YES" << endl;
    cout << s1.size() << endl;
    
    for (int x : s1) {
        cout << x << " ";
    }

    cout << endl;
    
    cout << s2.size() << endl;
    
    for (int x : s2){ 
        cout << x << " ";
    }
    
}