# Maximum subarray sum

array
```
+----+----+----+----+----+----+----+----+
| -1 |  2 |  4 | -3 |  5 |  2 | -5 |  2 |
+----+----+----+----+----+----+----+----+
```

buradaki max subarray sum : 2,4,-3,5,2

# algo 1
* O(n^3)
* tüm subarrayleri gezip toplayan algoritma
```cpp
int best = 0;
for (int a = 0; a < n; a++) {
    for (int b = a; b < n; b++) {
        int sum = 0;
        for (int k = a; k <= b; k++) {
            sum += array[k];
        }
        best = max(best, sum);
    }
}
cout << best << "\n";
```

# algo 2
* bir önceki suma yeni gelen değeri ekleyerek maxı buluyor.
```cpp
int best = 0;
for (int a = 0; a < n; a++) {
    int sum = 0;
    for (int b = a; b < n; b++) {
        sum += array[b];
        best = max(best, sum);
    }
}
cout << best << "\n";
```

# algo 3
* O(n)
* her seferinde sum + next eleman
* Kadane's algorithm
```cpp

    int n;
    cin >> n;
    int x;
    // initializing them as -infinity
    int sum = -INF;
    int best = -INF;

    for(int i=0; i< n ; i++){
        cin >> x;

        sum= max(x, sum + x);

        best= max(best, sum);

    }

    cout << best;

```

