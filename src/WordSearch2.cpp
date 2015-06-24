#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
	TrieNode() : flag(false){
		for(int i = 0; i < 26; i++)
			next[i] = nullptr;
	}
	TrieNode *next[26];
	bool flag;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		build(words);
        vector<string> result;
		vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				search(i, j, board, root, result, "", check);
			}
		}
		return result;
    }
private:
	void build(vector<string> &words){
		root = new TrieNode();
		root->flag = true;
		for(auto i : words)
			addWord(i);
	}
	
    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode *cur = root;
		for(int i = 0; i < word.length(); i++){
			if(cur->next[word[i] - 'a'] == nullptr)
				cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
		}
		cur->flag = true;
    }
	
	void search(int i, int j, vector<vector<char>>& board, TrieNode *start, vector<string>& result, string cur, vector<vector<bool>>& check){
		if(start->next[board[i][j] - 'a'] == nullptr)
			return;
		check[i][j] = true;
		cur += board[i][j];
		if(start->next[board[i][j] - 'a']->flag){
			cout << "find: " + cur << endl;
			result.push_back(cur);
			start->next[board[i][j] - 'a']->flag = false;
		}
		if(i > 0 && !check[i - 1][j])
			search(i - 1, j, board, start->next[board[i][j] - 'a'], result, cur, check);
		if(i < board.size() - 1 && !check[i + 1][j])
			search(i + 1, j, board, start->next[board[i][j] - 'a'], result, cur, check);
		if(j > 0 && !check[i][j - 1])
			search(i, j - 1, board, start->next[board[i][j] - 'a'], result, cur, check);
		if(j < board[0].size() - 1 && !check[i][j + 1])
			search(i, j + 1, board, start->next[board[i][j] - 'a'], result, cur, check);
		check[i][j] = false;
	}
	
	TrieNode *root;
};

int main(){
	Solution s;
	vector<vector<char>> board;
	board.push_back(vector<char>(1, 'a'));
	vector<string> words = {"a"};
	cout << s.findWords(board, words).size() << endl;
}