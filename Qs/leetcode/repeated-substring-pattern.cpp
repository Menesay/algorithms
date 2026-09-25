class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
            if(s.length() == 1){
                    
                    return false;
            }


            vector<string> v;

            // yarısına kadar olan tüm substringleri al
            for(int i = 1; i < s.length()/2 + 1 ; i++){

                v.push_back(s.substr(0,i));
            }

            /*
            elements of v
        x: a
        x: ab
        x: aba
        x: abaa
        x: abaab
            */

            vector<string> v2;
            for(auto x : v){

                string curr_str = "";
                for(int i = 0; i < s.length() - x.length() ; i += x.length()){

                    curr_str += x;

                }
                curr_str += x;
                v2.push_back(curr_str);


            }


            for(auto x: v2){
                if(x == s){
                    return true;
                }
            }
            return false;

    }
};