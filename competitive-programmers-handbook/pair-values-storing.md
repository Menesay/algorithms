
# Pair values storing

## vector
```cpp
vector<pair<int,int>> v;
// Adding pairs
v.push_back({3, 10});
v.push_back({1, 50});
v.push_back({2, 30});
v.push_back({1, 20}); 

sort(v.begin(), v.end());
```

Sortlandı, sırayla:
1 -> 20
1 -> 50
2 -> 30
3 -> 10



# `map<int,int>` — when keys are unique

```cpp
map<int,int> mp;
mp[3] = 10;
mp[1] = 50;
mp[2] = 30;
// Automatically sorted by key
for (auto& [k, v] : mp){
    cout << k << " -> " << v << "\n";
}
```
Use when: keys are unique, you need fast lookup O(log n), auto-sorted.

 
# `unordered_map<int,int>` — fast lookup, no order
Cpp
```cpp
unordered_map<int,int> ump;
ump[3] = 10;
ump[1] = 50;
// O(1) average lookup, but no guaranteed order
```
Use when: you only care about lookup speed, not order.


# Sorting with Original Index

```cpp
vector<pair<int,int>> v; // {value, original_index}
for (int i = 0; i < n; i++){
    v.push_back({a[i], i});
}
sort(v.begin(), v.end());
// Now v[i].second gives you where it came from
```

Used in: inversion count, coordinate compression, rank queries.
