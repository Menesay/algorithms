
# sort function on cpp
```cpp
vector<int> v = {4,2,5,3,5,8,3};

// sort
sort(v.begin(),v.end());

// reverse sort
sort(v.rbegin(),v.rend());
```

```cpp
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});

// pair sort
// (1,2), (1,5), (2,3)
sort(v.begin(), v.end());
```