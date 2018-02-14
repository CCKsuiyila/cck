class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
		int one = 0;
		int two = 0;
		while(one<m&&two<n){
			if(nums1[one]<nums2[two]){
				temp.push_back(nums1[one]);
				++one;
			}else{
				temp.push_back(nums2[two]);
				++two;
			}
		}
		
		if(one<m){
			while(one<m){
				temp.push_back(nums1[one]);
				++one;
			}
		}else if(two<n){
			while(two<n){
				temp.push_back(nums2[two]);
				++two;
			}
		}
		
		for(int i=0;i<m+n;++i){
			nums1[i] = temp[i];
		}
	}
};