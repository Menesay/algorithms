
# Modulo
```
(a + b) mod m = (a mod m + b mod m) mod m  
(a - b) mod m = (a mod m - b mod m) mod m  
(a * b) mod m = (a mod m * b mod m) mod m
```

# Bitwise Even/Odd check
```
x & 1 == 1
```
* x : odd
* son bitinde 1 var.
* kullanmana gerek yok. compiler arka planda % 2 'yi buna optimize ediyor.
* hatta bazı sorularda bu çalışmadı, % 2 çalıştı.

# time complexity

```
O(log n)
n = 16 → 8 → 4 → 2 → 1    (4 steps = log₂16 = 4)
```
* log_2 n
* problemi 2ye bölen algoritma. örneğin binary search

```
O(n log n)
```
* Linearithmic
* n tane eleman için O(log n) operation yap
* genelde sort algoritmaları

# estimating efficiency
```
| input size | required time complexity |
|------------|--------------------------|
| n ≤ 10     | O(n!)                    |
| n ≤ 20     | O(2^n)                   |
| n ≤ 500    | O(n^3)                   |
| n ≤ 5000   | O(n^2)                   |
| n ≤ 10^6   | O(n log n) or O(n)       |
| n is large | O(1) or O(log n)         |
```

# subarray gez
```cpp
//int best = 0;
for (int a = 0; a < n; a++) {
    
    for (int b = a; b < n; b++) {
        
        //int sum = 0;
        
        for (int k = a; k <= b; k++) {
            
            //sum += array[k];
        
        }
        
        // best = max(best, sum);
    }
}

//cout << best << "\n";
```

# 2^n

```cpp
// 1       = 000001
// 1 << 3  = 001000  = 8 = 2³
int power2 = 1 << n;
```

# iterator
```cpp
{ 3, 4, 6, 8, 12, 13, 14, 17 }
  ^                          ^
  |                          |
s.begin()               s.end()

// elemana eriş
*s.end()
```

# 2^n

```cpp
// daha verimli
(1 << n)

// compiler yine de bunu yuakrdakine çevirir.
pow(2,n);
```

# const koymak
* 8 kat daha hızlı çalışıyor.
```cpp
const int  x = 100;
```

# substring
* pos: position
* len: length
```cpp
substr(pos, len);

string s = "abcdef";

cout << s.substr(3,2); // de
cout << s.substr(3); // def
```

# `[i]` vs `.at(i)`
```cpp
string s = "cpp";
// i kesin var.
// çok hızlı
s[i];

// i yoksa exception throw eder
// yavaş
s.at(i);
```

# DP
* hesaplarken 2 tane yaklaşım vardır:
up to bottom (100'den 1'e mesela)
bottom to up (1'den 100'e mesela)