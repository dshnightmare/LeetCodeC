#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
		vector<vector<bool>> col(size, vector<bool>(size, false));
		vector<vector<bool>> row(size, vector<bool>(size, false));
		vector<vector<bool>> grid(size, vector<bool>(size, false));
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(board[i][j] == '.')
					continue;
				int num = board[i][j] - '1';
				if(row[i][num] || col[j][num] || grid[i / 3 * 3 + j / 3][num])
					return false;
				row[i][num] = true;
				col[j][num] = true;
				grid[i / 3 * 3 + j / 3][num] = true;
			}
		}
		return true;
    }
};