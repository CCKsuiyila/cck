//66
class Solution {      //quick but ugly
public:
    vector<int> plusOne(vector<int>& digits) {
		int next = 1;
        for(int i=digits.size()-1;i>=0;--i){
			if(next!=0){
				if(digits[i]!=9){
					++digits[i];
					next = 0;
					return digits;
				}else{
					digits[i]=0;
				}
			}else{
				return digits;
			}
        }   
		
        digits[0] = 1;
        digits.push_back(0);
		return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
		int next = 1;
        for(int i=digits.size()-1;i>=0;--i){
            if(digits[i]!=9&&next!=0){
                ++digits[i];
                next = 0;
				break;
            }else if(digits[i]==9&&next!=0){
                digits[i]=0;
            }else{
                break;
            }
        }   
		
		if(next == 1){                                  //special case
            digits[0] = 1;
            digits.push_back(0);
        }
		
		return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
		int next = 1;
        for(int i=digits.size()-1;i>=0;--i){
            if(digits[i]!=9&&next==0){
                break;
            }else if(digits[i]!=9&&next!=0){
                ++digits[i];
                next = 0;
				break;
            }else if(digits[i]==9&&next==0){
                break;
            }else if(digits[i]==9&&next!=0){
                digits[i]=0;
            }
        }   
		
		if(next == 1){                                  //special case
            digits[0] = 1;
            digits.push_back(0);
        }
		
		return digits;
    }
};



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int sign = 0;
        for(int i=0;i<digits.size();++i){
            if(digits[i]!=9){
                sign = 1;
            }
        }
        if(sign == 0){                                  //special case
            for(int i=0;i<digits.size();++i){
                digits[i] = 0;
            }
            digits[0] = 1;
            digits.push_back(0);
            return digits;
        }else if(sign == 1){
            int next = 1;
            for(int i=digits.size()-1;i>=0;--i){
                if(digits[i]!=9&&next==0){
                    return digits;
                }else if(digits[i]!=9&&next!=0){
                    ++digits[i];
                    return digits;
                }else if(digits[i]==9&&next==0){
                    return digits;
                }else if(digits[i]==9&&next!=0){
                    digits[i]=0;
                }
            }
        }
        
        
    }
};