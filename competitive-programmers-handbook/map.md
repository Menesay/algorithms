
# map
* 2 tip map var:
* `map`: balanced binary tree kullanır ve O(log n).
elementlarin sırasınsı tutar ve daha fazla func var.
* `unordered_map`: hash map: hashing kullanır ve O(1).
daha verimli olabilir

```cpp
map<string, int> m;

// add element
m["key1"] = 1;
m["key2"] = 2;

// hinsert
m.insert({"key3", 3});

// delete
m.erase("key1");

if (m.count("key1")) {
	// key exists
}


// key == "key2" olan elemanı bul
// O(log n)
auto f1 = m.find("key1");
if (f1 != m.end()){
    cout << f1->first << " " << f1->second;
} else {
 	cout << "Key not Found!";
}


for (auto i = m.begin(); i != m.end(); ++i) {
  	// mapi gez  
    cout << i->first << " " << i->second << endl;
}
for (auto x : m) {
	// mapi gez
	cout << x.first << " " << x.second << endl;
}

```

```cpp
unordered_map<char, int> hm;
hm['A'] = 1;

cout << hm['A'] << endl; // 1

// mapi gez
for (auto x : hm) {
	cout << x.first << ": " << x.second << endl; // A: 1
}

// Finding element with key A
auto it = hm.find('A');    
if (it != hm.end()){
    cout << it->first << ": " << it->second; // A: 1
}
else {
	cout << "Not Found";
}

// delete
hm.erase('A');
```