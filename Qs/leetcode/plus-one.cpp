
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // [4,3,2,1]

        int last_idx = digits.size()-1;
        
        if(digits[last_idx] != 9){
            digits[last_idx] += 1;
            return digits;
        }

        while(digits[last_idx] == 9){

            digits[last_idx] = 0;

            if (last_idx - 1 >= 0){
                last_idx -= 1;
            }
            
        }

        if (last_idx == 0 && digits[last_idx] == 0){
            vector<int> digits2;
            digits2.push_back(1);
            for(auto x : digits){
                digits2.push_back(x);
            }

            return digits2;

        }else{
            digits[last_idx] += 1;

            return digits;
        }
        
    }
};