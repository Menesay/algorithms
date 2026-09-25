#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

vector<int> reorder(vector<int> arr, int n) {
    vector<int> arr2;
    for (int i=0; i<n; ++i) {
        if (arr[i] % 6 == 0) {
            arr2.push_back(arr[i]);
        }
    }
    for (int i=0; i<n; ++i) {
        if (arr[i] % 2 == 0 && arr[i] % 6 != 0) {
            arr2.push_back(arr[i]);
        }
    }
    for (int i=0; i<n; ++i) {
        if (arr[i] % 3 != 0 && arr[i] % 2 != 0) {
            arr2.push_back(arr[i]);
        }
    }
    for (int i=0; i<n; ++i) {
        if (arr[i] % 3 == 0 && arr[i] % 6 != 0) {
            arr2.push_back(arr[i]);
        }
    }
    
    return arr2;
}

signed main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;cin >> t;
    int n, v;
    vector<int> arr;
    for (int i=0; i<t; ++i) {
        cin >> n;
        for (int j=0; j<n; ++j) {
            cin >> v;
            arr.push_back(v);
        }
        arr = reorder(arr, n);
        for (int k=0; k<n; ++k) {
            cout << arr[k] << " ";
        } cout << "\n";
        arr.clear();
    }



    return 0;
}