
// 1.tip stack sorusu
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5;
const int MOD = 1e9+7;
const int INF = 1e18;

class Solution {
public:
    bool isValid(string s) {
  	      


  	      stack<char> stack0;

  	      // ()[]{}
  	      // ([)]
  	      // (){()}
  	      for(int i = 0; i<s.length(); i++){

  	      		if(s[i] == '{' || s[i] == '(' ||s[i] == '[' ){
  	      			stack0.push(s[i]);
  	      		
  	      		} else if (s[i] == '}'){
  	      		
  	      			if (stack0.empty() == 1 || stack0.top() != '{') {
  	      				return false;
  	      			}
  	      			stack0.pop();
  	      		
  	      		} else if (s[i] == ']'){
  	      			if (stack0.empty() == 1 || stack0.top() != '[') {
  	      				return false;
  	      			}
  	      			stack0.pop();
  	      		} else if (s[i] == ')'){
  	      			if (stack0.empty() == 1 || stack0.top() != '(') {
  	      				return false;
  	      			}
  	      			stack0.pop();
  	      		} 

    		}

    		return stack0.empty();

}
};
