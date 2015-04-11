#include <string>
using namespace std;

class Solution{
public:
	bool isScramble(string s1, string s2){
		const int N = s1.size();
		if(s1 == s2)
			return true;
		bool dp[N + 1][N][N];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++)
				dp[1][i][j] = s1[i] == s2[j];
		}
		
		for(int l = 2; l <= N; l++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					dp[l][i][j] = false;
					for(int k = 1; k < l; k++){
						//cout << dp[k][i][j] << dp[l - k][i + k][j + k] << dp[k][i][j + l - k] << dp[l-k][i + k][j] << endl;
						dp[l][i][j] = (dp[k][i][j] && dp[l - k][i + k][j + k]) || (dp[k][i][j + l - k] && dp[l-k][i + k][j]);
						if(dp[l][i][j])
							break;
					}
				}
			}
		}
		return dp[N][0][0];
	}
};

int main(){
	Solution s;
	cout << s.isScramble("rgtae", "great") << endl;
}