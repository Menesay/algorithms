
# bubble sort
* O(n^2)
* n kere tüm dizi boyunda 2li bakıyor.


```cpp

// basic
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n-1; j++) {
		if (array[j] > array[j+1]) {
			swap(array[j],array[j+1]);
		}
	}
}
```


```cpp
// optimized
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        if (!swapped){
            break;
        }
        
    }
}

signed main() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    bubbleSort(arr);


}
```