#include <string>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution{
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		if(wordDict.size() == 0)
			return vector<string>();
		int minl = INT_MAX, maxl = 0;
		bool check[256] = {false};
		for(auto i : wordDict){
			int cur = i.length();
			minl = min(minl, cur);
			maxl = max(maxl, cur);
			for(auto j : i)
				check[j] = true;
				
		}
		for(auto i : s){
			if(check[i] == false)
				return vector<string>();
		}
		vector<vector<string>> dp(maxl, vector<string>(1, ""));
		int it = 0;
		for(int i = s.length() - 1; i >= 0; i--){
			vector<string> here;
			for(int j = minl; j <= maxl && i + j <= s.length(); j++){
				string cur = s.substr(i, j);
				cout << i << " " << cur << endl;
				if(wordDict.find(cur) != wordDict.end()){
					for(auto k : dp[(it + j - 1 + maxl) % maxl])
						here.push_back(k == "" ? cur : cur + " " + k);
				}
			}
			dp[(it - 1 + maxl) % maxl] = here;
			it = (it - 1 + maxl) % maxl;
		}
		return dp[it];
	}
};

int main(){
	unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	Solution s;
	vector<string> result = s.wordBreak("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", dict);
	for(auto i : result)
		cout << i << " ";
	cout << endl;
}