
# binary search
* eğer sorted ise n için küçükse n+1 için de küçüktür.
* eğer sorted ise n için büyükse n-1 için de büyüktür.
* prensibi ile çalışır.

```cpp
// method 1
// O(log n)
int a = 0, b = n-1;
while (a <= b) {
	
	int mid = (a+b)/2;
	
	if (array[mid] == x) {
		// x found at index k
	}
	if (array[mid] > x) {
		b = mid-1;
	} else {
		a = mid+1;
	}
}

// method 2
// O(log n)
int k = 0;
for (int b = n/2; b >= 1; b /= 2) {
	while (k+b < n && array[k+b] <= x) {
		k += b;
	}
}
if (array[k] == x) {
// x found at index k
}
```

## upper_bound and lower_bound
* x değerine en yakın alt yada üst index
```cpp
// x'ten >= olan ilk elmanın poziyonu.
auto lb = lower_bound(array, array+n, x);

// x'ten > olan ilk elemanın pozisyonu.
auto up = upper_bound(array, array+n, x);

// örnek
vector<int> v = {1, 3, 3, 3, 7, 9};
//               0  1  2  3  4  5

auto lb = lower_bound(v.begin(), v.end(), 3);
auto ub = upper_bound(v.begin(), v.end(), 3);

// bu yapılamaz çünkü lb bir iterator'dur ve pointer gibi davranır.
// cout << lb <<endl;

cout << "lower_bound(3) index: " << lb - v.begin() << "\n"; // 1
cout << "upper_bound(3) index: " << ub - v.begin() << "\n"; // 4
cout << "lower_bound(3) element:" << *lb << endl; // 3
cout << "upper_bound(3) element:" << *ub << endl; // 7
```

