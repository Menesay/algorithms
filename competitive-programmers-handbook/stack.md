
# stack
* O(1) erişim
* parantez dengesi soruları
* method: monotonic stack


```cpp
stack<int> s;

s.push(3);
s.push(2);
s.push(5);

cout << s.top(); // 5

s.pop();

cout << s.top(); // 2

s.empty(); // false
```

