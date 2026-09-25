
# generating subsets
* brute force
* O(2^n n)

## recursion
```
search(0)
├── search(1)                          [0 NOT included]
│   ├── search(2)                      [1 NOT included]
│   │   ├── search(3) → ∅              [2 NOT included]
│   │   └── search(3) → {2}            [2 included]
│   └── search(2)                      [1 included]
│       ├── search(3) → {1}            [2 NOT included]
│       └── search(3) → {1,2}          [2 included]
└── search(1)                          [0 included]
    ├── search(2)                      [1 NOT included]
    │   ├── search(3) → {0}            [2 NOT included]
    │   └── search(3) → {0,2}          [2 included]
    └── search(2)                      [1 included]
        ├── search(3) → {0,1}          [2 NOT included]
        └── search(3) → {0,1,2}        [2 included]
```


```cpp
int n;
vector<int> subset;
void search(int k) {
    if (k == n) {
        // Print current subset
        // bu sebset for ile gezilip işlem yapılabilir.
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
        return;
    }

    // Left branch: do NOT include k
    search(k + 1);

    // Right branch: include k
    subset.push_back(k);
    search(k + 1);
    subset.pop_back();  // backtrack
}
int main() {
    n = 3;
    search(0);
    return 0;
}
```

```
{ }
{ 2 }
{ 1 }
{ 1 2 }
{ 0 }
{ 0 2 }
{ 0 1 }
{ 0 1 2 }
```

## bitmask / bit representation
```cpp
int main() {
    int n = 3;

    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;

        for (int i = 0; i < n; i++) {
            
        	// b & 2^i
            if (b & (1 << i)) {

                // direkt subset kaldırılıp burada o anki subsetin elemanlarına (i) erişiebilir.
                subset.push_back(i);
            }
        }

        // Print
        // bu sebset for ile gezilip işlem yapılabilir.
        cout << "b=" << b << "  bits=";
        for (int i = n-1; i >= 0; i--){
            cout << ((b >> i) & 1);
        }
        
        cout << "  subset={ ";
        for (int x : subset){

            // subset indexleri
            cout << x << " ";
        }
        
        cout << "}\n";
    }
}
```
```
b=0  bits=000  subset={ }
b=1  bits=001  subset={ 0 }
b=2  bits=010  subset={ 1 }
b=3  bits=011  subset={ 0 1 }
b=4  bits=100  subset={ 2 }
b=5  bits=101  subset={ 0 2 }
b=6  bits=110  subset={ 1 2 }
b=7  bits=111  subset={ 0 1 2 }
```