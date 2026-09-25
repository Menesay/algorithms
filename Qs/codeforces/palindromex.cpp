#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

bool pal(vector<int> v){

// 1 2 0 3 3 0 2 1
	for(int i =0; i<v.size() / 2 ; ++i){
		if(v[i] != v[v.size()-i-1]){
			return false;
		}
	}
	return true;

}

int mex(vector<int> v){

// 1 2 0 3 3 0 2 1
	
	// 0 ,2 ,1
	// 0, 2
	// 1, 2
	sort(v.begin(), v.end());

	if(v[0] != 0){

	}

	int i = 0;
	int j = 0;
	while(j < v.size()){

		if(v[j] != i){
			return i;
		} else {
			while(j < v.size() && v[j] == i ){
				++j;
			}
	
			++i;
		}
	}

	return i;


}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int q; cin >> q;

	while(q>0){


		int n; cin >> n;
		vector<int> v;
		int ni;
		for(int i = 0; i<2*n;++i ){
			cin >> ni;
			v.push_back(ni);
		}

		int max_mex = 0;
		for (int a = 0; a < 2*n; a++) {
    
		    for (int b = a; b < 2*n; b++) {
		        
		        vector<int> currv;
		        for(int i = a ; i<=b; ++i){
		        	currv.push_back(v[i]);
		        }

		        if(pal(currv)){
		        	int x;
		        	x = mex(currv);
		        	max_mex = max(max_mex, x);
		        }
		        
		        
		    }
		}

		cout << max_mex << endl;



		q--;
	}
}