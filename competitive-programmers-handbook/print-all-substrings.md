
# print all substrings
```cpp
string s = "abcd";
int n = s.length();
    
// Logic to print all substring
// using substr()
for (int i = 0; i < n; i++){
    for (int len = 1; len <= n - i; len++){
        cout << s.substr(i, len) << endl;
    }
}
```

```
a
ab
abc
abcd
b
bc
bcd
c
cd
d
```