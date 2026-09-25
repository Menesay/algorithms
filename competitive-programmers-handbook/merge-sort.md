# merge sort
* O(n logn)
* n kere array 2ye bölme işi yapıyor.

```c
[5, 3, 8, 1, 9, 2, 7, 4]

        Split phase (recurse down)
       /                        \
  [5, 3, 8, 1]            [9, 2, 7, 4]
   /        \               /        \
[5, 3]    [8, 1]        [9, 2]    [7, 4]
  / \       / \           / \      / \
[5] [3]  [8] [1]       [9] [2]  [7] [4]

        Merge phase (build back up)
[3, 5]    [1, 8]        [2, 9]    [4, 7]
    \      /                \      /
  [1, 3, 5, 8]          [2, 4, 7, 9]
         \                  /
      [1, 2, 3, 4, 5, 7, 8, 9]
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted halves: [left, mid] and [mid+1, right]
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)  temp.push_back(arr[i++]);

    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);       // sort left half
    mergeSort(arr, mid + 1, right);  // sort right half
    merge(arr, left, mid, right);    // merge both sorted halves
}

int main() {
    vector<int> arr = {5, 3, 8, 1, 9, 2, 7, 4};

    cout << "Before: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "After:  ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```