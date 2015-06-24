#include <vector>
using namespace std;

class Solution{
public:
	int numIslands(vector<vector<char> > &grid) {
		int num = 0;
		for(int i = 0; i < grid.size(); i++){
			for(int j = 0; j < grid[i].size(); j++){
				if(grid[i][j] == '1'){
					num++;
					fill(grid, i, j);
				}
			}
		}
		return num;
	}
	
	void fill(vector<vector<char> > &grid, int i, int j){
		if(grid[i][j] == '0')
			return;
		grid[i][j] = '0';
		if(i - 1 >= 0)
			fill(grid, i - 1, j);
		if(i + 1 < grid.size())
			fill(grid, i + 1, j);
		if(j - 1 >= 0)
			fill(grid, i, j - 1);
		if(j + 1 < grid[i].size())
			fill(grid, i, j + 1);
	}
};