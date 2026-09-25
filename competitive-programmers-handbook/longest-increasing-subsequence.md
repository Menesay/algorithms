# longest increasing subsequence
* DP problemidir klasik.

array
```
+----+----+----+----+----+----+----+----+
| 6  |  2 |  5 | 1  |  7 |  4 | 8  |  3 |
+----+----+----+----+----+----+----+----+
```
2,5,7,8 istenen subseqtir.

* length(k) = k. indexte son bulan longest increasing subseqin uzunluğu
length(0) = 1
length(1) = 1
length(2) = 2
length(3) = 1
length(4) = 3
length(5) = 2
length(6) = 4
length(7) = 2

* tespit edilmesi için:
array[i] < array[k]
i < k
olması gerekli.

* bu sağlandığında length(k) = length(i) + 1 olur.

```cpp
int length[n-1];
for (int k = 0; k < n; k++) {
	length[k] = 1;
	for (int i = 0; i < k; i++) {
		if (array[i] < array[k]) {
			length[k] = max(length[k],length[i]+1);
		}
	}
}
```

