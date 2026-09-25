
# prefix sum

vector
+---+---+---+---+---+---+
| 1 | 4 | 2 | 6 | 5 | 3 |
+---+---+---+---+---+---+

pref
+---+---+---+---+----+----+----+
| 0 | 1 | 5 | 7 | 13 | 18 | 21 |
+---+---+---+---+----+----+----+


```cpp
// function to find the prefix sum array
vector<int> prefSum(vector<int> &arr) {
    int n = arr.size();
    
    // to store the prefix sum
    vector<int> prefixSum(n);

    // initialize the first element
    prefixSum[0] = arr[0];

    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}

signed main() {
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = prefSum(arr);

    // prefixSum = {10, 30 ,40, 45, 60}
    for(auto i: prefixSum) {
        cout << i << " " ;
    }
}
```

```cpp
vector<int> v(n);
for(auto &x : v) cin >> x;
  
vector<int> pref(n + 1);
for (int i = 1; i <= n; i++) {
	pref[i] = pref[i - 1] + v[i - 1];
}

// pref[0] == 0. eleman
// pref[1] == 0. eleman + 1. eleman
```