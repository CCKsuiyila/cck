//这个题第一次看到做隔了一周
//自己那个想法虽然可行,但是不知为啥总是不想去实现  
//最后还是参考了别人发现的规律
//行列的字母互换就得出了相反方向旋转的结果


//3 MS    63.84%
//这是顺时针
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
		if(length<2){
			return;
		}
		for(int i = 0; i < length/2; ++i){      //列       
			for(int j = i; j<length-i-1;++j){   //行   
				int temp = matrix[j][i];
				matrix[j][i] = matrix[length-i-1][j];
				matrix[length-i-1][j] = matrix[length-j-1][length-i-1];
				matrix[length-j-1][length-i-1] = matrix[i][length-j-1];
				matrix[i][length-j-1] = temp;
			}
		}
    }
};




/*
//这是逆时针旋转90°
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
		if(length<2){
			return;
		}
		for(int i = 0; i < length/2; ++i){     //行
			for(int j = i; j<length-i-1;++j){  //列
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][length-i-1];
				matrix[j][length-i-1] = matrix[length-i-1][length-j-1];
				matrix[length-i-1][length-j-1] = matrix[length-j-1][i];
				matrix[length-j-1][i] = temp;
			}
		}
    }
};
*/