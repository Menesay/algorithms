#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int sum = n*(n+1)/2;

    if(sum % 2){
        cout<<0;
        return 0;
    }

    int target = sum/2;

    vector<int> dp(target+1);

    dp[0]=1;
    // num = 1 : [1,1,0,0,0,0,0...];
    // num = 2 : [1,1,1,1,0,0,0,...];
    // num = 3 : [1,1,1,2,1,1,1,0,0,0....];


    for(int num=1;num<=n;num++){

        for(int s=target;s>=num;s--){

            dp[s]+=dp[s-num];
            dp[s]%=MOD;



        }



    /*
    for (auto x : dp){ cout << x << " ";}
    	cout << endl;
    }
    */



    cout<<dp[target];

}