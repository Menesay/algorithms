
# vector

```cpp
vector <int> v;
// size 10, values 0
vector<int> v(10, 0);

// pushla
// O(1)
v.push_back(5);

// 1. index'e 5 insert et.
// O(n)
v.insert(v.begin() + 1, 5);

// last elementi bobla
v.pop_back();

// 5'i delete et
// O(n)
v.erase(find(v.begin(), v.end(), 5));

// size
v.size();

// globalde tanımladıktan sonra n büyüklüğüne set etmek için
v.resize(n);

for (auto x : v){
	// eleman gez
}

```