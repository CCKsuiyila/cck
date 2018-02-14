class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size()-1;++i){
			if(bits[i]==0){
				continue;
			}else{
				if(i+1<bits.size()-1){
					++i;
					continue;
				}else{
					return false;
				}
			}
		}
		return true;
    }
};