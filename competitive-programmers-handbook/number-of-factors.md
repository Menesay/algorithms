
# number of factors - bölen sayısı
d(n) : bölen sayısı
sigma(n) : bölenlerin toplamı

```
╔══════════════════════════════════════════════════════════════╗
║         ARİTMETİK FONKSİYONLAR: d(n) ve σ(n)                 ║
║                     n = 60                                   ║
╚══════════════════════════════════════════════════════════════╝

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
ADIM 1 — ASAL ÇARPANLARA AYIR
──────────────────────────────
  60 = 2² × 3¹ × 5¹
  Genel form:   n = p1^a1 × p2^a2 × ... × pk^ak
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
ADIM 2 — d(n): BÖLEN SAYISI FONKSİYONU
────────────────────────────────────────
  Formül:
           k
  d(n)  =  ∏  (ai + 1)
          i=1

  Yani her üssü 1 artır, hepsini çarp.
  60 = 2² × 3¹ × 5¹  için:
  d(60) = (2+1) × (1+1) × (1+1)
        =   3   ×   2   ×   2
        =  12
  ┌─────────────────────────────────────────────────────┐
  │  60'ın 12 böleni vardır.                            │
  └─────────────────────────────────────────────────────┘

  Bölenlerin listesi:
  { 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60 }
    └──────────────────────────────────────┘
              toplam 12 tane ✓
NOT: 12 pozitif, 12 negatif : 24 tam böleni vardır.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
ADIM 3 — σ(n): BÖLENLERİN TOPLAMI FONKSİYONU
──────────────────────────────────────────────
  Formül:
           k    pᵢ^(aᵢ+1) - 1
  σ(n)  =  ∏  ───────────────────
          i=1      pᵢ - 1

  Her asal p için:  1 + p + p² + ... + p^a  =  (p^(a+1) - 1) / (p - 1)
  (geometrik seri)

  60 = 2² × 3¹ × 5¹  için:

  σ(60) = σ(2²)  ×  σ(3¹)  ×  σ(5¹)

          2³ - 1     3² - 1     5² - 1
        = ───────  × ───────  × ───────
           2 - 1      3 - 1      5 - 1

           8 - 1      9 - 1     25 - 1
        = ───────  × ───────  × ───────
             1          2          4

           7     8     24
        = ─── × ─── × ────
           1     2      4

        =  7  ×  4  ×  6

        = 168
  ┌─────────────────────────────────────────────────────┐
  │  60'ın bölenlerinin toplamı = 168                   │
  └─────────────────────────────────────────────────────┘
  Doğrulama (elle toplama):
  1 + 2 + 3 + 4 + 5 + 6 + 10 + 12 + 15 + 20 + 30 + 60 = 168 ✓
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
ÖZET
────
  n  =  60  =  2² × 3¹ × 5¹
  d(60)  =  (2+1)(1+1)(1+1)               =  12
  σ(60)  =  (1+2+4)(1+3)(1+5)  =  7×4×6  =  168

  NOT: Her iki fonksiyon da MULTIPLICATIVE'dir:
       gcd(a,b)=1  ⟹  f(ab) = f(a)·f(b)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```


# bolen sayısı
```cpp
vector<int> bolen_sayisi(N + 1);

for (int i = 1; i <= N; i++) {
  for (int j = i; j <= N; j += i) {
    bolen_sayisi[j]++;
  }
}
```

# bolen sayısı
```cpp
int count_divisors(int n){
    /*

    kareköküne kadar 2şer bölen vardır
    karekökünde 1 bölen vardır.

    Count the number of divisors for a given integer n.
    Time Complexity: O(√n)
    Args:
        n: Integer to find divisor count for
    Returns:
        Number of divisors
    Examples:
        count_divisors(12) -> 6  (divisors: 1, 2, 3, 4, 6, 12)
        count_divisors(28) -> 6  (divisors: 1, 2, 4, 7, 14, 28)
        count_divisors(1) -> 1   (divisor: 1)
    */
    if (n <= 0 ){
        return 0;
    }
    
    int count = 0;
    int i = 1;
    
    while (i * i <= n ){
        
        if ( n % i == 0 ){
        
            if (i * i == n ){
                count += 1;
            } else {
              count += 2;
            }
        }
                
        i += 1;
    }
    
    return count;

}
```