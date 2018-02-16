//这个题原来是这个意思    这么操作真的好吗     算了  没背景知识   不管了 管不了
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M){
		
		if(M.size()==0||M[0].size()==0){
			return M;
		}
		
		vector<vector<int>> result;
		
        for(int i=0;i<M.size();++i){
			vector<int> temp;
			for(int j=0;j<M[0].size();++j){
				temp.push_back(sum_computing(M,i,j));
			}
			result.push_back(temp);
		}
		
		return result;
    }
	
	int sum_computing(vector<vector<int>>& M,int r,int c){
		int sum = M[r][c];
		int count = 1;
		if(r-1>=0){
			sum += M[r-1][c];
			++count;
		}
		if(r+1<M.size()){
			sum += M[r+1][c];
			++count;
		}
		if(c-1>=0){
			sum += M[r][c-1];
			++count;
		}
		if(c+1<M[0].size()){
			sum += M[r][c+1];
			++count;
		}
		if(r-1>=0&&c-1>=0){
			sum += M[r-1][c-1];
			++count;
		}
		if(r-1>=0&&c+1<M[0].size()){
			sum += M[r-1][c+1];
			++count;
		}
		if(r+1<M.size()&&c-1>=0){
			sum += M[r+1][c-1];
			++count;
		}
		if(r+1<M.size()&&c+1<M[0].size()){
			sum += M[r+1][c+1];
			++count;
		}
		
		return sum/count;
	}
};
/*
//1改变计算顺序试试,先算用点少的后算用点多的
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M){
		
		if(M.size()==0||M[0].size()==0){
			return M;
		}
		
		M[0][0] = sum_computing(M,0,0);
		M[0][M[0].size()-1] = sum_computing(M,0,M[0].size()-1);
		M[M.size()-1][0] = sum_computing(M,M.size()-1,0);
		M[M.size()-1][M[0].size()-1] = sum_computing(M,M.size()-1,M[0].size()-1);
		
		for(int i=1;i<M[0].size()-1;++i){
			M[0][i] = sum_computing(M,0,i);
			M[M.size()-1][i] = sum_computing(M,M.size()-1,i);
		}
		for(int i=1;i<M.size()-1;++i){
			M[i][0] = sum_computing(M,i,0);
			M[i][M[0].size()-1] = sum_computing(M,i,M[0].size()-1);
		}
		
		
        for(int i=1;i<M.size()-1;++i){
			for(int j=1;j<M[0].size()-1;++j){
				M[i][j] = sum_computing(M,i,j);
			}
		}
		
		return M;
    }
	
	int sum_computing(vector<vector<int>>& M,int r,int c){
		int sum = M[r][c];
		int count = 1;
		if(r-1>=0){
			sum += M[r-1][c];
			++count;
		}
		if(r+1<M.size()){
			sum += M[r+1][c];
			++count;
		}
		if(c-1>=0){
			sum += M[r][c-1];
			++count;
		}
		if(c+1<M[0].size()){
			sum += M[r][c+1];
			++count;
		}
		if(r-1>=0&&c-1>=0){
			sum += M[r-1][c-1];
			++count;
		}
		if(r-1>=0&&c+1<M[0].size()){
			sum += M[r-1][c+1];
			++count;
		}
		if(r+1<M.size()&&c-1>=0){
			sum += M[r+1][c-1];
			++count;
		}
		if(r+1<M.size()&&c+1<M[0].size()){
			sum += M[r+1][c+1];
			++count;
		}
		
		return sum/count;
	}
};
*/