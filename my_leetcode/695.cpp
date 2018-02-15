//好久没写递归了   竟然几乎一遍过     高兴
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		
		int result = 0;
        for(int i=0;i<grid.size();++i){
			for(int j=0;j<grid[0].size();++j){
				if(grid[i][j]==1){
					int temp = 1;
                    grid[i][j]=2;
					process(i,j,grid,&temp);
					if(temp>result){
						result = temp;
					}
				}
			}
		}
		return result;
    }
	
	void process(int r,int c,vector<vector<int>>& grid,int* temp){
		
		if(r-1>=0&&grid[r-1][c]==1){
			++(*temp);
			grid[r-1][c] = 2;
			process(r-1,c,grid,temp);
		}
		if(r+1<grid.size()&&grid[r+1][c]==1){
			++(*temp);
			grid[r+1][c] = 2;
			process(r+1,c,grid,temp);
		}
		if(c-1>=0&&grid[r][c-1]==1){
			++(*temp);
			grid[r][c-1] = 2;
			process(r,c-1,grid,temp);
		}
		if(c+1<grid[0].size()&&grid[r][c+1]==1){
			++(*temp);
			grid[r][c+1] = 2;
			process(r,c+1,grid,temp);
		}
	}
};