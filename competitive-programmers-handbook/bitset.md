
# bitset
* içinde 0 yada 1 olan array
* uzunluğu sabit
* memory efficent

```cpp
bitset<10> bit;
bit[1] = 0

// from right to left
bitset<10> s(string("0010011010"));
cout << s[4] << "\n"; // 1
cout << s[5] << "\n"; // 0

// 1 sayısını return eder.
cout << s.count() << "\n"; // 4


bitset<10> a(string("0010110110"));
bitset<10> b(string("1011011000"));
cout << (a^b) << "\n"; // 1001101110
```