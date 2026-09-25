
# two-pointers method
* 2 tane indexin (pointerın) toplamda n adımda vectoru gezmesi
* O(n)

## subarray sum
* subarray : ardışık eleman seçimi elemanlar yanyana olmalı
* hangi subarrayler'deki elemanların toplamının x olduğu problem

If current sum < x → expanding right will increase the sum
If current sum > x → shrinking from the left will decrease the sum


```cpp
[1,  3,  2,  5,  1,  1,  2,  3]
 L
 R                                  sum = 1        < 8  → expand R

[1,  3,  2,  5,  1,  1,  2,  3]
 L   R                              sum = 1+3 = 4  < 8  → expand R

[1,  3,  2,  5,  1,  1,  2,  3]
 L       R                          sum = 4+2 = 6  < 8  → expand R

[1,  3,  2,  5,  1,  1,  2,  3]
 L           R                      sum = 6+5 = 11 > 8  → shrink L

[1,  3,  2,  5,  1,  1,  2,  3]
     L       R                      sum = 11-1 = 10 > 8 → shrink L

[1,  3,  2,  5,  1,  1,  2,  3]
         L   R                      sum = 10-3 = 7  < 8 → expand R

[1,  3,  2,  5,  1,  1,  2,  3]
         L       R                  sum = 7+1 = 8  == 8 → FOUND ✓
```

```cpp
bool subarraySum(vector<int> &arr, int target) {
    int left = 0, right = 0;
    int sum = arr[0];

    while (right < arr.size()) {
        if (sum == target){
            return true;
        }

        // Window too small, expand right
        else if (sum < target){
            sum += arr[++right];
        }

        // Window too big, shrink from left
        else{
            sum -= arr[left++];
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 3, 2, 5, 1, 1, 2, 3};
    int target = 8;
    if (subarraySum(arr, target)){
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}
```


## 2SUM
* sorted olmalı
* O(n) (sorted olduğu varsayılıyor.)

twosum
```cpp
[1,  2,  3,  5,  7]
 L               R     sum = 1+7 = 8  > 6  → move R left

[1,  2,  3,  5,  7]
 L            R        sum = 1+5 = 6  == 6 → FOUND ✓
```

* twosum
* O(n) (vectorun sortlu olduğu varsayılıyor.)
```cpp
bool twoSum(vector<int> &arr, int target){

    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target){
            return true;
        }
        
        // Move toward a higher sum
        else if (sum < target){
            left++; 
        }
      
        // Move toward a lower sum
        else{
            right--; 
        }
    }
  
    // If no pair found
    return false;
}

int main(){

    vector<int> arr = {-3, -1, 0, 1, 2};
    int target = -2;

    if (twoSum(arr, target)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}
```

