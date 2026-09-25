#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

int c = 0;

// Merges two sorted halves: [left, mid] and [mid+1, right]
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    c++;

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

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;

	mergeSort(v, 0, v.size() - 1);

    for (int x : v) cout << x << " ";
    cout << "\n";
	
	cout << c;

}