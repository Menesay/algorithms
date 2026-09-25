
# meet in the middle

* bir arrayde kaç tane subsetin toplamı x'tir.
* [2,4,5,9] arrayinde elemanları toplamı 16 olan subset

* normalde tüm subsetler çıkartılıp brute force ile hesaplanabilir.

```
Meet in the Middle — example: [2,4,5,9], x = 15
════════════════════════════════════════════════

        ┌─────────────────────────┐
        │  Original: [2, 4, 5, 9] │
        └────────────┬────────────┘
                     │ split
           ┌─────────┴──────────┐
           ▼                    ▼
    ┌─────────────┐      ┌─────────────┐
    │   Half A    │      │   Half B    │
    │   [2, 4]    │      │   [5, 9]    │
    └──────┬──────┘      └──────┬──────┘
           │ all subsets        │ all subsets
           ▼                    ▼
    ┌─────────────┐      ┌──────────────┐
    │  SA (sorted)│      │  SB (sorted) │
    │ [0, 2, 4, 6]│      │ [0, 5, 9, 14]│
    └──────┬──────┘      └──────┬───────┘
           │                    │
           └─────────┬──────────┘
                     ▼
        ┌────────────────────────────┐
        │ ∃ a∈SA, b∈SB : a + b = x? │
        │  6 ∈ SA  +  9 ∈ SB = 15 ✓ │
        └────────────────────────────┘

Complexity:
  Generate each half : O(2^(n/2))
  Sort SA            : O(2^(n/2) · n)
  Binary search step : O(2^(n/2) · n)
  ─────────────────────────────────────
  Total              : O(2^(n/2) · n)
```


```cpp
// toplamı x olan subset var mı yok mu?
// Generate all subset sums of nums[l..r] and store in `sums`
void generate(vector<int>& nums, int l, int r, vector<int>& sums) {
    int n = r - l + 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1){
                s += nums[l + i];
            }
        }
        sums.push_back(s);
    }
}

bool meetInTheMiddle(vector<int>& nums, int x) {
    int n = nums.size();
    int half = n / 2;

    vector<int> SA, SB;
    generate(nums, 0, half - 1, SA);         // left half
    generate(nums, half, n - 1, SB);         // right half

    sort(SA.begin(), SA.end());

    // For each sum b in SB, binary search for (x - b) in SA
    for (int b : SB) {
        if (binary_search(SA.begin(), SA.end(), x - b)) {
            return true;
        }
    }
    return false;
}

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << (meetInTheMiddle(nums, x) ? "YES" : "NO") << "\n";
    return 0;
}
```

## subseti return eden versiyon
```cpp
/**
 * Generates all subset sums and maps each sum to its bitmask.
 * Using unordered_map for O(1) average lookup.
 */
void generate(const vector<int>& nums, int start, int count, unordered_map<int, int>& sumToMask) {
    for (int mask = 0; mask < (1 << count); mask++) {
        int currentSum = 0;
        for (int i = 0; i < count; i++) {
            if ((mask >> i) & 1) {
                currentSum += nums[start + i];
            }
        }
        // If multiple subsets have the same sum, we only need to store one.
        sumToMask[currentSum] = mask;
    }
}

vector<int> getSubsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    int n1 = n / 2;
    int n2 = n - n1;

    // Maps: Sum -> Bitmask
    unordered_map<int, int> SA, SB;

    generate(nums, 0, n1, SA);
    generate(nums, n1, n2, SB);

    for (auto const& [sumRight, maskRight] : SB) {
        int required = target - sumRight;
        
        if (SA.find(required) != SA.end()) {
            int maskLeft = SA[required];
            vector<int> result;

            // Reconstruct elements from the left half
            for (int i = 0; i < n1; i++) {
                if ((maskLeft >> i) & 1) result.push_back(nums[i]);
            }
            // Reconstruct elements from the right half
            for (int i = 0; i < n2; i++) {
                if ((maskRight >> i) & 1) result.push_back(nums[n1 + i]);
            }
            return result;
        }
    }

    return {}; // Return empty vector if no subset is found
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = getSubsetSum(nums, x);

    if (result.empty() && x != 0) {
        cout << "No subset found." << endl;
    } else {
        cout << "Subset found: ";
        for (int val : result) cout << val << " ";
        cout << endl;
    }

    return 0;
}
```