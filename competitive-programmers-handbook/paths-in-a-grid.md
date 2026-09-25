
# paths in a grid
* DP problemi klasik.
* upper-left'ten lower-right'a max sumı oluşturacak şekilde gitme problemi
* O(n^2)
```
+-----+-----+-----+-----+-----+
| [3] |  7  |  9  |  2  |  7  |
+-----+-----+-----+-----+-----+
| [9] | [8] |  3  |  5  |  5  |
+-----+-----+-----+-----+-----+
|  1  | [7] | [9] | [8] | [5] |
+-----+-----+-----+-----+-----+
|  3  |  8  |  6  |  4  | [10]|
+-----+-----+-----+-----+-----+
|  6  |  3  |  9  |  7  | [8] |
+-----+-----+-----+-----+-----+
```

* herhangi bir kareye
ya üssten (y-1)
yada soldan (x-1)
gelinebilir.

`sum(y, x) = max( sum(y, x−1) , sum(y−1, x) ) + value[y][x]`


```cpp
int sum[n][n];

for (int y = 1; y <= n; y++) {
	for (int x = 1; x <= n; x++) {
		sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
	}
}
```


fully implementation
```cpp
/* input
3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
*/

/*
grid array
     x=0  x=1  x=2  x=3  x=4  x=5
y=0 [  0    0    0    0    0    0 ]
y=1 [  0    3    7    9    2    7 ]
y=2 [  0    9    8    3    5    5 ]
y=3 [  0    1    7    9    8    5 ]
y=4 [  0    3    8    6    4   10 ]
y=5 [  0    6    3    9    7    8 ]


dp array
     x=0  x=1  x=2  x=3  x=4  x=5
y=0 [  0    0    0    0    0    0 ]
y=1 [  0    3   10   19   21   28 ]
y=2 [  0   12   18   21   26   31 ]
y=3 [  0   13   25   34   42   47 ]  ← wait
y=4 [  0   16   33   40   46   57 ]
y=5 [  0   22   36   45   53   65 ]

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	// n = 5
    int n;
    cin >> n;
    
    vector<vector<int>> grid( n+1, vector<int>(n+1) );
    vector<vector<long long>> dp( n+1, vector<long long>(n+1, 0) );
    
    for (int y = 1; y <= n; y++){
        for (int x = 1; x <= n; x++){
        	// satır satır topluyor
        	// y: row, x: column
        	// ROW major order'da okunur
        	// 3 7 9 2 7
            cin >> grid[y][x];
        }
    }
    
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            dp[y][x] = max(dp[y][x-1], dp[y-1][x]) + grid[y][x];
        }
    }
    
    // path reconstruction
    vector<pair<int,int>> path;
    int y = n, x = n;
    while (y > 1 || x > 1) {
        path.push_back({y, x});
        if (y == 1) x--;
        else if (x == 1) y--;
        else if (dp[y-1][x] > dp[y][x-1]) y--;
        else x--;
    }
    path.push_back({1, 1});
    reverse(path.begin(), path.end());
    
    // 67
    cout << dp[n][n] << "\n";
    
    // optional: print path
    /* y,x
	1 1
	2 1
	2 2
	3 2
	3 3
	3 4
	3 5
	4 5
	5 5
    /*
    //for (auto [r,c] : path) cout << r << " " << c << "\n";
    
    return 0;
}
```