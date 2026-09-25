
# linear sieve
* O(n)
* n'ye kadar olan prime'ları listele
```cpp
vector<int> linear_sieve(int n) {
    if (n < 2) return {};
    
    // 35 sayısının spf'si 5.
    vector<int> spf(n + 1, 0); // Smallest prime factor
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) { // i is prime
            spf[i] = i;
            primes.push_back(i);
        }
        
        for (int p : primes) {
            if (p > spf[i] || (long long)i * p > n) break;
            spf[i * p] = p;
        }
    }
    
    return primes;
}
```