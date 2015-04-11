#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	int minDistance(string word1, string word2){
		vector<vector<int> > dp(word2.size() + 1);
		for(int i = 0; i <= word2.size(); i++){
			dp[i].resize(word1.size() + 1, 0);
		}
		for(int i = 1; i <= word1.size(); i++)
			dp[0][i] = i;
		for(int i = 1; i <= word2.size(); i++)
			dp[i][0] = i;
		for(int i = 1; i <= word2.size(); i++){
			for(int j = 1; j <= word1.size(); j++){
				if(word2[i - 1] == word1[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
		}
		return dp[word2.size()][word1.size()];
	}
};

int main(){
	Solution s;
	cout << s.minDistance("plasma", "altruism") << endl;
	return 0;
}