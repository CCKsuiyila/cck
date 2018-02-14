class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int a = 0;
		int b = 0;
		while(a<matrix.size()&&b<matrix[0].size()){
			int i = a;
			int j = b;
			++a;
			while(i+1<matrix.size()&&j+1<matrix[0].size()){
				if(matrix[i][j]==matrix[i+1][j+1]){
					++i;
					++j;
				}else{
					return false;
				}
			}
		}
		a = 0;
		b = 0;
		while(a<matrix.size()&&b<matrix[0].size()){
			int i = a;
			int j = b;
			++b;
			while(i+1<matrix.size()&&j+1<matrix[0].size()){
				if(matrix[i][j]==matrix[i+1][j+1]){
					++i;
					++j;
				}else{
					return false;
				}
			}
		}
		return true;
    }
};