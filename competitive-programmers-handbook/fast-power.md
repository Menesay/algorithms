
# fast power and combination

* question C(10^6 , 10^3) = (10^6)! / ( (10^3)! (10^6 - 10^3)! ) nedir?


```cpp

// 10^6
const int MAX = 1e6;
const int MOD = 1e9+7;

// fast power, fast exponentiation
// a^b
int fp(int a, int b){

	if(b==0) return	1;
	int res = fp(a, b/2);
	res *= res;
	// tekse bi de a ile çarp
	if(b & 1) res *= a;

	return res;
}


// fact[x] = x!
// olacak şekilde array dolduruyoruz
int fact[MAX];
void factorize(){
	fact[1] = 1;

	for(int i = 2 ; i < MAX; ++i){
		// overflow olmasın diye MOD koyduk
		fact[i] = i * fact[i-1] % MOD;
	}
}

void solve(){

	int N, R;
	cin >> N >> R;

	// C(N, R) = N! / R! * (N-R)!
	int ans = fact[N];
	ans = ans * fp(fact[N], MOD-2) % MOD;
	ans = ans * fp(fact[N-R], MOD-2) % MOD;

	cout << ans;


}
```

