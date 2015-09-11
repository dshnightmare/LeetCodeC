#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length() < t.length())
			return 0;
		vector<vector<int>> dp(t.length() + 1, vector<int>(s.length() + 1, 0));
		for(int j = 0; j <= s.length(); j++)
			dp[0][j] = 1;
		for(int i = 1; i <= t.length(); i++){
			for(int j = i; j <= s.length(); j++){
				dp[i][j] = dp[i][j - 1];
				if(t[i - 1] == s[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[t.length()][s.length()];	
    }
};

int main(){
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit") << endl;
}