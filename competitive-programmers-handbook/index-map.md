
# index map

```cpp
    // index map ile çözüm
    // index map : O(1)

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
```