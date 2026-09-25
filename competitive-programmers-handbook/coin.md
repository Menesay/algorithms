
# dynamic programming
* DP aynı problemi küçük parçalara bölmektir.
* slow ama her zaman correct

* üst üste gelen, independent olarak çözülebilinecek problemler olduğunda DP.

# coin problem
* coins = {1,3,4}
* solve(x) fonksiyonu x sayısının en az kaç coin kullanılarak elde edilebilineceğini göstersin.
solve(0) = 0
solve(1) = 1
solve(2) = 2
solve(3) = 1
solve(4) = 1
solve(5) = 2
solve(6) = 2
solve(7) = 2
solve(8) = 2
solve(9) = 3

solve(10) = 3
* solve fonksiyonunu hesaplarken ilk seçilen eleman önemli
eğer 1 şeçilirse sonraki adımda solve(10 - 1) çağrılacak
eğer 3 şeçilirse sonraki adımda solve(10 - 3) çağrılacak
eğer 4 şeçilirse sonraki adımda solve(10 - 4) çağrılacak
bu 3 ihtimalden en küçük olan istediğimiz. o zaman:

solve(x) = min( solve(x−1)+1 , solve(x−3)+1 , solve(x−4)+1 )

* O(k^n) : her node coin sayısı kadar node açıyor.
n: target sum 
k: coin sayısı

```cpp
int solve(int x) {
	if (x < 0) return INF;
	if (x == 0) return 0;
	
	int best = INF;
	for (auto c : coins) {
		best = min(best, solve(x-c)+1);
	}
	return best;
}
```

## memoization method
* best'leri bir array'de saklamak. bu sayede `value[5]` (yani solve(5)) sadece 1 kere hesaplanıyor.
* O(nk)
n: target sum 
k: coin sayısı

* bottom-top memoization (1'den n'e kadar olan x'lere bakıyor)
```cpp
// value[x] : x'e ulaşmak için gerekli coin sayısını tutuyor. 
// solve fonksiyonun sonucu

vector<int> value(n);
value[0] = 0;
for (int x = 1; x <= n; x++) {
	value[x] = INF;
	for (auto c : coins) {
		if (x-c >= 0) {
			value[x] = min(value[x], value[x-c]+1);
		}
	}
}

```

# coin problem 2
* total çözme şeklini sorsaydı ve n = 5 olsaydı
1+1+1+1+1
1+1+3
1+3+1
3+1+1
1+4
4+1
şeklinde 6 yolla çözülcekti.

* n = 0 olsaydı 1 yol olacaktı çünkü empty sum elde etmenin 1 yolu var.

```cpp
// n = 0 durumu için 1
count[0] = 1;
for (int x = 1; x <= n; x++) {
	for (auto c : coins) {
		if (x-c >= 0) {

			// her bir index kendisi oluşturan index-coin'ler kadar
			count[x] += count[x-c];
		}
	}
}
```