#include <string>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution{
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		if(wordDict.size() == 0)
			return false;
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
				return false;
		}
		vector<bool> dp(s.length() + 1, false);
		dp[s.length()] = true;
		for(int i = s.length() - 1; i >= 0; i--){
			for(int j = minl; j <= maxl && i + j <= s.length(); j++){
				string cur = s.substr(i, j);
				if(wordDict.find(cur) != wordDict.end() && dp[i + j]){
					dp[i] = true;
					break;
				}
			}
		}
		return dp[0];
	}
};