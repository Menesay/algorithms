#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

    int n, elf;
    cin>>elf>>n;
    if(elf>=n) {cout<<0; return 0;}

    vector<int> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

    sort(v.begin(), v.end());
    int ans=v[n-1]-v[0];

    vector<int> diff;
    for(int i=0;i<n-1;i++){
    	diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.begin(), diff.end(), greater<int>());

    for(int i=0;i<elf-1;i++) ans-=diff[i];

    cout<<ans;
    return 0;
}


