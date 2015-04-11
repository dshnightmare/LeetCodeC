#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	vector<string> letterCombinations(string digits){
		vector<string> result;
		if(digits == "")
			return result;
		string mapping[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		dfs(digits, 0, "", result, mapping);
		return result;
	}
	
	void dfs(string digits, int index, string cur, vector<string> &result, string mapping[]){
		int length = digits.size();
		if(index == length){
			result.push_back(cur);
			return;
		}
		int count = mapping[digits[index] - '0'].size();
		for(int i = 0; i < count; i++){
			dfs(digits, index + 1, cur + mapping[digits[index] - '0'][i], result, mapping);
		}
	}
};

int main(){
	
}