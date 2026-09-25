
# set
* 2 tip set var:
* `set`: balanced binary tree kullanır ve O(log n).
elementlarin sırasınsı tutar ve daha fazla func var.
* balances binray tree kullandığı için elemanlar sorted tutulur.
* lookup O(log n) ile ypaılır
* `unordered_set`: hashing kullanır ve O(1).
daha verimli olabilir

```cpp
set<int> s;

// insert ediyor, zaten sıralama önemsiz
s.insert(5);

// ikinci kere yapıldığında eklenmez. çünkü set
s.insert(5);

// delete
s.erase(5);


for (auto x : s) {
	// elemanları gez
}

for (auto i = s.begin(); i != s.end(); i++) {
	// elemanları gez ve eriş (*)
	cout << *i << endl;
}

```

# multiset 

# unordered set
* lookup O(1), içinde bir hash fonksiyonu var.
* dikkat O(1) ile aynı sürede veriyor ama o süre belli değil.
* input küçük : set, input büyük: unordered_set kullanmak mantıklı olan.
