
# priority queue
* set gibidir ama heap kullanığı için daha hızlı
* sorted tutar.
* insert ve remove: O(log n)
* lookup : O(1)
* top() ile sürekli en büyük elemanı tutar.
* pop() : O(log n), binary tree olduğu için tree yeniden yapılandırılıyor.

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(5);
pq.push(7);
pq.push(2);

// 7 5 3 2 
cout << pq.top() << "\n"; // 7

pq.empty(); // false

```