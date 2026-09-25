#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;


signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n_;
	cin >> n_;
	
	vector<int> arr1(n_);
	vector<int> arr2(n_);
	for(auto &x : arr1) cin >> x;

	for(int i = 0; i<n_ ; i++){
		arr2[i] = arr1[i]; 
	}



    int n = arr1.size();
    bool swapped1;
    bool swapped2;
  
  	int c1 = 0;
  	int c2 = 0;
    
    for (int i = 0; i < n - 1; i++) {
        swapped1 = false;
       
        for (int j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swap(arr1[j], arr1[j + 1]);
                swapped1 = true;
            	c1 += 1;
            }

        }
      
        if (!swapped1){
            break;
        }

    }

	for (int i = 0; i < n - 1; i++) {
        
        swapped2 = false;
        for (int j = 0; j < n - i - 1; j++) {
            
        	// less than
            if (arr2[j] < arr2[j + 1]) {
                swap(arr2[j], arr2[j + 1]);
                swapped2 = true;
            	c2 += 1;
            }

        }
      
        if (!swapped2){
            break;
        }

    }


    cout << min(c1,c2);
}