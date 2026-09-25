
# quick sort

* pivot genelde worst case en düşük ihtimalle gelsin diye rastgele seçilir.
* O(n logn)
```
[10, 80, 30, 90, 40, 50, 70]
                       |
             Partition around 70
             /         |         \
   [10, 30, 40, 50]   (70)    [90, 80]
          |                      |
  Partition (50)          Partition (80)
      /   |   \               /  |  \
[10,30,40](50) []           [] (80) [90]
    |                                 |
(Recursion continues...)          (Sorted!)
```

```cpp

int partition(vector<int>& arr, int low, int high) {
  
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {      
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
}
```