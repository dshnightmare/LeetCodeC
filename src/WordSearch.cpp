#include <vector>
using namespace std;

class Solution{
public:
	bool exist(vector<vector<char> > &board, string word){
		vector<vector<bool> > vis(board.size());
		for(int i = 0; i < vis.size(); i++)
			vis[i].resize(board[0].size(), false);
		
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				if(word[0] == board[i][j])
					if(search(i, j, 0, word, board, vis))
						return true;
			}
		}
		return false;
	}
	
	bool search(int x, int y, int pos, string &word, vector<vector<char> > &board, vector<vector<bool> > &vis){
		if(board[x][y] != word[pos])
			return false;
		if(pos == word.size() - 1)
			return true;
		vis[x][y] = true;
		bool flag  = false;
		//up
		if(y - 1 >= 0 && !vis[x][y - 1]){
			flag = search(x, y - 1, pos + 1, word, board, vis);
			if(flag){
				vis[x][y] = false;
				return flag;
			}
		}
		//down
		if(y + 1 < board[0].size() && !vis[x][y + 1]){
			flag = search(x, y + 1, pos + 1, word, board, vis);
			if(flag){
				vis[x][y] = false;
				return flag;
			}
		}
		//left
		if(x - 1 >= 0 && !vis[x - 1][y]){
			flag = search(x - 1, y, pos + 1, word, board, vis);
			if(flag){
				vis[x][y] = false;
				return flag;
			}
		}
		//right
		if(x + 1 < board.size() && !vis[x + 1][y]){
			flag = search(x + 1, y, pos + 1, word, board, vis);
			if(flag){
				vis[x][y] = false;
				return flag;
			}
		}
		vis[x][y] = false;
		return flag;
	}
};

int main(){
	return 0;
}