#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;

	unordered_map<char, int> hm;
	vector<char> v;

	for(int i ; i < s.length(); i++){
		// A görüldüğünde görüldü sayısı 1 artacak.
		hm[s[i]]++;
	}

	int odd_number = 0;
	int stack_size = 0;
	vector<char> odd_numbers;


	stack<char> palindrom_order;


	// middle_element yoksa bu olacak
	//char middle_element = '*';
	
	for(auto x: hm){
		// tek sayıda varsa
		if(x.second % 2 == 1){

			odd_numbers.push_back(x.first);
			odd_number += 1;
		}

		//cout << x.first << ":" << x.second << endl;

		// çiftse
		if(x.second % 2 == 0){
			//cout << x.second << " is even" << endl;
			// 4 tane A varsa
			// A A
			for(int i = 0; i<x.second/2; i++){
				v.push_back(x.first);
				palindrom_order.push(x.first);
				stack_size++;
			}

		}

	}

	// DDDAABB
	// v = A B

	if (odd_numbers.size() > 1){
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	if(odd_numbers.size() == 1){
		for(int i = 0; i < hm[odd_numbers[0]] ; i++ ){
			v.push_back(odd_numbers[0]);
		}

	}


	// v = A B D D D

	for(int i = 0 ; i < stack_size ; i++) {
		v.push_back(palindrom_order.top());
		palindrom_order.pop();
	}



	for(auto x : v){
		cout << x;
	}	

}