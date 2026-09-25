# counting sort

* n, array uzunluğu küçük iken kullanılabilir.

```
Input array
───────────────────────────────────────
index │  0   1   2   3   4   5   6   7
value │  1   3   6   9   9   3   5   9

        count[arr[i]]++
              │
              ▼
Bookkeeping array (count[])
index = value, cell = # of occurrences

* n uzunluğunda count arrayi oluşturuyor.
* 0'dan n'ye kadar her sayıdan ne kadar var bilgisini tutuyor.
───────────────────────────────────────
index │  0   1   2   3   4   5   6   7   8   9
count │  0   1   0   2   0   1   1   0   0   3

count[v] → v appears count[v] times
              │
              ▼

Sorted output
───────────────────────────────────────
index │  0   1   2   3   4   5   6   7
value │  1   3   3   5   6   9   9   9
```

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

void counting_sort(vector<int>& arr) {
    if (arr.empty()) return;

    // Step 1: find the maximum element to size our bookkeeping array
    int c = *max_element(arr.begin(), arr.end());

    // Step 2: build the count (bookkeeping) array — O(n + c)
    // count[v] = how many times value v appears in arr
    vector<int> count(c + 1, 0);
    for (int x : arr){
        count[x]++;
    }

    // Step 3: reconstruct sorted array from the counts — O(n + c)
    // For each value v, write it count[v] times in order
    int idx = 0;
    for (int v = 0; v <= c; v++){
        while (count[v]--){
            arr[idx++] = v;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    counting_sort(arr);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " \n"[i == n-1];
    }
}
```