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
    
    int count = 0;
    
    if(n == 1) {cout << "0"; exit(0);}
    
    int f;
    cin >> f;
    
    for (int i=1; i < n; i++){
    
        int s;
        cin >> s;
    
        if(s < f){
            count += f - s;
            s = f;
        }
        f = s;	
    }
    cout << count;
}