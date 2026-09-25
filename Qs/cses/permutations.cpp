#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;


	if (n==1){
		cout <<"1";
		exit(0);
	}
	if (n==2 || n==3){
		cout << "NO SOLUTION";
		exit(0);
	}


	if ((n&1)==1){

		

        for(int i=2; i<=n-1; i+=2){
        	// 2 4 6
            cout << i << " ";
        }
        
        cout << "1 3 ";

        for(int i=5; i<=n; i+=2){
            // 5 7 9
            cout << i << " ";
        }
	} 

	else {

		for(int i=2; i<=n; i+=2){
            cout << i << " ";
		}

        cout << "1 3 ";
        
        for(int i=5; i<=n-1; i+=2){
            cout << i << " ";
        }

	} 

}

