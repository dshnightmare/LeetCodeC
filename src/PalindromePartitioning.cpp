#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<string>> partition(string s){
		int length = s.length();
		vector<vector<bool>> pal(length, vector<bool>(length, false));
		for(int i = length - 1; i >= 0; i--){
			for(int j = i; j < length; j++){
				if(s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
					pal[i][j] = true;
			}
		}
		vector<vector<string>> ret;
		vector<string> cur;
		dfs(s, pal, 0, cur, ret);
		return ret;
	}
	
	void dfs(string &s, vector<vector<bool>> &pal, int begin, vector<string> &cur, vector<vector<string>> &result){
		int length = s.length();
		if(begin == length){
			result.push_back(cur);
			return;
		}
		for(int i = begin; i < length; i++){
			if(pal[begin][i]){
				cur.push_back(s.substr(begin, i - begin + 1));
				dfs(s, pal, i + 1, cur, result);
				cur.pop_back();
			}
		}
	}
};