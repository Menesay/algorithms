
# generating permutations
* brute force

## recursion

```cpp
int n = 3;
vector<int> permutation;

// >= n olan bir sayı ver. safe olsun
bool chosen[n];

void search() {
    if ((int)permutation.size() == n) {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
        chosen[i] = true;
        permutation.push_back(i);
        search();
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main(){
	memset(chosen, false, sizeof(chosen));
    search();
}
```
```
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
```

## next_permutation (iterative)
```cpp
void iterative(int n) {
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }

    // sorted olmalı
    sort(permutation.begin(), permutation.end());

    do {
    	// current perm
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));
}

int main(){
	iterative(3);
}
```

```
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
```