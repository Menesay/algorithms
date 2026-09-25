
# deque (double-ended queue)
* vector + push_front ve pop_front
* LIFO + FIFO

* ilk implementasyonu vectorden karmaşık olduğu için daha yavaş
* ama erişim hızı aynı O(1)



```cpp
deque<int> d;
d.push_back(5); // [5]
d.push_back(2); // [5,2]
d.push_front(3); // [3,5,2]
d.pop_back(); // [3,5]
d.pop_front(); // [5]
```