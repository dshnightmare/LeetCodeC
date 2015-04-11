#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs){
		int size = strs.size();
		if(size == 0)
			return "";
		string prefix = strs[0];
		for(int i = 1; i < size; i++){
			int j = min(prefix.size(), strs[i].size());
			for(; j > 0; j--){
				if(prefix.substr(0, j) == strs[i].substr(0, j))
					break;
			}
			if(j == 0)
				return "";
			else
				prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};

int main(){
	return 0;
}