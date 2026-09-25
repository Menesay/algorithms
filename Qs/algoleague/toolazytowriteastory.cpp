#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	/* Time limit yiyor

		find : O(n)
		n . find : O(n^2)
		index'leri bir vectorde tutuyor bunda.

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    vector<int> v_original;
    vector<int> v_indexlist(n);

    for(auto &x : v) {
        cin >> x; v_original.push_back(x);
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        v_indexlist[i] = find(v_original.begin(), v_original.end(), v[i]) - v_original.begin();
    }

    int res = 0;
    for(int i = 1; i<=n; i++){
    	res += abs(v_indexlist[i] - v_indexlist[i-1]);
    }
    cout << res;

    */


    // index map ile çözüm
    // index map : O(1)

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n);

    // value -> original index
    unordered_map<int,int> idx; 
    
    for(int i = 0; i < n; i++){
        cin >> v[i];

        // ilk index değerleri bu mapte saklandı
        idx[v[i]] = i;
    }
    
    sort(v.begin(), v.end());
    
    int res = 0;
    for(int i = 1; i < n; i++){

    	// eski index değerinin ne olduğuna erişilebiliniyor.
        res += abs(idx[v[i]] - idx[v[i-1]]);
    }
    cout << res;

}